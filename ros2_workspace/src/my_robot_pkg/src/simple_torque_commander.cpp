#include "my_robot_pkg/simple_torque_commander.hpp"

// 静态成员初始化
const std::vector<std::string> SimpleTorqueCommander::joint_names_ = {
    "Lwheel_joint", "Rwheel_joint", "Lbig_joint", 
    "Lsmall_joint", "Rbig_joint", "Rsmall_joint"
};

const std::vector<std::string> SimpleTorqueCommander::force_topics_ = {
    "/Lwheel_force", "/Rwheel_force", "/Lbig_force",
    "/Lsmall_force", "/Rbig_force", "/Rsmall_force"
};

SimpleTorqueCommander::SimpleTorqueCommander() : Node("simple_torque_commander")
{
    // ROS2 订阅器
    torque_sub_ = this->create_subscription<my_robot_pkg::msg::JointTorques>(
        "joint_torques", 10,
        std::bind(&SimpleTorqueCommander::torque_command_callback, this, std::placeholders::_1));
    
    // 初始化 ROS2 发布器
    force_publishers_.resize(6);
    for (size_t i = 0; i < 6; ++i) {
        force_publishers_[i] = this->create_publisher<std_msgs::msg::Float64>(
            force_topics_[i], 10);
        RCLCPP_INFO(this->get_logger(), "Publishing to: %s", force_topics_[i].c_str());
    }
    
    RCLCPP_INFO(this->get_logger(), "Simple Torque Commander initialized");
    RCLCPP_INFO(this->get_logger(), "Listening on: joint_torques");
    RCLCPP_INFO(this->get_logger(), "Joint order: [Lwheel, Rwheel, Lbig, Lsmall, Rbig, Rsmall]");
}

SimpleTorqueCommander::~SimpleTorqueCommander()
{
    // 停止时发送零力矩
    std_msgs::msg::Float64 zero_msg;
    zero_msg.data = 0.0;
    
    for (size_t i = 0; i < force_publishers_.size(); ++i) {
        if (force_publishers_[i]) {
            force_publishers_[i]->publish(zero_msg);
        }
    }
    
    RCLCPP_INFO(this->get_logger(), "Simple Torque Commander shutdown - all joints set to zero torque");
}

void SimpleTorqueCommander::torque_command_callback(const my_robot_pkg::msg::JointTorques::SharedPtr msg)
{
    if (msg->torques.size() < 6) {
        RCLCPP_WARN(this->get_logger(), "Received torque command with wrong size: %zu (expected 6)", 
                    msg->torques.size());
        return;
    }
    
    // 发送力矩到各个关节
    for (size_t i = 0; i < 6 && i < msg->torques.size(); ++i) {
        send_torque_to_joint(i, msg->torques[i]);
    }
    
    // 调试输出
    static int count = 0;
    if (++count % 25 == 0) { // 适当频率的调试输出
        RCLCPP_INFO(this->get_logger(), 
            "Torques: L/R wheel=[%.2f,%.2f] L/R big=[%.2f,%.2f] L/R small=[%.2f,%.2f]",
            msg->torques[0], msg->torques[1], msg->torques[2], 
            msg->torques[3], msg->torques[4], msg->torques[5]);
    }
}

void SimpleTorqueCommander::send_torque_to_joint(int joint_index, double torque)
{
    if (joint_index < 0 || joint_index >= static_cast<int>(force_publishers_.size())) {
        RCLCPP_ERROR(this->get_logger(), "Invalid joint index: %d", joint_index);
        return;
    }
    
    if (!force_publishers_[joint_index]) {
        RCLCPP_ERROR(this->get_logger(), "Publisher not initialized for joint %d (%s)", 
                     joint_index, joint_names_[joint_index].c_str());
        return;
    }
    
    std_msgs::msg::Float64 force_msg;
    force_msg.data = torque;
    
    force_publishers_[joint_index]->publish(force_msg);
}
