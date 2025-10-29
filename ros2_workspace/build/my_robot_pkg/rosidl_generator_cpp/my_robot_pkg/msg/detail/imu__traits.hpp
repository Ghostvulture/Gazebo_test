// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_pkg:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__IMU__TRAITS_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__IMU__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_pkg/msg/detail/imu__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Imu & msg,
  std::ostream & out)
{
  out << "{";
  // member: acc_x
  {
    out << "acc_x: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_x, out);
    out << ", ";
  }

  // member: acc_y
  {
    out << "acc_y: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_y, out);
    out << ", ";
  }

  // member: acc_z
  {
    out << "acc_z: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_z, out);
    out << ", ";
  }

  // member: gyro_x
  {
    out << "gyro_x: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_x, out);
    out << ", ";
  }

  // member: gyro_y
  {
    out << "gyro_y: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_y, out);
    out << ", ";
  }

  // member: gyro_z
  {
    out << "gyro_z: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Imu & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: acc_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_x: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_x, out);
    out << "\n";
  }

  // member: acc_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_y: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_y, out);
    out << "\n";
  }

  // member: acc_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acc_z: ";
    rosidl_generator_traits::value_to_yaml(msg.acc_z, out);
    out << "\n";
  }

  // member: gyro_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_x: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_x, out);
    out << "\n";
  }

  // member: gyro_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_y: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_y, out);
    out << "\n";
  }

  // member: gyro_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_z: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Imu & msg, bool use_flow_style = false)
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
  const my_robot_pkg::msg::Imu & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_pkg::msg::Imu & msg)
{
  return my_robot_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_pkg::msg::Imu>()
{
  return "my_robot_pkg::msg::Imu";
}

template<>
inline const char * name<my_robot_pkg::msg::Imu>()
{
  return "my_robot_pkg/msg/Imu";
}

template<>
struct has_fixed_size<my_robot_pkg::msg::Imu>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_pkg::msg::Imu>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_pkg::msg::Imu>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_PKG__MSG__DETAIL__IMU__TRAITS_HPP_
