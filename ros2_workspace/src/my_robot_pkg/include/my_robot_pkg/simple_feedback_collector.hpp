#ifndef SIMPLE_FEEDBACK_COLLECTOR_HPP
#define SIMPLE_FEEDBACK_COLLECTOR_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <geometry_msgs/msg/vector3.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include "my_robot_pkg/msg/joint_torques.hpp"
#include "my_robot_pkg/msg/robot_feedback.hpp"

class SimpleFeedbackCollector : public rclcpp::Node
{
public:
    SimpleFeedbackCollector();
    ~SimpleFeedbackCollector();

private:
    void joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
    void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg);
    void torque_callback(const my_robot_pkg::msg::JointTorques::SharedPtr msg);
    void publish_feedback();
    void initialize_feedback();
    int find_joint_index(const std::string& joint_name);
    
    // ROS2 通信
    rclcpp::Publisher<my_robot_pkg::msg::RobotFeedback>::SharedPtr feedback_pub_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_sub_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
    rclcpp::Subscription<my_robot_pkg::msg::JointTorques>::SharedPtr torque_sub_;
    rclcpp::TimerBase::SharedPtr publish_timer_;
    
    // 反馈数据
    my_robot_pkg::msg::RobotFeedback current_feedback_;
    my_robot_pkg::msg::JointTorques current_torques_;
    
    // 控制参数
    double publish_rate_;
    bool joint_data_received_;
    bool imu_data_received_;
    
    // 关节配置
    static const std::vector<std::string> joint_names_;
};

#endif // SIMPLE_FEEDBACK_COLLECTOR_HPP
