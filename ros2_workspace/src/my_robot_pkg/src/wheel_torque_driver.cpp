/*
 * Wheel Torque Driver for Bipedal Robot (ROS2 C++)
 * 
 * Advanced wheel torque controller with PID control and velocity feedback.
 * Subscribes to velocity commands and applies smooth torque control.
 * 
 * Topics:
 * - /cmd_vel (geometry_msgs/Twist): Velocity commands
 * - /gazebo/apply_link_wrench: Output torque commands
 * 
 * Parameters:
 * - wheel_radius: Radius of wheels (default: 0.05m)
 * - wheel_separation: Distance between wheels (default: 0.3m)
 * - max_torque: Maximum torque per wheel (default: 20.0 N⋅m)
 * - kp, ki, kd: PID gains
 * 
 * Author: Robot Control Team
 */

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <gazebo_msgs/srv/apply_link_wrench.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <chrono>
#include <cmath>

class PIDController {
private:
    double kp_, ki_, kd_;
    double prev_error_;
    double integral_;
    std::chrono::steady_clock::time_point last_time_;
    bool initialized_;

public:
    PIDController(double kp = 1.0, double ki = 0.0, double kd = 0.0)
        : kp_(kp), ki_(ki), kd_(kd), prev_error_(0.0), integral_(0.0), initialized_(false) {}
    
    void setGains(double kp, double ki, double kd) {
        kp_ = kp;
        ki_ = ki;
        kd_ = kd;
    }
    
    double compute(double setpoint, double measured_value) {
        auto current_time = std::chrono::steady_clock::now();
        
        if (!initialized_) {
            last_time_ = current_time;
            prev_error_ = setpoint - measured_value;
            initialized_ = true;
            return 0.0;
        }
        
        auto dt = std::chrono::duration<double>(current_time - last_time_).count();
        if (dt <= 0.0) return 0.0;
        
        double error = setpoint - measured_value;
        
        // Proportional term
        double proportional = kp_ * error;
        
        // Integral term
        integral_ += error * dt;
        double integral_term = ki_ * integral_;
        
        // Derivative term
        double derivative = kd_ * (error - prev_error_) / dt;
        
        // Output
        double output = proportional + integral_term + derivative;
        
        // Update for next iteration
        prev_error_ = error;
        last_time_ = current_time;
        
        return output;
    }
    
    void reset() {
        prev_error_ = 0.0;
        integral_ = 0.0;
        initialized_ = false;
    }
};

class WheelTorqueDriver : public rclcpp::Node
{
private:
    // Publishers and subscribers
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    rclcpp::Client<gazebo_msgs::srv::ApplyLinkWrench>::SharedPtr torque_client_;
    rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr debug_pub_;
    
    // Control timer
    rclcpp::TimerBase::SharedPtr control_timer_;
    
    // Robot parameters
    double wheel_radius_;
    double wheel_separation_;
    double max_torque_;
    double max_linear_velocity_;
    double max_angular_velocity_;
    
    // PID controllers for each wheel
    PIDController left_wheel_pid_;
    PIDController right_wheel_pid_;
    
    // Current command
    geometry_msgs::msg::Twist current_cmd_;
    
    // Target wheel velocities
    double left_wheel_velocity_target_;
    double right_wheel_velocity_target_;
    
    // Simulated wheel velocities (in real robot, these would come from encoders)
    double left_wheel_velocity_actual_;
    double right_wheel_velocity_actual_;
    
    // Velocity smoothing
    double velocity_alpha_;  // Low-pass filter coefficient
    
