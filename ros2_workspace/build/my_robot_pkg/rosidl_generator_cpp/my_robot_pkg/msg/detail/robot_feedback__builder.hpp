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

class Init_RobotFeedback_imu
{
public:
  explicit Init_RobotFeedback_imu(::my_robot_pkg::msg::RobotFeedback & msg)
  : msg_(msg)
  {}
  ::my_robot_pkg::msg::RobotFeedback imu(::my_robot_pkg::msg::RobotFeedback::_imu_type arg)
  {
    msg_.imu = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

class Init_RobotFeedback_r_wheel
{
public:
  explicit Init_RobotFeedback_r_wheel(::my_robot_pkg::msg::RobotFeedback & msg)
  : msg_(msg)
  {}
  Init_RobotFeedback_imu r_wheel(::my_robot_pkg::msg::RobotFeedback::_r_wheel_type arg)
  {
    msg_.r_wheel = std::move(arg);
    return Init_RobotFeedback_imu(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

class Init_RobotFeedback_l_wheel
{
public:
  explicit Init_RobotFeedback_l_wheel(::my_robot_pkg::msg::RobotFeedback & msg)
  : msg_(msg)
  {}
  Init_RobotFeedback_r_wheel l_wheel(::my_robot_pkg::msg::RobotFeedback::_l_wheel_type arg)
  {
    msg_.l_wheel = std::move(arg);
    return Init_RobotFeedback_r_wheel(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

class Init_RobotFeedback_r_small
{
public:
  explicit Init_RobotFeedback_r_small(::my_robot_pkg::msg::RobotFeedback & msg)
  : msg_(msg)
  {}
  Init_RobotFeedback_l_wheel r_small(::my_robot_pkg::msg::RobotFeedback::_r_small_type arg)
  {
    msg_.r_small = std::move(arg);
    return Init_RobotFeedback_l_wheel(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

class Init_RobotFeedback_r_big
{
public:
  explicit Init_RobotFeedback_r_big(::my_robot_pkg::msg::RobotFeedback & msg)
  : msg_(msg)
  {}
  Init_RobotFeedback_r_small r_big(::my_robot_pkg::msg::RobotFeedback::_r_big_type arg)
  {
    msg_.r_big = std::move(arg);
    return Init_RobotFeedback_r_small(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

class Init_RobotFeedback_l_small
{
public:
  explicit Init_RobotFeedback_l_small(::my_robot_pkg::msg::RobotFeedback & msg)
  : msg_(msg)
  {}
  Init_RobotFeedback_r_big l_small(::my_robot_pkg::msg::RobotFeedback::_l_small_type arg)
  {
    msg_.l_small = std::move(arg);
    return Init_RobotFeedback_r_big(msg_);
  }

private:
  ::my_robot_pkg::msg::RobotFeedback msg_;
};

class Init_RobotFeedback_l_big
{
public:
  Init_RobotFeedback_l_big()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotFeedback_l_small l_big(::my_robot_pkg::msg::RobotFeedback::_l_big_type arg)
  {
    msg_.l_big = std::move(arg);
    return Init_RobotFeedback_l_small(msg_);
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
  return my_robot_pkg::msg::builder::Init_RobotFeedback_l_big();
}

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__BUILDER_HPP_
