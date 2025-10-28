#include "my_robot_pkg/simple_feedback_collector.hpp"
#include <chrono>
#include <algorithm>

// 静态成员初始化
const std::vector<std::string> SimpleFeedbackCollector::joint_names_ = {
    "Lwheel_joint", "Rwheel_joint", "Lbig_joint", 
    "Lsmall_joint", "Rbig_joint", "Rsmall_joint"
};

SimpleFeedbackCollector::SimpleFeedbackCollector() 
    : Node("simple_feedback_collector"), joint_data_received_(false), imu_data_received_(false)
{
    // 参数: 默认使用 500 Hz（2 ms）
    this->declare_parameter("publish_rate", 500.0);
    publish_rate_ = this->get_parameter("publish_rate").as_double();

    // ROS2 发布器 (保留可靠小队列用于consumer)
    feedback_pub_ = this->create_publisher<my_robot_pkg::msg::RobotFeedback>(
        "robot_feedback", rclcpp::QoS(10));

    // 使用SensorData QoS以支持高频数据（适合传感器/仿真数据）
    auto sensor_qos = rclcpp::SensorDataQoS();

    // ROS2 订阅器 - 使用桥接话题，高频QoS
    joint_state_sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "/joint_states", sensor_qos,
        std::bind(&SimpleFeedbackCollector::joint_state_callback, this, std::placeholders::_1));

    imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
        "/imu", sensor_qos,
        std::bind(&SimpleFeedbackCollector::imu_callback, this, std::placeholders::_1));
    
    torque_sub_ = this->create_subscription<my_robot_pkg::msg::JointTorques>(
        "joint_torques", 10,
        std::bind(&SimpleFeedbackCollector::torque_callback, this, std::placeholders::_1));
    
    // 发布定时器：固定 2ms 周期（500 Hz）以匹配高频传感器处理
    auto period = std::chrono::milliseconds(2);
    publish_timer_ = this->create_wall_timer(
        period, std::bind(&SimpleFeedbackCollector::publish_feedback, this));
    
    // 初始化反馈数据
    initialize_feedback();
    
    RCLCPP_INFO(this->get_logger(), "Simple Feedback Collector initialized at %.1f Hz (2ms period)", publish_rate_);
    RCLCPP_INFO(this->get_logger(), "Subscribed to: /joint_states, /imu, joint_torques");
    RCLCPP_INFO(this->get_logger(), "Publishing to: robot_feedback");
    RCLCPP_INFO(this->get_logger(), "Joint order: [Lwheel, Rwheel, Lbig, Lsmall, Rbig, Rsmall]");
}

SimpleFeedbackCollector::~SimpleFeedbackCollector()
{
    RCLCPP_INFO(this->get_logger(), "Simple Feedback Collector shutdown");
}

void SimpleFeedbackCollector::initialize_feedback()
{
    current_feedback_.header.frame_id = "base_link";
    current_feedback_.motors.resize(6);
    
    // 初始化电机反馈
    for (size_t i = 0; i < 6; ++i) {
        current_feedback_.motors[i].position = 0.0;
        current_feedback_.motors[i].velocity = 0.0;
        current_feedback_.motors[i].torque = 0.0;
    }
    
    // 初始化IMU数据
    current_feedback_.angular_velocity.x = 0.0;
    current_feedback_.angular_velocity.y = 0.0;
    current_feedback_.angular_velocity.z = 0.0;
    current_feedback_.linear_acceleration.x = 0.0;
    current_feedback_.linear_acceleration.y = 0.0;
    current_feedback_.linear_acceleration.z = 9.81; // 默认重力
    
    // 初始化力矩指令
    current_torques_.torques.resize(6);
    std::fill(current_torques_.torques.begin(), current_torques_.torques.end(), 0.0);
}

int SimpleFeedbackCollector::find_joint_index(const std::string& joint_name)
{
    auto it = std::find(joint_names_.begin(), joint_names_.end(), joint_name);
    if (it != joint_names_.end()) {
        return std::distance(joint_names_.begin(), it);
    }
    return -1;
}

void SimpleFeedbackCollector::joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
{
    // 处理关节状态数据
    for (size_t i = 0; i < msg->name.size(); ++i) {
        int index = find_joint_index(msg->name[i]);
        if (index >= 0 && index < 6) {
            if (i < msg->position.size()) {
                current_feedback_.motors[index].position = msg->position[i];
            }
            if (i < msg->velocity.size()) {
                current_feedback_.motors[index].velocity = msg->velocity[i];
            }
            if (i < msg->effort.size()) {
                current_feedback_.motors[index].torque = msg->effort[i];
            } else {
                // 如果没有effort数据，使用当前指令
                if (index < static_cast<int>(current_torques_.torques.size())) {
                    current_feedback_.motors[index].torque = current_torques_.torques[index];
                }
            }
        }
    }
    joint_data_received_ = true;
}

void SimpleFeedbackCollector::imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
{
    current_feedback_.angular_velocity.x = msg->angular_velocity.x;
    current_feedback_.angular_velocity.y = msg->angular_velocity.y;
    current_feedback_.angular_velocity.z = msg->angular_velocity.z;
    
    current_feedback_.linear_acceleration.x = msg->linear_acceleration.x;
    current_feedback_.linear_acceleration.y = msg->linear_acceleration.y;
    current_feedback_.linear_acceleration.z = msg->linear_acceleration.z;
    
    imu_data_received_ = true;
}

void SimpleFeedbackCollector::torque_callback(const my_robot_pkg::msg::JointTorques::SharedPtr msg)
{
    if (msg->torques.size() >= 6) {
        current_torques_ = *msg;
        // 更新反馈中的力矩信息
        for (size_t i = 0; i < 6 && i < msg->torques.size(); ++i) {
            current_feedback_.motors[i].torque = msg->torques[i];
        }
    } else {
        RCLCPP_WARN(this->get_logger(), "Received torque command with wrong size: %zu", 
                    msg->torques.size());
    }
}

void SimpleFeedbackCollector::publish_feedback()
{
    // 更新时间戳
    current_feedback_.header.stamp = this->now();
    
    // 发布反馈
    feedback_pub_->publish(current_feedback_);
    
    // 调试输出
    static int count = 0;
    if (++count % 50 == 0) { // 每秒输出一次调试信息
        RCLCPP_INFO(this->get_logger(), 
            "Feedback: Joint[%s] Pos=%.3f Vel=%.3f Tor=%.3f | IMU AngVel=[%.3f,%.3f,%.3f] | Data: J=%s I=%s",
            joint_names_[0].c_str(),
            current_feedback_.motors[0].position,
            current_feedback_.motors[0].velocity, 
            current_feedback_.motors[0].torque,
            current_feedback_.angular_velocity.x,
            current_feedback_.angular_velocity.y,
            current_feedback_.angular_velocity.z,
            joint_data_received_ ? "OK" : "NO",
            imu_data_received_ ? "OK" : "NO");
    }
}
