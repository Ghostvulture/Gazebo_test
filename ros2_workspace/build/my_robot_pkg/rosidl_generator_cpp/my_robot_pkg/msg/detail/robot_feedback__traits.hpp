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
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'motors'
#include "my_robot_pkg/msg/detail/motor_feedback__traits.hpp"
// Member 'angular_velocity'
// Member 'linear_acceleration'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace my_robot_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: motors
  {
    if (msg.motors.size() == 0) {
      out << "motors: []";
    } else {
      out << "motors: [";
      size_t pending_items = msg.motors.size();
      for (auto item : msg.motors) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: angular_velocity
  {
    out << "angular_velocity: ";
    to_flow_style_yaml(msg.angular_velocity, out);
    out << ", ";
  }

  // member: linear_acceleration
  {
    out << "linear_acceleration: ";
    to_flow_style_yaml(msg.linear_acceleration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: motors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motors.size() == 0) {
      out << "motors: []\n";
    } else {
      out << "motors:\n";
      for (auto item : msg.motors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity:\n";
    to_block_style_yaml(msg.angular_velocity, out, indentation + 2);
  }

  // member: linear_acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_acceleration:\n";
    to_block_style_yaml(msg.linear_acceleration, out, indentation + 2);
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
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_pkg::msg::RobotFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_pkg::msg::RobotFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__TRAITS_HPP_
