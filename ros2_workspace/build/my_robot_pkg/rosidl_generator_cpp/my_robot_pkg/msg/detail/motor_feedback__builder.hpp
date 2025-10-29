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

class Init_MotorFeedback_tor_fdb
{
public:
  explicit Init_MotorFeedback_tor_fdb(::my_robot_pkg::msg::MotorFeedback & msg)
  : msg_(msg)
  {}
  ::my_robot_pkg::msg::MotorFeedback tor_fdb(::my_robot_pkg::msg::MotorFeedback::_tor_fdb_type arg)
  {
    msg_.tor_fdb = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_pkg::msg::MotorFeedback msg_;
};

class Init_MotorFeedback_sbd_fdb
{
public:
  explicit Init_MotorFeedback_sbd_fdb(::my_robot_pkg::msg::MotorFeedback & msg)
  : msg_(msg)
  {}
  Init_MotorFeedback_tor_fdb sbd_fdb(::my_robot_pkg::msg::MotorFeedback::_sbd_fdb_type arg)
  {
    msg_.sbd_fdb = std::move(arg);
    return Init_MotorFeedback_tor_fdb(msg_);
  }

private:
  ::my_robot_pkg::msg::MotorFeedback msg_;
};

class Init_MotorFeedback_pos_fdb
{
public:
  Init_MotorFeedback_pos_fdb()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorFeedback_sbd_fdb pos_fdb(::my_robot_pkg::msg::MotorFeedback::_pos_fdb_type arg)
  {
    msg_.pos_fdb = std::move(arg);
    return Init_MotorFeedback_sbd_fdb(msg_);
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
  return my_robot_pkg::msg::builder::Init_MotorFeedback_pos_fdb();
}

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__BUILDER_HPP_
