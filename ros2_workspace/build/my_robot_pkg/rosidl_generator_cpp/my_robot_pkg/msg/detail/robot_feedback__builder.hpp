// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_pkg:msg/RobotFeedback.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__BUILDER_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_pkg/msg/detail/robot_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_pkg
{

namespace msg
{

namespace builder
{

class Init_RobotFeedback_linear_acceleration
{
public:
  explicit Init_RobotFeedback_linear_acceleration(::my_robot_pkg::msg::RobotFeedback & msg)
  : msg_(msg)
  {}
  ::my_robot_pkg::msg::RobotFeedback linear_acceleration(::my_robot_pkg::msg::RobotFeedback::_linear_acceleration_type arg)
  {
    msg_.linear_acceleration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

class Init_RobotFeedback_angular_velocity
{
public:
  explicit Init_RobotFeedback_angular_velocity(::my_robot_pkg::msg::RobotFeedback & msg)
  : msg_(msg)
  {}
  Init_RobotFeedback_linear_acceleration angular_velocity(::my_robot_pkg::msg::RobotFeedback::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return Init_RobotFeedback_linear_acceleration(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

class Init_RobotFeedback_motors
{
public:
  explicit Init_RobotFeedback_motors(::my_robot_pkg::msg::RobotFeedback & msg)
  : msg_(msg)
  {}
  Init_RobotFeedback_angular_velocity motors(::my_robot_pkg::msg::RobotFeedback::_motors_type arg)
  {
    msg_.motors = std::move(arg);
    return Init_RobotFeedback_angular_velocity(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

class Init_RobotFeedback_header
{
public:
  Init_RobotFeedback_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotFeedback_motors header(::my_robot_pkg::msg::RobotFeedback::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotFeedback_motors(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_pkg::msg::RobotFeedback>()
{
  return my_robot_pkg::msg::builder::Init_RobotFeedback_header();
}

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__BUILDER_HPP_
