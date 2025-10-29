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
// Member 'l_big'
// Member 'l_small'
// Member 'r_big'
// Member 'r_small'
// Member 'l_wheel'
// Member 'r_wheel'
#include "my_robot_pkg/msg/detail/motor_feedback__struct.h"
// Member 'imu'
#include "my_robot_pkg/msg/detail/imu__struct.h"

/// Struct defined in msg/RobotFeedback in the package my_robot_pkg.
/**
  * 机器人反馈消息
 */
typedef struct my_robot_pkg__msg__RobotFeedback
{
  /// 左大腿电机
  my_robot_pkg__msg__MotorFeedback l_big;
  /// 左小腿电机
  my_robot_pkg__msg__MotorFeedback l_small;
  /// 右大腿电机
  my_robot_pkg__msg__MotorFeedback r_big;
  /// 右小腿电机
  my_robot_pkg__msg__MotorFeedback r_small;
  /// 左轮子电机
  my_robot_pkg__msg__MotorFeedback l_wheel;
  /// 右轮子电机
  my_robot_pkg__msg__MotorFeedback r_wheel;
  /// IMU 传感器数据
  my_robot_pkg__msg__Imu imu;
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
