// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_pkg:msg/RobotFeedback.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__STRUCT_H_
#define MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'motors'
#include "my_robot_pkg/msg/detail/motor_feedback__struct.h"
// Member 'angular_velocity'
// Member 'linear_acceleration'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/RobotFeedback in the package my_robot_pkg.
/**
  * 完整的反馈包
 */
typedef struct my_robot_pkg__msg__RobotFeedback
{
  std_msgs__msg__Header header;
  /// 六个电机的反馈 [Lwheel, Rwheel, Lbig, Lsmall, Rbig, Rsmall]
  my_robot_pkg__msg__MotorFeedback__Sequence motors;
  /// IMU数据
  /// 角速度 (rad/s)
  geometry_msgs__msg__Vector3 angular_velocity;
  /// 线性加速度 (m/s²)
  geometry_msgs__msg__Vector3 linear_acceleration;
} my_robot_pkg__msg__RobotFeedback;

// Struct for a sequence of my_robot_pkg__msg__RobotFeedback.
typedef struct my_robot_pkg__msg__RobotFeedback__Sequence
{
  my_robot_pkg__msg__RobotFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_pkg__msg__RobotFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__STRUCT_H_