    // Safety
    std::chrono::steady_clock::time_point last_cmd_time_;
    double cmd_timeout_;
    
public:
    WheelTorqueDriver() : Node("wheel_torque_driver"),
        wheel_radius_(0.05),     // 5cm wheel radius
        wheel_separation_(0.3),  // 30cm between wheels
        max_torque_(20.0),       // 20 N⋅m max torque
        max_linear_velocity_(2.0),  // 2 m/s max
        max_angular_velocity_(3.0), // 3 rad/s max
        left_wheel_pid_(8.0, 2.0, 0.5),   // PID gains
        right_wheel_pid_(8.0, 2.0, 0.5),
        left_wheel_velocity_target_(0.0),
        right_wheel_velocity_target_(0.0),
        left_wheel_velocity_actual_(0.0),
        right_wheel_velocity_actual_(0.0),
        velocity_alpha_(0.9),
        cmd_timeout_(0.5)  // 500ms timeout
    {
        // Declare parameters
        this->declare_parameter("wheel_radius", wheel_radius_);
        this->declare_parameter("wheel_separation", wheel_separation_);
        this->declare_parameter("max_torque", max_torque_);
        this->declare_parameter("kp", 8.0);
        this->declare_parameter("ki", 2.0);
        this->declare_parameter("kd", 0.5);
        
        // Get parameters
        wheel_radius_ = this->get_parameter("wheel_radius").as_double();
        wheel_separation_ = this->get_parameter("wheel_separation").as_double();
        max_torque_ = this->get_parameter("max_torque").as_double();
        
        double kp = this->get_parameter("kp").as_double();
        double ki = this->get_parameter("ki").as_double();
        double kd = this->get_parameter("kd").as_double();
        
        left_wheel_pid_.setGains(kp, ki, kd);
        right_wheel_pid_.setGains(kp, ki, kd);
        
        // Initialize subscribers
        cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10,
            std::bind(&WheelTorqueDriver::cmdVelCallback, this, std::placeholders::_1));
        
        // Initialize publishers
        torque_client_ = this->create_client<gazebo_msgs::srv::ApplyLinkWrench>(
            "/world/car_world/apply_link_wrench");
        
        debug_pub_ = this->create_publisher<std_msgs::msg::Float32MultiArray>(
            "/wheel_debug", 10);
        
