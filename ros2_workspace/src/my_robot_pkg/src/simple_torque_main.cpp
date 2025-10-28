#include <rclcpp/rclcpp.hpp>
#include "my_robot_pkg/simple_torque_commander.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<SimpleTorqueCommander>();
    
    RCLCPP_INFO(node->get_logger(), "Starting Simple Torque Commander...");
    
    try {
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node->get_logger(), "Exception: %s", e.what());
    }
    
    rclcpp::shutdown();
    return 0;
}
