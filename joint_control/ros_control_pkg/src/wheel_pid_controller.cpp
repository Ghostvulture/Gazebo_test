/*
 * Wheel PID Controller for Bipedal Robot Balance
 * 
 * This node implements PID control for the left and right wheels
 * to maintain balance of the bipedal robot using differential drive.
 */

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Imu.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <cmath>

class WheelPIDController
{
private:
    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;
    
    // Publishers for wheel torques
    ros::Publisher left_wheel_pub_;
    ros::Publisher right_wheel_pub_;
    
    // Subscribers
    ros::Subscriber imu_sub_;
    ros::Subscriber cmd_vel_sub_;
    
    // PID parameters for balance control
    double balance_kp_, balance_ki_, balance_kd_;
    double balance_integral_, balance_prev_error_;
    double balance_target_angle_;  // Target pitch angle (0 for upright)
    
    // PID parameters for velocity control
    double velocity_kp_, velocity_ki_, velocity_kd_;
    double velocity_integral_, velocity_prev_error_;
    
    // Control variables
    double current_pitch_;
    double current_pitch_rate_;
    double target_linear_velocity_;
    double target_angular_velocity_;
    
    // Wheel parameters
    double wheel_radius_;
    double wheel_base_;
    double max_torque_;
    
    // Control loop timing
    ros::Time last_time_;
    double dt_;
    
    // Control enable flag
    bool control_enabled_;
    
public:
    WheelPIDController() : 
        pnh_("~"),
        balance_integral_(0.0),
        balance_prev_error_(0.0),
        velocity_integral_(0.0),
        velocity_prev_error_(0.0),
        current_pitch_(0.0),
        current_pitch_rate_(0.0),
        target_linear_velocity_(0.0),
        target_angular_velocity_(0.0),
        control_enabled_(true)
    {
        initializeParameters();
        initializePublishersAndSubscribers();
        
        last_time_ = ros::Time::now();
        
        ROS_INFO("Wheel PID Controller initialized");
        printParameters();
    }
    
    void initializeParameters()
    {
        // Balance PID parameters
        pnh_.param("balance_kp", balance_kp_, 50.0);
        pnh_.param("balance_ki", balance_ki_, 2.0);
        pnh_.param("balance_kd", balance_kd_, 8.0);
        pnh_.param("balance_target_angle", balance_target_angle_, 0.0);
        
        // Velocity PID parameters  
        pnh_.param("velocity_kp", velocity_kp_, 0.5);
        pnh_.param("velocity_ki", velocity_ki_, 0.1);
        pnh_.param("velocity_kd", velocity_kd_, 0.05);
        
        // Physical parameters
        pnh_.param("wheel_radius", wheel_radius_, 0.05);  // 5cm radius
        pnh_.param("wheel_base", wheel_base_, 0.3);       // 30cm between wheels
        pnh_.param("max_torque", max_torque_, 20.0);      // Maximum torque
        
        // Control parameters
        pnh_.param("control_enabled", control_enabled_, true);
    }
    
    void initializePublishersAndSubscribers()
    {
        // Publishers for wheel joint torques
        left_wheel_pub_ = nh_.advertise<std_msgs::Float64>("/model/bipedal_4/joint/Lwheel_joint/cmd_force", 1);
        right_wheel_pub_ = nh_.advertise<std_msgs::Float64>("/model/bipedal_4/joint/Rwheel_joint/cmd_force", 1);
        
        // Subscribers
        imu_sub_ = nh_.subscribe("/imu/data", 1, &WheelPIDController::imuCallback, this);
        cmd_vel_sub_ = nh_.subscribe("/cmd_vel", 1, &WheelPIDController::cmdVelCallback, this);
    }
    
    void printParameters()
    {
        ROS_INFO("=== PID Controller Parameters ===");
        ROS_INFO("Balance PID: Kp=%.2f, Ki=%.2f, Kd=%.2f", balance_kp_, balance_ki_, balance_kd_);
        ROS_INFO("Velocity PID: Kp=%.2f, Ki=%.2f, Kd=%.2f", velocity_kp_, velocity_ki_, velocity_kd_);
        ROS_INFO("Wheel radius: %.3f m", wheel_radius_);
        ROS_INFO("Wheel base: %.3f m", wheel_base_);
        ROS_INFO("Max torque: %.1f N⋅m", max_torque_);
        ROS_INFO("Target angle: %.2f rad (%.1f deg)", balance_target_angle_, balance_target_angle_ * 180.0 / M_PI);
        ROS_INFO("================================");
    }
    
