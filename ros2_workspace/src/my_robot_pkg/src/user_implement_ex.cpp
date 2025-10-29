#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <std_msgs/msg/int32.hpp>
#include <chrono>
#include <memory>
#include "my_robot_pkg/msg/robot_feedback.hpp"  // 添加自定义消息头文件

class UserFunction : public rclcpp::Node
{
public:
    UserFunction() : Node("user_function")
    {
        // 订阅传感器信息
        sensor_sub_ = this->create_subscription<my_robot_pkg::msg::RobotFeedback>(
            "/robot_feedback", 10,
            std::bind(&UserFunction::sensor_callback, this, std::placeholders::_1));

        stop_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(1),  
            std::bind(&UserFunction::TimeTick, this));
        
        right_wheel_pub_ = this->create_publisher<std_msgs::msg::Float64>(
            "/model/bipedal_4/joint/Rwheel_joint/cmd_force", 10);
        left_wheel_pub_ = this->create_publisher<std_msgs::msg::Float64>(
            "/model/bipedal_4/joint/Lwheel_joint/cmd_force", 10);
        right_big_wheel_pub_ = this->create_publisher<std_msgs::msg::Float64>(
            "/model/bipedal_4/joint/Rbig_joint/cmd_force", 10);
        left_big_wheel_pub_ = this->create_publisher<std_msgs::msg::Float64>(
            "/model/bipedal_4/joint/Lbig_joint/cmd_force", 10);
        right_small_wheel_pub_ = this->create_publisher<std_msgs::msg::Float64>(
            "/model/bipedal_4/joint/Rsmall_joint/cmd_force", 10);
        left_small_wheel_pub_ = this->create_publisher<std_msgs::msg::Float64>(
            "/model/bipedal_4/joint/Lsmall_joint/cmd_force", 10);
    }
    
    ~UserFunction()
    {
        // 停止轮子
        RCLCPP_INFO(this->get_logger(), "Gstop thread timetick");
    }

private:
    
    void TimeTick(){
        //implement main function here


        publishForces(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    }

    void publishForces(double Lwheel_tor, double Rwheel_tor, double Lbig_tor, double Rbig_tor, double Lsmall_tor, double Rsmall_tor)
    {

        auto Rwheel_msg = std_msgs::msg::Float64();
        auto Lwheel_msg = std_msgs::msg::Float64();
        auto Rbig_msg = std_msgs::msg::Float64();
        auto Lbig_msg = std_msgs::msg::Float64();
        auto Rsmall_msg = std_msgs::msg::Float64();
        auto Lsmall_msg = std_msgs::msg::Float64();

        Rwheel_msg.data = Rwheel_tor;
        Lwheel_msg.data = Lwheel_tor;
        Rbig_msg.data = Rbig_tor;
        Lbig_msg.data = Lbig_tor;
        Rsmall_msg.data = Rsmall_tor;
        Lsmall_msg.data = Lsmall_tor;

        right_wheel_pub_->publish(Rwheel_msg);
        left_wheel_pub_->publish(Lwheel_msg);
        right_big_wheel_pub_->publish(Rbig_msg);
        left_big_wheel_pub_->publish(Lbig_msg);
        right_small_wheel_pub_->publish(Rsmall_msg);
        left_small_wheel_pub_->publish(Lsmall_msg);
    }
    


private:
    void sensor_callback(const my_robot_pkg::msg::RobotFeedback::SharedPtr msg)
    {
        // 处理接收到的传感器信息
        // 可以根据需要实现具体逻辑
        RCLCPP_INFO(this->get_logger(), "Received RobotFeedback: [%f, %f, %f, %f, %f, %f]",
            msg->l_big.pos_fdb, msg->l_big.sbd_fdb, msg->l_big.tor_fdb,
            msg->r_big.pos_fdb, msg->r_big.sbd_fdb, msg->r_big.tor_fdb);
    }

    // ROS2 组件
    rclcpp::Subscription<my_robot_pkg::msg::RobotFeedback>::SharedPtr sensor_sub_;  // 添加缺少的订阅器
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr right_wheel_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr left_wheel_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr right_big_wheel_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr left_big_wheel_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr right_small_wheel_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr left_small_wheel_pub_; 
    rclcpp::TimerBase::SharedPtr stop_timer_;
    
    // 参数和状态

    rclcpp::Time last_key_time_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<UserFunction>());
    rclcpp::shutdown();
    return 0;
}
