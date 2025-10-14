/*
 * Keyboard Wheel Controller for Bipedal Robot (ROS2 C++)
 * 
 * This program provides keyboard control for the bipedal robot's wheels using torque mode.
 * Uses the ApplyLinkWrench system to apply forces/torques to the wheel links.
 * 
 * Controls:
 * - W/S: Forward/Backward
 * - A/D: Turn Left/Right  
 * - Q/E: Decrease/Increase torque
 * - SPACE: Emergency stop
 * - ESC: Exit
 * 
 * Author: Robot Control Team
 */

#include <rclcpp/rclcpp.hpp>
#include <gazebo_msgs/srv/apply_link_wrench.hpp>
#include <geometry_msgs/msg/vector3.hpp>
#include <geometry_msgs/msg/wrench.hpp>
#include <std_msgs/msg/string.hpp>

#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <iostream>
#include <thread>
#include <atomic>
#include <string>

class KeyboardWheelController : public rclcpp::Node
{
private:
    // Service clients for wheel torques
    rclcpp::Client<gazebo_msgs::srv::ApplyLinkWrench>::SharedPtr link_wrench_client_;
    
    // Control timer
    rclcpp::TimerBase::SharedPtr control_timer_;
    
    // Control parameters
    double base_torque_;
    double max_torque_;
    double min_torque_;
    double torque_step_;
    
    // Motion state
    std::atomic<int> linear_direction_;   // -1: backward, 0: stop, 1: forward
    std::atomic<int> angular_direction_;  // -1: left, 0: straight, 1: right
    
    // Threading
    std::atomic<bool> running_;
    std::thread keyboard_thread_;
    
