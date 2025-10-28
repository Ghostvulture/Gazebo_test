// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_pkg:msg/MotorFeedback.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__STRUCT_H_
#define MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MotorFeedback in the package my_robot_pkg.
/**
  * 单个电机的反馈信息
 */
typedef struct my_robot_pkg__msg__MotorFeedback
{
  /// 位置 (弧度)
  double position;
  /// 速度 (弧度/秒)
  double velocity;
  /// 力矩 (Nm)
  double torque;
} my_robot_pkg__msg__MotorFeedback;

// Struct for a sequence of my_robot_pkg__msg__MotorFeedback.
typedef struct my_robot_pkg__msg__MotorFeedback__Sequence
{
  my_robot_pkg__msg__MotorFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_pkg__msg__MotorFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__STRUCT_H_
