// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_pkg:msg/RobotFeedback.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__TRAITS_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_pkg/msg/detail/robot_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'l_big'
// Member 'l_small'
// Member 'r_big'
// Member 'r_small'
// Member 'l_wheel'
// Member 'r_wheel'
#include "my_robot_pkg/msg/detail/motor_feedback__traits.hpp"
// Member 'imu'
#include "my_robot_pkg/msg/detail/imu__traits.hpp"

namespace my_robot_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: l_big
  {
    out << "l_big: ";
    to_flow_style_yaml(msg.l_big, out);
    out << ", ";
  }

  // member: l_small
  {
    out << "l_small: ";
    to_flow_style_yaml(msg.l_small, out);
    out << ", ";
  }

  // member: r_big
  {
    out << "r_big: ";
    to_flow_style_yaml(msg.r_big, out);
    out << ", ";
  }

  // member: r_small
  {
    out << "r_small: ";
    to_flow_style_yaml(msg.r_small, out);
    out << ", ";
  }

  // member: l_wheel
  {
    out << "l_wheel: ";
    to_flow_style_yaml(msg.l_wheel, out);
    out << ", ";
  }

  // member: r_wheel
  {
    out << "r_wheel: ";
    to_flow_style_yaml(msg.r_wheel, out);
    out << ", ";
  }

  // member: imu
  {
    out << "imu: ";
    to_flow_style_yaml(msg.imu, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: l_big
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_big:\n";
    to_block_style_yaml(msg.l_big, out, indentation + 2);
  }

  // member: l_small
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_small:\n";
    to_block_style_yaml(msg.l_small, out, indentation + 2);
  }

  // member: r_big
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_big:\n";
    to_block_style_yaml(msg.r_big, out, indentation + 2);
  }

  // member: r_small
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_small:\n";
    to_block_style_yaml(msg.r_small, out, indentation + 2);
  }

  // member: l_wheel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_wheel:\n";
    to_block_style_yaml(msg.l_wheel, out, indentation + 2);
  }

  // member: r_wheel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_wheel:\n";
    to_block_style_yaml(msg.r_wheel, out, indentation + 2);
  }

  // member: imu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imu:\n";
    to_block_style_yaml(msg.imu, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotFeedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_robot_pkg

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_pkg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_pkg::msg::RobotFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_pkg::msg::RobotFeedback & msg)
{
  return my_robot_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_pkg::msg::RobotFeedback>()
{
  return "my_robot_pkg::msg::RobotFeedback";
}

template<>
inline const char * name<my_robot_pkg::msg::RobotFeedback>()
{
  return "my_robot_pkg/msg/RobotFeedback";
}

template<>
struct has_fixed_size<my_robot_pkg::msg::RobotFeedback>
  : std::integral_constant<bool, has_fixed_size<my_robot_pkg::msg::Imu>::value && has_fixed_size<my_robot_pkg::msg::MotorFeedback>::value> {};

template<>
struct has_bounded_size<my_robot_pkg::msg::RobotFeedback>
  : std::integral_constant<bool, has_bounded_size<my_robot_pkg::msg::Imu>::value && has_bounded_size<my_robot_pkg::msg::MotorFeedback>::value> {};

template<>
struct is_message<my_robot_pkg::msg::RobotFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__TRAITS_HPP_
