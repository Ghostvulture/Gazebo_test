#ifndef FEEDBACK_RECEIVER_HPP
#define FEEDBACK_RECEIVER_HPP

#include <rclcpp/rclcpp.hpp>

struct MOTOR{
    float pos_fdb;
    float sbd_fdb;
    float tor_fdb;
};

struct IMU{
    float acc_x;
    float acc_y;
    float acc_z;
    float gyro_x;
    float gyro_y;
    float gyro_z;
};

struct Received_Pkg{
    MOTOR LBig;
    MOTOR LSmall;
    MOTOR RBig;
    MOTOR RSmall;
    MOTOR LWheel;
    MOTOR RWheel;

    IMU imu;
};

// class FeedbackReceiver : public rclcpp::Node
// {
// public:
//     FeedbackReceiver();
//     ~FeedbackReceiver();

// private:
//     void model_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
//     void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg);
//     void timer_callback();
    
//     // ROS2 通信
//     rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_1;
//     rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription_2;
//     rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
//     // 定时器
//     rclcpp::TimerBase::SharedPtr timer_;
    
// };

#endif // FEEDBACK_RECEIVER_HPP
