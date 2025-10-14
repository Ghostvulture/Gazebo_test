/*
 * Gazebo Service Checker - 调试工具
 * 检查Gazebo服务状态和可用的链接名称
 */

#include <rclcpp/rclcpp.hpp>
#include <gazebo_msgs/srv/apply_link_wrench.hpp>
#include <gazebo_msgs/srv/get_entity_state.hpp>
#include <gazebo_msgs/srv/get_world_properties.hpp>

class GazeboServiceChecker : public rclcpp::Node
{
public:
    GazeboServiceChecker() : Node("gazebo_service_checker")
    {
        // Create service clients
        apply_wrench_client_ = this->create_client<gazebo_msgs::srv::ApplyLinkWrench>(
            "/gazebo/apply_link_wrench");
        get_entity_state_client_ = this->create_client<gazebo_msgs::srv::GetEntityState>(
            "/gazebo/get_entity_state");
        get_world_properties_client_ = this->create_client<gazebo_msgs::srv::GetWorldProperties>(
            "/gazebo/get_world_properties");
        
        // Start checking
        timer_ = this->create_wall_timer(
            std::chrono::seconds(2),
            std::bind(&GazeboServiceChecker::checkServices, this));
            
        RCLCPP_INFO(this->get_logger(), "Gazebo Service Checker started!");
    }

private:
    rclcpp::Client<gazebo_msgs::srv::ApplyLinkWrench>::SharedPtr apply_wrench_client_;
    rclcpp::Client<gazebo_msgs::srv::GetEntityState>::SharedPtr get_entity_state_client_;
    rclcpp::Client<gazebo_msgs::srv::GetWorldProperties>::SharedPtr get_world_properties_client_;
    rclcpp::TimerBase::SharedPtr timer_;
    
    void checkServices()
    {
        RCLCPP_INFO(this->get_logger(), "=== GAZEBO SERVICE STATUS ===");
        
        // Check ApplyLinkWrench service
        bool apply_wrench_ready = apply_wrench_client_->service_is_ready();
        RCLCPP_INFO(this->get_logger(), "ApplyLinkWrench service: %s", 
                   apply_wrench_ready ? "READY" : "NOT READY");
        
        // Check GetEntityState service  
        bool entity_state_ready = get_entity_state_client_->service_is_ready();
        RCLCPP_INFO(this->get_logger(), "GetEntityState service: %s", 
                   entity_state_ready ? "READY" : "NOT READY");
        
        // Check GetWorldProperties service
        bool world_props_ready = get_world_properties_client_->service_is_ready();
        RCLCPP_INFO(this->get_logger(), "GetWorldProperties service: %s", 
                   world_props_ready ? "READY" : "NOT READY");
        
        // Test getting entity states for our robot links
        if (entity_state_ready) {
            checkRobotLinks();
        }
        
        // Test applying a small torque
        if (apply_wrench_ready) {
            testApplyWrench();
        }
    }
    
    void checkRobotLinks()
    {
        std::vector<std::string> links_to_check = {
            "bipedal_4::base_link",
            "bipedal_4::Lwheel_Link", 
            "bipedal_4::Rwheel_Link",
            "bipedal_4::Lbig_Link",
            "bipedal_4::Rbig_Link"
        };
        
        RCLCPP_INFO(this->get_logger(), "=== CHECKING ROBOT LINKS ===");
        
        for (const auto& link_name : links_to_check) {
            auto request = std::make_shared<gazebo_msgs::srv::GetEntityState::Request>();
            request->name = link_name;
            
            auto future = get_entity_state_client_->async_send_request(request);
            
            // Wait for response (blocking for debugging)
            if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future, 
                                                  std::chrono::seconds(1)) == rclcpp::FutureReturnCode::SUCCESS) {
                auto response = future.get();
                if (response->success) {
                    RCLCPP_INFO(this->get_logger(), "✓ Found link: %s", link_name.c_str());
                    RCLCPP_INFO(this->get_logger(), "  Position: [%.3f, %.3f, %.3f]", 
                               response->state.pose.position.x,
                               response->state.pose.position.y, 
                               response->state.pose.position.z);
                } else {
                    RCLCPP_WARN(this->get_logger(), "✗ Link not found: %s", link_name.c_str());
                }
            } else {
                RCLCPP_WARN(this->get_logger(), "⚠ Timeout checking link: %s", link_name.c_str());
            }
        }
    }
    
    void testApplyWrench()
    {
        static int test_counter = 0;
        test_counter++;
        
        // Only test every 5th call to avoid spam
        if (test_counter % 5 != 0) return;
        
        RCLCPP_INFO(this->get_logger(), "=== TESTING APPLY_WRENCH ===");
        
        // Test with a small torque to left wheel
        auto request = std::make_shared<gazebo_msgs::srv::ApplyLinkWrench::Request>();
        request->link_name = "bipedal_4::Lwheel_Link";
        request->wrench.torque.y = 1.0;  // Small test torque
        request->reference_frame = "bipedal_4::Lwheel_Link";
        request->duration.sec = 0;
        request->duration.nanosec = 100000000;  // 0.1s
        
        auto future = apply_wrench_client_->async_send_request(request);
        
        // Wait for response
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future, 
                                              std::chrono::seconds(1)) == rclcpp::FutureReturnCode::SUCCESS) {
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(), "ApplyWrench test result: %s", 
                       response->success ? "SUCCESS" : "FAILED");
            if (!response->success) {
                RCLCPP_WARN(this->get_logger(), "Failure reason: %s", 
                           response->status_message.c_str());
            }
        } else {
            RCLCPP_WARN(this->get_logger(), "ApplyWrench test: TIMEOUT");
        }
    }
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto checker = std::make_shared<GazeboServiceChecker>();
    rclcpp::spin(checker);
    rclcpp::shutdown();
    return 0;
}
