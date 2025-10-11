cmake_minimum_required(VERSION 3.0.2)
project(bipedal_balance_control)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  sensor_msgs
  gazebo_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
)

## System dependencies
find_package(Boost REQUIRED COMPONENTS system)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS 
    roscpp 
    rospy 
    std_msgs 
    geometry_msgs 
    sensor_msgs 
    gazebo_msgs
    tf2
    tf2_ros
    tf2_geometry_msgs
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable for wheel PID controller
add_executable(wheel_pid_controller src/wheel_pid_controller.cpp)
target_link_libraries(wheel_pid_controller ${catkin_LIBRARIES})
add_dependencies(wheel_pid_controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable for balance controller
add_executable(balance_controller src/balance_controller.cpp)
target_link_libraries(balance_controller ${catkin_LIBRARIES})
add_dependencies(balance_controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#############
## Install ##
#############

## Mark executables for installation
install(TARGETS wheel_pid_controller balance_controller
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark other files for installation (e.g. launch and bag files, etc.)
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  PATTERN ".svn" EXCLUDE
)

install(DIRECTORY config/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/config
  PATTERN ".svn" EXCLUDE
)