        // Control timer (50Hz)
        control_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(20),
            std::bind(&WheelTorqueDriver::controlLoop, this));
        
        last_cmd_time_ = std::chrono::steady_clock::now();
        
        RCLCPP_INFO(this->get_logger(), "Wheel Torque Driver started!");
        RCLCPP_INFO(this->get_logger(), "Wheel radius: %.3f m", wheel_radius_);
        RCLCPP_INFO(this->get_logger(), "Wheel separation: %.3f m", wheel_separation_);
        RCLCPP_INFO(this->get_logger(), "Max torque: %.1f N⋅m", max_torque_);
        RCLCPP_INFO(this->get_logger(), "PID gains - kp: %.1f, ki: %.1f, kd: %.1f", kp, ki, kd);
    }
    
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "=== CMD_VEL RECEIVED ===");
        RCLCPP_INFO(this->get_logger(), "Raw input: linear.x=%.3f, angular.z=%.3f", 
                   msg->linear.x, msg->angular.z);
        
        // Limit velocities
        current_cmd_.linear.x = std::max(-max_linear_velocity_, 
                                        std::min(max_linear_velocity_, msg->linear.x));
        current_cmd_.angular.z = std::max(-max_angular_velocity_, 
                                         std::min(max_angular_velocity_, msg->angular.z));
        
        RCLCPP_INFO(this->get_logger(), "After limits: linear.x=%.3f, angular.z=%.3f", 
                   current_cmd_.linear.x, current_cmd_.angular.z);
        
        // Update command timestamp
        last_cmd_time_ = std::chrono::steady_clock::now();
        
        // Convert to wheel velocities using differential drive kinematics
        convertToWheelVelocities(current_cmd_.linear.x, current_cmd_.angular.z);
        
        RCLCPP_INFO(this->get_logger(), 
                    "Target wheel velocities: LEFT=%.3f rad/s, RIGHT=%.3f rad/s", 
                    left_wheel_velocity_target_, right_wheel_velocity_target_);
    }
    
    void convertToWheelVelocities(double linear_vel, double angular_vel)
    {
        RCLCPP_INFO(this->get_logger(), "=== DIFFERENTIAL DRIVE CONVERSION ===");
        RCLCPP_INFO(this->get_logger(), "Input: linear=%.3f m/s, angular=%.3f rad/s", 
                   linear_vel, angular_vel);
        RCLCPP_INFO(this->get_logger(), "Robot params: wheel_radius=%.3f m, wheel_separation=%.3f m", 
                   wheel_radius_, wheel_separation_);
        
        // Differential drive kinematics
        // v_left = (linear - angular * wheel_separation / 2) / wheel_radius
        // v_right = (linear + angular * wheel_separation / 2) / wheel_radius
        
        double left_linear = linear_vel - angular_vel * wheel_separation_ / 2.0;
        double right_linear = linear_vel + angular_vel * wheel_separation_ / 2.0;
        
        RCLCPP_INFO(this->get_logger(), "Linear velocities: left=%.3f m/s, right=%.3f m/s", 
                   left_linear, right_linear);
        
        left_wheel_velocity_target_ = left_linear / wheel_radius_;
        right_wheel_velocity_target_ = right_linear / wheel_radius_;
        
        RCLCPP_INFO(this->get_logger(), "Final wheel velocities: left=%.3f rad/s, right=%.3f rad/s", 
                   left_wheel_velocity_target_, right_wheel_velocity_target_);
    }
    
    void controlLoop()
    {
        // Check for command timeout
        auto current_time = std::chrono::steady_clock::now();
        auto time_since_last_cmd = std::chrono::duration<double>(current_time - last_cmd_time_).count();
        
        if (time_since_last_cmd > cmd_timeout_) {
            // Timeout - stop the robot
            left_wheel_velocity_target_ = 0.0;
            right_wheel_velocity_target_ = 0.0;
            current_cmd_.linear.x = 0.0;
            current_cmd_.angular.z = 0.0;
        }
        
        // Simulate wheel velocity feedback (in real robot, get from encoders)
        updateSimulatedWheelVelocities();
        
        // Compute PID control outputs
        double left_torque = left_wheel_pid_.compute(left_wheel_velocity_target_, left_wheel_velocity_actual_);
        double right_torque = right_wheel_pid_.compute(right_wheel_velocity_target_, right_wheel_velocity_actual_);
        
        // Limit torques
        left_torque = std::max(-max_torque_, std::min(max_torque_, left_torque));
        right_torque = std::max(-max_torque_, std::min(max_torque_, right_torque));
        
        // Apply torques to wheels
        applyWheelTorque("Lwheel_Link", left_torque);
        applyWheelTorque("Rwheel_Link", right_torque);
        
        // Publish debug information
        publishDebugInfo(left_torque, right_torque);
    }
    
    void updateSimulatedWheelVelocities()
    {
        // Simple first-order dynamics simulation
        // In a real robot, you would get these from wheel encoders
        double torque_to_velocity_gain = 0.1;  // Simplified conversion
        
        // Get current torque commands (simplified)
        double left_target_accel = (left_wheel_velocity_target_ - left_wheel_velocity_actual_) * 10.0;
        double right_target_accel = (right_wheel_velocity_target_ - right_wheel_velocity_actual_) * 10.0;
        
        // Update velocities with low-pass filtering
        left_wheel_velocity_actual_ += left_target_accel * 0.02;  // dt = 20ms
        right_wheel_velocity_actual_ += right_target_accel * 0.02;
        
        // Add some damping
        left_wheel_velocity_actual_ *= 0.95;
        right_wheel_velocity_actual_ *= 0.95;
    }
    
    void applyWheelTorque(const std::string& link_name, double torque_y)
    {
        auto request = std::make_shared<gazebo_msgs::srv::ApplyLinkWrench::Request>();
        
        // Set target link
        request->link_name = "bipedal_4::" + link_name;
        
        // Create wrench (torque around Y-axis for wheel rotation)
        request->wrench.force.x = 0.0;
        request->wrench.force.y = 0.0;
        request->wrench.force.z = 0.0;
        request->wrench.torque.x = 0.0;
        request->wrench.torque.y = torque_y;
        request->wrench.torque.z = 0.0;
        
        // Reference frame (wheel center)
        request->reference_frame = "bipedal_4::" + link_name;
        request->reference_point.x = 0.0;
        request->reference_point.y = 0.0;
        request->reference_point.z = 0.0;
        
        // Duration
        request->duration.sec = 0;
        request->duration.nanosec = 50000000;  // 50ms
        
        // Debug output
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                            "Applying torque to %s: %.3f N⋅m (service ready: %s)", 
                            request->link_name.c_str(), torque_y, 
                            torque_client_->service_is_ready() ? "YES" : "NO");
        
        // Call service (async)
        if (torque_client_->service_is_ready()) {
            auto future = torque_client_->async_send_request(request);
            // Add callback to check result
            auto callback = [this, link_name, torque_y](rclcpp::Client<gazebo_msgs::srv::ApplyLinkWrench>::SharedFuture future) {
                try {
                    auto response = future.get();
                    if (response->success) {
                        RCLCPP_DEBUG(this->get_logger(), "Successfully applied torque to %s", link_name.c_str());
                    } else {
                        RCLCPP_WARN(this->get_logger(), "Failed to apply torque to %s: %s", 
                                   link_name.c_str(), response->status_message.c_str());
                    }
                } catch (const std::exception& e) {
                    RCLCPP_ERROR(this->get_logger(), "Service call exception for %s: %s", 
                                link_name.c_str(), e.what());
                }
            };
            // Note: In a real implementation, you might want to store the future
            // Here we just fire and forget for simplicity
        } else {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                                "ApplyLinkWrench service not ready!");
        }
    }
    
    void publishDebugInfo(double left_torque, double right_torque)
    {
        auto debug_msg = std_msgs::msg::Float32MultiArray();
        debug_msg.data = {
            static_cast<float>(left_wheel_velocity_target_),
            static_cast<float>(left_wheel_velocity_actual_),
            static_cast<float>(left_torque),
            static_cast<float>(right_wheel_velocity_target_),
            static_cast<float>(right_wheel_velocity_actual_),
            static_cast<float>(right_torque),
            static_cast<float>(current_cmd_.linear.x),
            static_cast<float>(current_cmd_.angular.z)
        };
        
        debug_pub_->publish(debug_msg);
        
        // Log every 2 seconds
        static int counter = 0;
        if (++counter % 50 == 0) {  // Changed from 100 to 50 for more frequent output
            RCLCPP_INFO(this->get_logger(), 
                       "=== CONTROL STATUS (every 1s) ===");
            RCLCPP_INFO(this->get_logger(), 
                       "Torques: LEFT=%.3f N⋅m, RIGHT=%.3f N⋅m", 
                       left_torque, right_torque);
            RCLCPP_INFO(this->get_logger(), 
                       "Target velocities: LEFT=%.3f rad/s, RIGHT=%.3f rad/s", 
                       left_wheel_velocity_target_, right_wheel_velocity_target_);
            RCLCPP_INFO(this->get_logger(), 
                       "Actual velocities: LEFT=%.3f rad/s, RIGHT=%.3f rad/s", 
                       left_wheel_velocity_actual_, right_wheel_velocity_actual_);
            RCLCPP_INFO(this->get_logger(), 
                       "Command: linear=%.3f m/s, angular=%.3f rad/s", 
                       current_cmd_.linear.x, current_cmd_.angular.z);
            RCLCPP_INFO(this->get_logger(), 
                       "Service ready: %s", 
                       torque_client_->service_is_ready() ? "YES" : "NO");
        }
    }
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    
    auto driver = std::make_shared<WheelTorqueDriver>();
    
    RCLCPP_INFO(driver->get_logger(), "Starting wheel torque control loop...");
    
    try {
        rclcpp::spin(driver);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(driver->get_logger(), "Error: %s", e.what());
        return 1;
    }
    
    rclcpp::shutdown();
    return 0;
}
