cmake_minimum_required(VERSION 3.8)
project(my_robot_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(gazebo_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

# Create executable for keyboard wheel controller
add_executable(keyboard_wheel_controller src/keyboard_wheel_controller.cpp)
ament_target_dependencies(keyboard_wheel_controller
  rclcpp
  std_msgs
  geometry_msgs
  gazebo_msgs
)

# Create executable for wheel torque controller  
add_executable(wheel_torque_driver src/wheel_torque_driver.cpp)
ament_target_dependencies(wheel_torque_driver
  rclcpp
  std_msgs
  geometry_msgs
  gazebo_msgs
)

# Create executable for simple velocity publisher
add_executable(simple_vel_publisher src/simple_vel_publisher.cpp)
ament_target_dependencies(simple_vel_publisher
  rclcpp
  geometry_msgs
)

# Create executable for Gazebo service checker
add_executable(gazebo_service_checker src/gazebo_service_checker.cpp)
ament_target_dependencies(gazebo_service_checker
  rclcpp
  gazebo_msgs
)

# Create executable for simple joint controller
add_executable(simple_joint_controller src/simple_joint_controller.cpp)
ament_target_dependencies(simple_joint_controller
  rclcpp
  geometry_msgs
  std_msgs
)

# Install executables
install(TARGETS
  keyboard_wheel_controller
  wheel_torque_driver
  simple_vel_publisher
  gazebo_service_checker
  simple_joint_controller
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
