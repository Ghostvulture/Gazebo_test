/*
 * Simple Velocity Publisher for testing wheel torque driver
 * 
 * Publishes velocity commands to /cmd_vel topic for testing the wheel torque driver.
 * Can be used as an alternative to keyboard control or for programmatic testing.
 * 
 * Author: Robot Control Team
 */

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

class SimpleVelPublisher : public rclcpp::Node
{
private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr vel_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    
    double current_time_;
    double test_duration_;

public:
    SimpleVelPublisher() : Node("simple_vel_publisher"), current_time_(0.0), test_duration_(20.0)
    {
        vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&SimpleVelPublisher::publishVelocity, this));
        
        RCLCPP_INFO(this->get_logger(), "Simple velocity publisher started!");
        RCLCPP_INFO(this->get_logger(), "Test sequence duration: %.1f seconds", test_duration_);
    }
    
    void publishVelocity()
    {
        auto msg = geometry_msgs::msg::Twist();
        
        // Test sequence: forward -> turn -> backward -> turn -> stop
        if (current_time_ < 5.0) {
            // Forward motion
            msg.linear.x = 0.5;
            msg.angular.z = 0.0;
            RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Phase 1: Forward");
        } else if (current_time_ < 8.0) {
            // Turn right
            msg.linear.x = 0.0;
            msg.angular.z = -1.0;
            RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Phase 2: Turn right");
        } else if (current_time_ < 13.0) {
            // Backward motion
            msg.linear.x = -0.3;
            msg.angular.z = 0.0;
            RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Phase 3: Backward");
        } else if (current_time_ < 16.0) {
            // Turn left
            msg.linear.x = 0.0;
            msg.angular.z = 1.5;
            RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Phase 4: Turn left");
        } else {
            // Stop
            msg.linear.x = 0.0;
            msg.angular.z = 0.0;
            RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Phase 5: Stop");
        }
        
        vel_pub_->publish(msg);
        current_time_ += 0.1;  // 100ms timer
        
        if (current_time_ > test_duration_) {
            RCLCPP_INFO(this->get_logger(), "Test sequence completed, shutting down...");
            rclcpp::shutdown();
        }
    }
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto publisher = std::make_shared<SimpleVelPublisher>();
    rclcpp::spin(publisher);
    rclcpp::shutdown();
    return 0;
}
