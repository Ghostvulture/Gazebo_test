#include <rclcpp/rclcpp.hpp>
#include "my_robot_pkg/simple_feedback_collector.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<SimpleFeedbackCollector>();
    
    RCLCPP_INFO(node->get_logger(), "Starting Simple Feedback Collector...");
    
    try {
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node->get_logger(), "Exception: %s", e.what());
    }
    
    rclcpp::shutdown();
    return 0;
}
