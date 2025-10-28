// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_pkg:msg/JointTorques.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__JOINT_TORQUES__STRUCT_H_
#define MY_ROBOT_PKG__MSG__DETAIL__JOINT_TORQUES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'torques'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/JointTorques in the package my_robot_pkg.
/**
  * 六个电机的力矩指令
 */
typedef struct my_robot_pkg__msg__JointTorques
{
  /// 六个电机的力矩指令 [Lwheel, Rwheel, Lbig, Lsmall, Rbig, Rsmall]
  rosidl_runtime_c__double__Sequence torques;
} my_robot_pkg__msg__JointTorques;

// Struct for a sequence of my_robot_pkg__msg__JointTorques.
typedef struct my_robot_pkg__msg__JointTorques__Sequence
{
  my_robot_pkg__msg__JointTorques * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_pkg__msg__JointTorques__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_PKG__MSG__DETAIL__JOINT_TORQUES__STRUCT_H_
