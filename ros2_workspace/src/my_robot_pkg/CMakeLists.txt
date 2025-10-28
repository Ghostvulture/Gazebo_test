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
find_package(sensor_msgs REQUIRED)
find_package(gazebo_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

# Find message generation dependencies
find_package(rosidl_default_generators REQUIRED)

# Include directories
include_directories(include)

# Message files
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/MotorFeedback.msg"
  "msg/JointTorques.msg"
  "msg/RobotFeedback.msg"
  DEPENDENCIES std_msgs geometry_msgs
)

# Create executable for gazebo keyboard controller
add_executable(gazebo_keyboard_controller src/gazebo_keyboard_controller.cpp)
ament_target_dependencies(gazebo_keyboard_controller
  rclcpp
  std_msgs
)

# Create executable for talker
add_executable(talker src/talker.cpp)
ament_target_dependencies(talker
  rclcpp
  std_msgs
)

# Create executable for listener
add_executable(listener src/listener.cpp)
ament_target_dependencies(listener
  rclcpp
  std_msgs
)

# ========== SIMPLE VERSIONS (WORKING IMPLEMENTATION) ==========

# Create simple feedback collector and main in one
add_executable(simple_feedback_main src/simple_feedback_main.cpp src/simple_feedback_collector.cpp)
ament_target_dependencies(simple_feedback_main
  rclcpp
  std_msgs
  geometry_msgs
  sensor_msgs
)

# Create simple torque commander and main in one
add_executable(simple_torque_main src/simple_torque_main.cpp src/simple_torque_commander.cpp)
ament_target_dependencies(simple_torque_main
  rclcpp
  std_msgs
)

# Link custom messages to simple executables
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(simple_feedback_main "${cpp_typesupport_target}")
target_link_libraries(simple_torque_main "${cpp_typesupport_target}")

# Install executables
install(TARGETS
  gazebo_keyboard_controller
  talker
  listener
  simple_feedback_main
  simple_torque_main
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

# Export message dependencies
ament_export_dependencies(rosidl_default_runtime)

ament_package()
