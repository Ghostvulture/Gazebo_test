#!/usr/bin/env python3
"""
Balance Controller for Bipedal Robot

This node implements a simpler Python version of the balance controller
for easier parameter tuning and debugging.
"""

import rospy
import math
import numpy as np
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion

class BalanceController:
    def __init__(self):
        rospy.init_node('balance_controller', anonymous=True)
        
        # PID parameters for balance
        self.balance_kp = rospy.get_param('~balance_kp', 30.0)
        self.balance_ki = rospy.get_param('~balance_ki', 1.5)
        self.balance_kd = rospy.get_param('~balance_kd', 5.0)
        
        # Target angle (0 for upright)
        self.target_angle = rospy.get_param('~target_angle', 0.0)
        
        # Physical parameters
        self.wheel_base = rospy.get_param('~wheel_base', 0.33)  # Distance between wheels
        self.max_torque = rospy.get_param('~max_torque', 15.0)
        
        # Control variables
        self.current_pitch = 0.0
        self.pitch_rate = 0.0
        self.prev_error = 0.0
        self.integral = 0.0
        self.last_time = rospy.Time.now()
        
        # Command velocities
        self.target_linear_vel = 0.0
        self.target_angular_vel = 0.0
        
        # Publishers
        self.left_wheel_pub = rospy.Publisher(
            '/model/bipedal_4/joint/Lwheel_joint/cmd_force', 
            Float64, queue_size=1
        )
        self.right_wheel_pub = rospy.Publisher(
            '/model/bipedal_4/joint/Rwheel_joint/cmd_force', 
            Float64, queue_size=1
        )
        
        # Subscribers
        self.imu_sub = rospy.Subscriber('/imu/data', Imu, self.imu_callback)
        self.cmd_vel_sub = rospy.Subscriber('/cmd_vel', Twist, self.cmd_vel_callback)
        
        # Control enable flag
        self.control_enabled = True
        
        rospy.loginfo("Balance Controller initialized")
        self.print_parameters()
        
        # Main control loop
        self.control_timer = rospy.Timer(rospy.Duration(0.01), self.control_loop)  # 100Hz
        
    def print_parameters(self):
        rospy.loginfo("=== Balance Controller Parameters ===")
        rospy.loginfo(f"Balance PID: Kp={self.balance_kp:.2f}, Ki={self.balance_ki:.2f}, Kd={self.balance_kd:.2f}")
        rospy.loginfo(f"Target angle: {self.target_angle:.3f} rad ({math.degrees(self.target_angle):.1f} deg)")
        rospy.loginfo(f"Wheel base: {self.wheel_base:.3f} m")
        rospy.loginfo(f"Max torque: {self.max_torque:.1f} N⋅m")
        rospy.loginfo("=====================================")
    
    def imu_callback(self, msg):
        """Process IMU data to extract pitch angle and angular velocity"""
        # Convert quaternion to Euler angles
        orientation_q = msg.orientation
        orientation_list = [orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
        (roll, pitch, yaw) = euler_from_quaternion(orientation_list)
        
        self.current_pitch = pitch
        self.pitch_rate = msg.angular_velocity.y  # Angular velocity around Y axis (pitch rate)
        
    def cmd_vel_callback(self, msg):
        """Process velocity commands"""
        self.target_linear_vel = msg.linear.x
        self.target_angular_vel = msg.angular.z
        
        rospy.logdebug(f"Received cmd_vel: linear={self.target_linear_vel:.2f}, angular={self.target_angular_vel:.2f}")
    
    def control_loop(self, event):
        """Main control loop"""
        if not self.control_enabled:
            return
            
        current_time = rospy.Time.now()
        dt = (current_time - self.last_time).to_sec()
        
        if dt <= 0.0 or dt > 0.1:  # Skip invalid time steps
            self.last_time = current_time
            return
        
        # Balance PID controller
        error = self.target_angle - self.current_pitch
        
        # Integral term with windup protection
        self.integral += error * dt
        max_integral = self.max_torque / self.balance_ki if self.balance_ki > 0 else 0
        self.integral = np.clip(self.integral, -max_integral, max_integral)
        
        # Derivative term
        derivative = (error - self.prev_error) / dt
        
        # PID output for balance
        balance_output = (self.balance_kp * error + 
                         self.balance_ki * self.integral + 
                         self.balance_kd * derivative)
        
        # Add pitch rate damping for stability
        pitch_rate_damping = -2.0 * self.pitch_rate
        balance_output += pitch_rate_damping
        
        # Simple velocity control (feedforward)
        velocity_output = 0.8 * self.target_linear_vel  # Simple proportional control
        
        # Differential drive: convert to left and right wheel torques
        base_torque = balance_output + velocity_output
        
        # Add differential steering
        steering_torque = self.target_angular_vel * self.wheel_base * 0.5
        
        left_torque = base_torque + steering_torque
        right_torque = base_torque - steering_torque
        
        # Apply torque limits
        left_torque = np.clip(left_torque, -self.max_torque, self.max_torque)
        right_torque = np.clip(right_torque, -self.max_torque, self.max_torque)
        
        # Publish wheel torques
        self.publish_wheel_torques(left_torque, right_torque)
        
        # Update for next iteration
        self.prev_error = error
        self.last_time = current_time
        
        # Debug output (throttled)
        if rospy.get_time() % 1.0 < 0.01:  # Print every second
            pitch_deg = math.degrees(self.current_pitch)
            rospy.loginfo(f"Pitch: {pitch_deg:.1f}°, Balance: {balance_output:.2f}, L: {left_torque:.2f}, R: {right_torque:.2f}")
    
    def publish_wheel_torques(self, left_torque, right_torque):
        """Publish torque commands to wheel joints"""
        left_msg = Float64()
        right_msg = Float64()
        
        left_msg.data = left_torque
        right_msg.data = right_torque
        
        self.left_wheel_pub.publish(left_msg)
        self.right_wheel_pub.publish(right_msg)
    
    def emergency_stop(self):
        """Emergency stop - set all torques to zero"""
        self.control_enabled = False
        self.publish_wheel_torques(0.0, 0.0)
        self.integral = 0.0  # Reset integral term
        rospy.logwarn("EMERGENCY STOP - Control disabled")
    
    def enable_control(self, enable=True):
        """Enable or disable control"""
        self.control_enabled = enable
        if not enable:
            self.publish_wheel_torques(0.0, 0.0)
            self.integral = 0.0
        rospy.loginfo(f"Control {'ENABLED' if enable else 'DISABLED'}")

def main():
    try:
        controller = BalanceController()
        rospy.loginfo("Balance controller started. Use Ctrl+C to stop.")
        rospy.spin()
        
    except rospy.ROSInterruptException:
        rospy.loginfo("Balance controller interrupted")
    except Exception as e:
        rospy.logerr(f"Exception in balance controller: {str(e)}")
    finally:
        # Emergency stop on shutdown
        try:
            controller.emergency_stop()
        except:
            pass

if __name__ == '__main__':
    main()
