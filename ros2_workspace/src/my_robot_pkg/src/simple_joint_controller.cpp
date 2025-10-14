/*
 * Simple Joint Velocity Controller (ROS2 C++)
 * 
 * 使用关节速度控制而不是力矩控制
 * 订阅 /cmd_vel 并直接设置关节速度
 */

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>

class SimpleJointController : public rclcpp::Node
{
private:
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr joint_vel_pub_;
    
    // Robot parameters
    double wheel_radius_;
    double wheel_separation_;
    double max_wheel_speed_;
    
    // Current command
    geometry_msgs::msg::Twist current_cmd_;

public:
    SimpleJointController() : Node("simple_joint_controller"),
        wheel_radius_(0.05),     // 5cm wheel radius
        wheel_separation_(0.3),  // 30cm between wheels
        max_wheel_speed_(20.0)   // 20 rad/s max
    {
        // Declare parameters
        this->declare_parameter("wheel_radius", wheel_radius_);
        this->declare_parameter("wheel_separation", wheel_separation_);
        this->declare_parameter("max_wheel_speed", max_wheel_speed_);
        
        // Get parameters
        wheel_radius_ = this->get_parameter("wheel_radius").as_double();
        wheel_separation_ = this->get_parameter("wheel_separation").as_double();
        max_wheel_speed_ = this->get_parameter("max_wheel_speed").as_double();
        
        // Initialize subscribers
        cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10,
            std::bind(&SimpleJointController::cmdVelCallback, this, std::placeholders::_1));
        
        // Initialize publishers - 发布到关节速度话题
        joint_vel_pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(
            "/joint_velocities", 10);
        
        RCLCPP_INFO(this->get_logger(), "Simple Joint Controller started!");
        RCLCPP_INFO(this->get_logger(), "Publishing joint velocities to /joint_velocities");
        RCLCPP_INFO(this->get_logger(), "Wheel radius: %.3f m", wheel_radius_);
        RCLCPP_INFO(this->get_logger(), "Wheel separation: %.3f m", wheel_separation_);
        RCLCPP_INFO(this->get_logger(), "Max wheel speed: %.1f rad/s", max_wheel_speed_);
    }
    
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "=== CMD_VEL RECEIVED ===");
        RCLCPP_INFO(this->get_logger(), "Input: linear.x=%.3f m/s, angular.z=%.3f rad/s", 
                   msg->linear.x, msg->angular.z);
        
        // Store command
        current_cmd_ = *msg;
        
        // Convert to wheel velocities using differential drive kinematics
        auto wheel_vels = convertToWheelVelocities(msg->linear.x, msg->angular.z);
        
        // Publish joint velocities
        publishJointVelocities(wheel_vels.first, wheel_vels.second);
    }
    
    std::pair<double, double> convertToWheelVelocities(double linear_vel, double angular_vel)
    {
        RCLCPP_INFO(this->get_logger(), "=== DIFFERENTIAL DRIVE CONVERSION ===");
        
        // Differential drive kinematics
        // v_left = (linear - angular * wheel_separation / 2) / wheel_radius
        // v_right = (linear + angular * wheel_separation / 2) / wheel_radius
        
        double left_linear = linear_vel - angular_vel * wheel_separation_ / 2.0;
        double right_linear = linear_vel + angular_vel * wheel_separation_ / 2.0;
        
        double left_wheel_vel = left_linear / wheel_radius_;
        double right_wheel_vel = right_linear / wheel_radius_;
        
        // Apply speed limits
        left_wheel_vel = std::max(-max_wheel_speed_, std::min(max_wheel_speed_, left_wheel_vel));
        right_wheel_vel = std::max(-max_wheel_speed_, std::min(max_wheel_speed_, right_wheel_vel));
        
        RCLCPP_INFO(this->get_logger(), "Wheel speeds: LEFT=%.3f rad/s, RIGHT=%.3f rad/s", 
                   left_wheel_vel, right_wheel_vel);
        
        return std::make_pair(left_wheel_vel, right_wheel_vel);
    }
    
    void publishJointVelocities(double left_vel, double right_vel)
    {
        auto msg = std_msgs::msg::Float64MultiArray();
        
        // 关节顺序：[左轮, 右轮]
        msg.data = {left_vel, right_vel};
        
        joint_vel_pub_->publish(msg);
        
        RCLCPP_INFO(this->get_logger(), "Published joint velocities: [%.3f, %.3f]", 
                   left_vel, right_vel);
    }
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    
    auto controller = std::make_shared<SimpleJointController>();
    
    RCLCPP_INFO(controller->get_logger(), "Starting simple joint velocity control...");
    
    try {
        rclcpp::spin(controller);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(controller->get_logger(), "Error: %s", e.what());
        return 1;
    }
    
    rclcpp::shutdown();
    return 0;
}
