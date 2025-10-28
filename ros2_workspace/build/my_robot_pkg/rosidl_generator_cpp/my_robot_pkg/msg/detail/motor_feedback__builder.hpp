// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_pkg:msg/MotorFeedback.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__BUILDER_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_pkg/msg/detail/motor_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_pkg
{

namespace msg
{

namespace builder
{

class Init_MotorFeedback_torque
{
public:
  explicit Init_MotorFeedback_torque(::my_robot_pkg::msg::MotorFeedback & msg)
  : msg_(msg)
  {}
  ::my_robot_pkg::msg::MotorFeedback torque(::my_robot_pkg::msg::MotorFeedback::_torque_type arg)
  {
    msg_.torque = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_pkg::msg::MotorFeedback msg_;
};

class Init_MotorFeedback_velocity
{
public:
  explicit Init_MotorFeedback_velocity(::my_robot_pkg::msg::MotorFeedback & msg)
  : msg_(msg)
  {}
  Init_MotorFeedback_torque velocity(::my_robot_pkg::msg::MotorFeedback::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_MotorFeedback_torque(msg_);
  }

private:
  ::my_robot_pkg::msg::MotorFeedback msg_;
};

class Init_MotorFeedback_position
{
public:
  Init_MotorFeedback_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorFeedback_velocity position(::my_robot_pkg::msg::MotorFeedback::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_MotorFeedback_velocity(msg_);
  }

private:
  ::my_robot_pkg::msg::MotorFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_pkg::msg::MotorFeedback>()
{
  return my_robot_pkg::msg::builder::Init_MotorFeedback_position();
}

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__BUILDER_HPP_