    void imuCallback(const sensor_msgs::Imu::ConstPtr& msg)
    {
        // Extract pitch angle from quaternion
        tf2::Quaternion quat(msg->orientation.x, msg->orientation.y, 
                            msg->orientation.z, msg->orientation.w);
        
        tf2::Matrix3x3 matrix(quat);
        double roll, pitch, yaw;
        matrix.getRPY(roll, pitch, yaw);
        
        current_pitch_ = pitch;
        current_pitch_rate_ = msg->angular_velocity.y;  // Pitch rate
        
        // Run control loop
        if (control_enabled_)
        {
            controlLoop();
        }
    }
    
    void cmdVelCallback(const geometry_msgs::Twist::ConstPtr& msg)
    {
        target_linear_velocity_ = msg->linear.x;
        target_angular_velocity_ = msg->angular.z;
        
        ROS_DEBUG("Received cmd_vel: linear=%.2f, angular=%.2f", 
                 target_linear_velocity_, target_angular_velocity_);
    }
    
    void controlLoop()
    {
        ros::Time current_time = ros::Time::now();
        dt_ = (current_time - last_time_).toSec();
        
        if (dt_ <= 0.0 || dt_ > 0.1)  // Ignore invalid dt
        {
            last_time_ = current_time;
            return;
        }
        
        // Balance control (primary objective)
        double balance_error = balance_target_angle_ - current_pitch_;
        balance_integral_ += balance_error * dt_;
        double balance_derivative = (balance_error - balance_prev_error_) / dt_;
        
        // Anti-windup for integral term
        if (std::abs(balance_integral_) > max_torque_ / balance_ki_)
        {
            balance_integral_ = std::copysign(max_torque_ / balance_ki_, balance_integral_);
        }
        
        double balance_output = balance_kp_ * balance_error + 
                               balance_ki_ * balance_integral_ + 
                               balance_kd_ * balance_derivative;
        
        // Velocity control (secondary objective)
        // For now, we'll use a simple proportional control for velocity
        double velocity_command = velocity_kp_ * target_linear_velocity_;
        
        // Differential drive calculation
        double left_torque = balance_output + velocity_command + 
                           (target_angular_velocity_ * wheel_base_ / 2.0);
        double right_torque = balance_output + velocity_command - 
                            (target_angular_velocity_ * wheel_base_ / 2.0);
        
        // Apply torque limits
        left_torque = std::max(-max_torque_, std::min(max_torque_, left_torque));
        right_torque = std::max(-max_torque_, std::min(max_torque_, right_torque));
        
        // Publish wheel torques
        publishWheelTorques(left_torque, right_torque);
        
        // Update for next iteration
        balance_prev_error_ = balance_error;
        last_time_ = current_time;
        
        // Debug output
        ROS_DEBUG_THROTTLE(1.0, "Pitch: %.3f rad (%.1f deg), Balance output: %.2f, L: %.2f, R: %.2f", 
                          current_pitch_, current_pitch_ * 180.0 / M_PI, 
                          balance_output, left_torque, right_torque);
    }
    
    void publishWheelTorques(double left_torque, double right_torque)
    {
        std_msgs::Float64 left_msg, right_msg;
        left_msg.data = left_torque;
        right_msg.data = right_torque;
        
        left_wheel_pub_.publish(left_msg);
        right_wheel_pub_.publish(right_msg);
    }
    
    void enableControl(bool enable)
    {
        control_enabled_ = enable;
        if (!enable)
        {
            // Stop wheels when control is disabled
            publishWheelTorques(0.0, 0.0);
            // Reset integral terms
            balance_integral_ = 0.0;
            velocity_integral_ = 0.0;
        }
        ROS_INFO("Control %s", enable ? "ENABLED" : "DISABLED");
    }
    
    // Service or topic to enable/disable control dynamically
    bool isControlEnabled() const { return control_enabled_; }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "wheel_pid_controller");
    
    try
    {
        WheelPIDController controller;
        
        ROS_INFO("Starting wheel PID controller...");
        
        // Set up dynamic reconfigure or parameter updates here if needed
        
        ros::spin();
    }
    catch (const std::exception& e)
    {
        ROS_ERROR("Exception in wheel PID controller: %s", e.what());
        return 1;
    }
    
    ROS_INFO("Wheel PID controller shutting down");
    return 0;
}
