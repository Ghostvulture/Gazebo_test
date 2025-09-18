cmake_minimum_required(VERSION 3.10)
project(urdf_test)

find_package(ignition-gazebo6 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_library(${PROJECT_NAME} SHARED urdf_test.cpp)
target_link_libraries(${PROJECT_NAME}
  ignition-gazebo6::ignition-gazebo6
  rclcpp::rclcpp
)
ament_target_dependencies(${PROJECT_NAME} rclcpp std_msgs)
