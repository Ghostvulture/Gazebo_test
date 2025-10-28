#ifndef SIMPLE_TORQUE_COMMANDER_HPP
#define SIMPLE_TORQUE_COMMANDER_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include "my_robot_pkg/msg/joint_torques.hpp"

class SimpleTorqueCommander : public rclcpp::Node
{
public:
    SimpleTorqueCommander();
    ~SimpleTorqueCommander();

private:
    void torque_command_callback(const my_robot_pkg::msg::JointTorques::SharedPtr msg);
    void send_torque_to_joint(int joint_index, double torque);
    
    // ROS2 订阅器
    rclcpp::Subscription<my_robot_pkg::msg::JointTorques>::SharedPtr torque_sub_;
    
    // ROS2 发布器 - 每个关节一个
    std::vector<rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr> force_publishers_;
    
    // 关节配置
    static const std::vector<std::string> joint_names_;
    static const std::vector<std::string> force_topics_;
};

#endif // SIMPLE_TORQUE_COMMANDER_HPP
