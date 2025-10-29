// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_pkg:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__IMU__STRUCT_H_
#define MY_ROBOT_PKG__MSG__DETAIL__IMU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Imu in the package my_robot_pkg.
/**
  * IMU 数据
 */
typedef struct my_robot_pkg__msg__Imu
{
  /// 加速度 x 轴
  double acc_x;
  /// 加速度 y 轴
  double acc_y;
  /// 加速度 z 轴
  double acc_z;
  /// 陀螺仪 x 轴
  double gyro_x;
  /// 陀螺仪 y 轴
  double gyro_y;
  /// 陀螺仪 z 轴
  double gyro_z;
} my_robot_pkg__msg__Imu;

// Struct for a sequence of my_robot_pkg__msg__Imu.
typedef struct my_robot_pkg__msg__Imu__Sequence
{
  my_robot_pkg__msg__Imu * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_pkg__msg__Imu__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_PKG__MSG__DETAIL__IMU__STRUCT_H_
