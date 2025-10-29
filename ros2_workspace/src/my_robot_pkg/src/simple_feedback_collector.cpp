#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"  // 根据 Gazebo 发布的消息类型进行导入
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/string.hpp"  // 用于发送日志或状态信息
#include <sstream>  // 添加字符串流头文件
#include "../include/my_robot_pkg/simple_feedback_collector.hpp"
#include "my_robot_pkg/msg/imu.hpp"  // 正确的自定义消息包含
#include "my_robot_pkg/msg/robot_feedback.hpp"  // 正确的自定义消息包含
#include "my_robot_pkg/msg/motor_feedback.hpp"  // 正确的自定义消息包含


class FeedbackReceiver : public rclcpp::Node
{
public:

    Received_Pkg received_pkg;


    FeedbackReceiver() : Node("feedback_receiver")
    {
        // 订阅 Gazebo 发布的模型状态消息
        subscription_1 = this->create_subscription<sensor_msgs::msg::JointState>(
            "/joint_states", 10,
            std::bind(&FeedbackReceiver::model_state_callback, this, std::placeholders::_1));

        subscription_2 = this->create_subscription<sensor_msgs::msg::Imu>(
            "/imu/data", 10,
            std::bind(&FeedbackReceiver::imu_callback, this, std::placeholders::_1));

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(10),
            std::bind(&FeedbackReceiver::timer_callback, this));

        // 发布机器人反馈消息
        publisher_ = this->create_publisher<my_robot_pkg::msg::RobotFeedback>("/robot_feedback", 10);
    }

private:
    void model_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        // 处理接收到的关节状态消息
        // 填充 MOTOR 结构体

        for (size_t i = 0; i < msg->name.size(); ++i) {
            if (msg->name[i] == "Lbig_joint") {
                this->received_pkg.LBig.pos_fdb = msg->position[i];
                this->received_pkg.LBig.sbd_fdb = msg->velocity[i];
                this->received_pkg.LBig.tor_fdb = msg->effort[i];
            }
            else if (msg->name[i] == "Lsmall_joint") {
                this->received_pkg.LSmall.pos_fdb = msg->position[i];
                this->received_pkg.LSmall.sbd_fdb = msg->velocity[i];
                this->received_pkg.LSmall.tor_fdb = msg->effort[i];
            }
            else if (msg->name[i] == "Lwheel_joint") {
                this->received_pkg.LWheel.pos_fdb = msg->position[i];
                this->received_pkg.LWheel.sbd_fdb = msg->velocity[i];
                this->received_pkg.LWheel.tor_fdb = msg->effort[i];
            }
            else if (msg->name[i] == "Rbig_joint") {
                this->received_pkg.RBig.pos_fdb = msg->position[i];
                this->received_pkg.RBig.sbd_fdb = msg->velocity[i];
                this->received_pkg.RBig.tor_fdb = msg->effort[i];
            }
            else if (msg->name[i] == "Rsmall_joint") {
                this->received_pkg.RSmall.pos_fdb = msg->position[i];
                this->received_pkg.RSmall.sbd_fdb = msg->velocity[i];
                this->received_pkg.RSmall.tor_fdb = msg->effort[i];
            }
            else if (msg->name[i] == "Rwheel_joint") {
                this->received_pkg.RWheel.pos_fdb = msg->position[i];
                this->received_pkg.RWheel.sbd_fdb = msg->velocity[i];
                this->received_pkg.RWheel.tor_fdb = msg->effort[i];
            }
        }
    }

    void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
        // 处理接收到的 IMU 消息

        this->received_pkg.imu.acc_x = msg->linear_acceleration.x;
        this->received_pkg.imu.acc_y = msg->linear_acceleration.y;
        this->received_pkg.imu.acc_z = msg->linear_acceleration.z;

        this->received_pkg.imu.gyro_x = msg->angular_velocity.x;
        this->received_pkg.imu.gyro_y = msg->angular_velocity.y;
        this->received_pkg.imu.gyro_z = msg->angular_velocity.z;
    }

    void timer_callback()
    {
        // 定期发布日志或状态信息
        auto message = my_robot_pkg::msg::RobotFeedback();


        // 填充 MotorFeedback 数据
        message.l_big.pos_fdb = this->received_pkg.LBig.pos_fdb;
        message.l_big.sbd_fdb = this->received_pkg.LBig.sbd_fdb;
        message.l_big.tor_fdb = this->received_pkg.LBig.tor_fdb;

        message.l_small.pos_fdb = this->received_pkg.LSmall.pos_fdb;
        message.l_small.sbd_fdb = this->received_pkg.LSmall.sbd_fdb;
        message.l_small.tor_fdb = this->received_pkg.LSmall.tor_fdb;

        message.l_wheel.pos_fdb = this->received_pkg.LWheel.pos_fdb;
        message.l_wheel.sbd_fdb = this->received_pkg.LWheel.sbd_fdb;
        message.l_wheel.tor_fdb = this->received_pkg.LWheel.tor_fdb;

        message.r_big.pos_fdb = this->received_pkg.RBig.pos_fdb;
        message.r_big.sbd_fdb = this->received_pkg.RBig.sbd_fdb;
        message.r_big.tor_fdb = this->received_pkg.RBig.tor_fdb;

        message.r_small.pos_fdb = this->received_pkg.RSmall.pos_fdb;
        message.r_small.sbd_fdb = this->received_pkg.RSmall.sbd_fdb;
        message.r_small.tor_fdb = this->received_pkg.RSmall.tor_fdb;

        message.r_wheel.pos_fdb = this->received_pkg.RWheel.pos_fdb;
        message.r_wheel.sbd_fdb = this->received_pkg.RWheel.sbd_fdb;
        message.r_wheel.tor_fdb = this->received_pkg.RWheel.tor_fdb;

        // 填充 IMU 数据
        message.imu.acc_x = this->received_pkg.imu.acc_x;
        message.imu.acc_y = this->received_pkg.imu.acc_y;
        message.imu.acc_z = this->received_pkg.imu.acc_z;

        message.imu.gyro_x = this->received_pkg.imu.gyro_x;
        message.imu.gyro_y = this->received_pkg.imu.gyro_y;
        message.imu.gyro_z = this->received_pkg.imu.gyro_z;

        
        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "Published feedback_msg with joint states.");

    }


    // 订阅器和发布器
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_1;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription_2;
    rclcpp::Publisher<my_robot_pkg::msg::RobotFeedback>::SharedPtr publisher_;

    // 定时器
    rclcpp::TimerBase::SharedPtr timer_;


};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FeedbackReceiver>());
    rclcpp::shutdown();
    return 0;
}
