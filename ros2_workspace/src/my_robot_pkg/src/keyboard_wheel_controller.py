#!/usr/bin/env python3
"""
Keyboard Wheel Controller for Bipedal Robot (ROS2)

This script provides keyboard control for the bipedal robot's wheels using torque mode.
Uses the ApplyLinkWrench system to apply forces/torques to the wheel links.

Controls:
- W/S: Forward/Backward
- A/D: Turn Left/Right  
- Q/E: Increase/Decrease speed
- SPACE: Emergency stop
- ESC: Exit

Author: Robot Control Team
"""

import rclpy
from rclpy.node import Node
import sys
import termios
import tty
import select
from gazebo_msgs.msg import ApplyLinkWrench
from geometry_msgs.msg import Vector3, Wrench
from std_msgs.msg import String
import threading

class KeyboardWheelController(Node):
    def __init__(self):
        super().__init__('keyboard_wheel_controller')
        
        # Publishers for wheel torques using ApplyLinkWrench
        self.left_wheel_pub = self.create_publisher(
            ApplyLinkWrench, 
            '/gazebo/apply_link_wrench', 
            10
        )
        self.right_wheel_pub = self.create_publisher(
            ApplyLinkWrench, 
            '/gazebo/apply_link_wrench', 
            10
        )
        
        # Control parameters
        self.base_torque = 5.0        # Base torque magnitude
        self.max_torque = 20.0        # Maximum torque
        self.min_torque = 1.0         # Minimum torque
        self.torque_step = 1.0        # Torque adjustment step
        
        # Current motion state
        self.linear_direction = 0     # -1: backward, 0: stop, 1: forward
        self.angular_direction = 0    # -1: left, 0: straight, 1: right
        
        # Control timer
        self.control_timer = self.create_timer(0.1, self.publish_wheel_torques)  # 10Hz
        
        # Terminal settings for keyboard input
        self.old_settings = termios.tcgetattr(sys.stdin)
        
        self.get_logger().info("Keyboard Wheel Controller started!")
        self.print_instructions()
        
        # Start keyboard input thread
        self.running = True
        self.keyboard_thread = threading.Thread(target=self.keyboard_input_loop)
        self.keyboard_thread.daemon = True
        self.keyboard_thread.start()
    
    def print_instructions(self):
        """Print control instructions"""
        instructions = """
╔══════════════════════════════════════════════════╗
║            KEYBOARD WHEEL CONTROLLER             ║
╠══════════════════════════════════════════════════╣
║  W / S    : Forward / Backward                   ║
║  A / D    : Turn Left / Turn Right               ║
║  Q / E    : Decrease / Increase torque           ║
║  SPACE    : Emergency Stop                       ║
║  ESC      : Exit                                 ║
╠══════════════════════════════════════════════════╣
║  Current torque: {:.1f} N⋅m                      ║
║  Max torque: {:.1f} N⋅m                          ║
╚══════════════════════════════════════════════════╝
        """.format(self.base_torque, self.max_torque)
        print(instructions)
    
    def get_key(self):
        """Get single key press"""
        tty.setraw(sys.stdin.fileno())
        key = sys.stdin.read(1)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.old_settings)
        return key
    
    def keyboard_input_loop(self):
        """Main keyboard input loop"""
        while self.running:
            if select.select([sys.stdin], [], [], 0.1)[0]:
                key = self.get_key()
                self.process_key(key)
    
    def process_key(self, key):
        """Process keyboard input"""
        key = key.lower()
        
        if key == 'w':
            self.linear_direction = 1
            self.get_logger().info("Forward motion")
        elif key == 's':
            self.linear_direction = -1
            self.get_logger().info("Backward motion")
        elif key == 'a':
            self.angular_direction = -1
            self.get_logger().info("Turn left")
        elif key == 'd':
            self.angular_direction = 1
            self.get_logger().info("Turn right")
        elif key == 'q':
            self.base_torque = max(self.min_torque, self.base_torque - self.torque_step)
            self.get_logger().info(f"Torque decreased to: {self.base_torque:.1f} N⋅m")
        elif key == 'e':
            self.base_torque = min(self.max_torque, self.base_torque + self.torque_step)
            self.get_logger().info(f"Torque increased to: {self.base_torque:.1f} N⋅m")
        elif key == ' ':  # Space bar
            self.emergency_stop()
        elif key == '\x1b':  # ESC key
            self.get_logger().info("Exiting...")
            self.emergency_stop()
            self.running = False
            rclpy.shutdown()
        elif key in ['x', 'c']:  # Stop keys
            self.linear_direction = 0
            self.angular_direction = 0
            self.get_logger().info("Stop")
    
    def emergency_stop(self):
        """Emergency stop - immediately set all torques to zero"""
        self.linear_direction = 0
        self.angular_direction = 0
        self.get_logger().warn("EMERGENCY STOP!")
        
        # Send zero torques immediately
        self.apply_wheel_torque("Lwheel_Link", 0.0)
        self.apply_wheel_torque("Rwheel_Link", 0.0)
    
    def calculate_wheel_torques(self):
        """Calculate left and right wheel torques based on linear and angular commands"""
        # Base movement torque
        linear_torque = self.linear_direction * self.base_torque
        
        # Differential torque for turning
        turn_torque = self.angular_direction * self.base_torque * 0.5
        
        # Calculate individual wheel torques
        left_torque = linear_torque + turn_torque   # Left wheel
        right_torque = linear_torque - turn_torque  # Right wheel (opposite for differential drive)
        
        # Apply torque limits
        left_torque = max(-self.max_torque, min(self.max_torque, left_torque))
        right_torque = max(-self.max_torque, min(self.max_torque, right_torque))
        
        return left_torque, right_torque
    
    def apply_wheel_torque(self, link_name, torque_y):
        """Apply torque to a specific wheel link"""
        msg = ApplyLinkWrench()
        
        # Set target link (wheel)
        msg.link_name = f"bipedal_4::{link_name}"
        
        # Create wrench (force + torque)
        wrench = Wrench()
        wrench.force = Vector3(x=0.0, y=0.0, z=0.0)      # No linear force
        wrench.torque = Vector3(x=0.0, y=torque_y, z=0.0)  # Torque around Y-axis
        msg.wrench = wrench
        
        # Set reference frame and point
        msg.reference_frame = f"bipedal_4::{link_name}"
        msg.reference_point = Vector3(x=0.0, y=0.0, z=0.0)
        
        # Duration (0 means apply once)
        msg.duration.sec = 0
        msg.duration.nanosec = 100000000  # 0.1 seconds
        
        # Publish the message
        if "Lwheel" in link_name:
            self.left_wheel_pub.publish(msg)
        else:
            self.right_wheel_pub.publish(msg)
    
    def publish_wheel_torques(self):
        """Timer callback to publish wheel torques"""
        if self.running:
            left_torque, right_torque = self.calculate_wheel_torques()
            
            # Apply torques to wheels
            self.apply_wheel_torque("Lwheel_Link", left_torque)
            self.apply_wheel_torque("Rwheel_Link", right_torque)
            
            # Debug output (throttled)
            if abs(left_torque) > 0.1 or abs(right_torque) > 0.1:
                self.get_logger().debug(f"Torques - Left: {left_torque:.1f}, Right: {right_torque:.1f}")
    
    def __del__(self):
        """Cleanup on destruction"""
        try:
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.old_settings)
        except:
            pass

def main(args=None):
    rclpy.init(args=args)
    
    try:
        controller = KeyboardWheelController()
        
        # Keep the node spinning
        while rclpy.ok() and controller.running:
            rclpy.spin_once(controller, timeout_sec=0.1)
            
    except KeyboardInterrupt:
        print("\nKeyboard interrupt received. Stopping...")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        try:
            controller.emergency_stop()
            controller.destroy_node()
        except:
            pass
        rclpy.shutdown()

if __name__ == '__main__':
    main()
