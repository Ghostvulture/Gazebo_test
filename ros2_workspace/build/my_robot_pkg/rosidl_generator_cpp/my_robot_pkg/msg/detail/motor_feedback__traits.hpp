// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_pkg:msg/MotorFeedback.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__TRAITS_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_pkg/msg/detail/motor_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: torque
  {
    out << "torque: ";
    rosidl_generator_traits::value_to_yaml(msg.torque, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << "\n";
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }

  // member: torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "torque: ";
    rosidl_generator_traits::value_to_yaml(msg.torque, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorFeedback & msg, bool use_flow_style = false)
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
  const my_robot_pkg::msg::MotorFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_pkg::msg::MotorFeedback & msg)
{
  return my_robot_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_pkg::msg::MotorFeedback>()
{
  return "my_robot_pkg::msg::MotorFeedback";
}

template<>
inline const char * name<my_robot_pkg::msg::MotorFeedback>()
{
  return "my_robot_pkg/msg/MotorFeedback";
}

template<>
struct has_fixed_size<my_robot_pkg::msg::MotorFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_pkg::msg::MotorFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_pkg::msg::MotorFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__TRAITS_HPP_