    // Terminal settings
    struct termios old_settings_;

public:
    KeyboardWheelController() : Node("keyboard_wheel_controller"),
        base_torque_(5.0),
        max_torque_(20.0),
        min_torque_(1.0),
        torque_step_(1.0),
        linear_direction_(0),
        angular_direction_(0),
        running_(true)
    {
        // Initialize service client
        link_wrench_client_ = this->create_client<gazebo_msgs::srv::ApplyLinkWrench>(
            "/world/car_world/apply_link_wrench");
        
        // Create control timer (10Hz)
        control_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&KeyboardWheelController::publishWheelTorques, this));
        
        // Save terminal settings
        tcgetattr(STDIN_FILENO, &old_settings_);
        
        RCLCPP_INFO(this->get_logger(), "Keyboard Wheel Controller started!");
        printInstructions();
        
        // Start keyboard input thread
        keyboard_thread_ = std::thread(&KeyboardWheelController::keyboardInputLoop, this);
    }
    
    ~KeyboardWheelController()
    {
        running_ = false;
        if (keyboard_thread_.joinable()) {
            keyboard_thread_.join();
        }
        
        // Restore terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &old_settings_);
        
        // Emergency stop
        emergencyStop();
    }
    
    void printInstructions()
    {
        std::cout << "\n";
        std::cout << "╔══════════════════════════════════════════════════╗\n";
        std::cout << "║            KEYBOARD WHEEL CONTROLLER (C++)      ║\n";
        std::cout << "╠══════════════════════════════════════════════════╣\n";
        std::cout << "║  W / S    : Forward / Backward                   ║\n";
        std::cout << "║  A / D    : Turn Left / Turn Right               ║\n";
        std::cout << "║  Q / E    : Decrease / Increase torque           ║\n";
        std::cout << "║  SPACE    : Emergency Stop                       ║\n";
        std::cout << "║  X / C    : Stop motion                          ║\n";
        std::cout << "║  ESC      : Exit                                 ║\n";
        std::cout << "╠══════════════════════════════════════════════════╣\n";
        std::cout << "║  Current torque: " << base_torque_ << " N⋅m                      ║\n";
        std::cout << "║  Max torque: " << max_torque_ << " N⋅m                          ║\n";
        std::cout << "╚══════════════════════════════════════════════════╝\n";
        std::cout << std::endl;
    }
    
    char getKey()
    {
        char key = 0;
        struct termios new_settings;
        
        // Set terminal to raw mode
        new_settings = old_settings_;
        new_settings.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
        
        // Check if input is available
        fd_set readfds;
        struct timeval timeout;
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000; // 100ms timeout
        
        if (select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout) > 0) {
            if (FD_ISSET(STDIN_FILENO, &readfds)) {
                if (read(STDIN_FILENO, &key, 1) < 0) {
                    key = 0;
                }
            }
        }
        
        // Restore terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &old_settings_);
        
        return key;
    }
    
    void keyboardInputLoop()
    {
        while (running_) {
            char key = getKey();
            if (key != 0) {
                processKey(key);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
    
    void processKey(char key)
    {
        // Convert to lowercase
        key = std::tolower(key);
        
        switch (key) {
            case 'w':
                linear_direction_ = 1;
                RCLCPP_INFO(this->get_logger(), "Forward motion");
                break;
            case 's':
                linear_direction_ = -1;
                RCLCPP_INFO(this->get_logger(), "Backward motion");
                break;
            case 'a':
                angular_direction_ = -1;
                RCLCPP_INFO(this->get_logger(), "Turn left");
                break;
            case 'd':
                angular_direction_ = 1;
                RCLCPP_INFO(this->get_logger(), "Turn right");
                break;
            case 'q':
                base_torque_ = std::max(min_torque_, base_torque_ - torque_step_);
                RCLCPP_INFO(this->get_logger(), "Torque decreased to: %.1f N⋅m", base_torque_);
                break;
            case 'e':
                base_torque_ = std::min(max_torque_, base_torque_ + torque_step_);
                RCLCPP_INFO(this->get_logger(), "Torque increased to: %.1f N⋅m", base_torque_);
                break;
            case ' ':  // Space bar
                emergencyStop();
                break;
            case 27:   // ESC key
                RCLCPP_INFO(this->get_logger(), "Exiting...");
                emergencyStop();
                running_ = false;
                rclcpp::shutdown();
                break;
            case 'x':
            case 'c':
                linear_direction_ = 0;
                angular_direction_ = 0;
                RCLCPP_INFO(this->get_logger(), "Stop");
                break;
            default:
                // Ignore other keys
                break;
        }
    }
    
    void emergencyStop()
    {
        linear_direction_ = 0;
        angular_direction_ = 0;
        RCLCPP_WARN(this->get_logger(), "EMERGENCY STOP!");
        
        // Send zero torques immediately
        applyWheelTorque("Lwheel_Link", 0.0);
        applyWheelTorque("Rwheel_Link", 0.0);
    }
    
    std::pair<double, double> calculateWheelTorques()
    {
        // Base movement torque
        double linear_torque = linear_direction_.load() * base_torque_;
        
        // Differential torque for turning
        double turn_torque = angular_direction_.load() * base_torque_ * 0.5;
        
        // Calculate individual wheel torques
        double left_torque = linear_torque + turn_torque;   // Left wheel
        double right_torque = linear_torque - turn_torque;  // Right wheel (opposite for differential drive)
        
        // Apply torque limits
        left_torque = std::max(-max_torque_, std::min(max_torque_, left_torque));
        right_torque = std::max(-max_torque_, std::min(max_torque_, right_torque));
        
        return std::make_pair(left_torque, right_torque);
    }
    
    void applyWheelTorque(const std::string& link_name, double torque_y)
    {
        auto request = std::make_shared<gazebo_msgs::srv::ApplyLinkWrench::Request>();
        
        // Set target link (wheel)
        request->link_name = "bipedal_4::" + link_name;
        
        // Create wrench (force + torque)
        request->wrench.force.x = 0.0;
        request->wrench.force.y = 0.0;
        request->wrench.force.z = 0.0;
        request->wrench.torque.x = 0.0;
        request->wrench.torque.y = torque_y;  // Torque around Y-axis
        request->wrench.torque.z = 0.0;
        
        // Set reference frame and point
        request->reference_frame = "bipedal_4::" + link_name;
        request->reference_point.x = 0.0;
        request->reference_point.y = 0.0;
        request->reference_point.z = 0.0;
        
        // Duration (0 means apply once)
        request->duration.sec = 0;
        request->duration.nanosec = 100000000;  // 0.1 seconds
        
        // Debug output
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500,
                            "Keyboard: Applying %.3f N⋅m to %s (service: %s)", 
                            torque_y, request->link_name.c_str(),
                            link_wrench_client_->service_is_ready() ? "READY" : "NOT_READY");
        
        // Call service (async)
        if (link_wrench_client_->service_is_ready()) {
            link_wrench_client_->async_send_request(request);
        } else {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                                "ApplyLinkWrench service not available!");
        }
    }
    
    void publishWheelTorques()
    {
        if (running_) {
            auto [left_torque, right_torque] = calculateWheelTorques();
            
            // Apply torques to wheels
            applyWheelTorque("Lwheel_Link", left_torque);
            applyWheelTorque("Rwheel_Link", right_torque);
            
            // Debug output (throttled)
            static int counter = 0;
            if (++counter % 10 == 0 && (std::abs(left_torque) > 0.1 || std::abs(right_torque) > 0.1)) {
                RCLCPP_INFO(this->get_logger(), 
                           "Keyboard Control: LEFT=%.3f N⋅m, RIGHT=%.3f N⋅m (linear:%d, angular:%d)", 
                           left_torque, right_torque, 
                           linear_direction_.load(), angular_direction_.load());
            }
        }
    }
    
    bool isRunning() const { return running_; }
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    
    try {
        auto controller = std::make_shared<KeyboardWheelController>();
        
        // Keep the node spinning
        while (rclcpp::ok() && controller->isRunning()) {
            rclcpp::spin_some(controller);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    rclcpp::shutdown();
    return 0;
}
