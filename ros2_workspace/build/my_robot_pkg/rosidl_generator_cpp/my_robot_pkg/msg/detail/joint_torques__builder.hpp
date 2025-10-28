// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_pkg:msg/JointTorques.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__JOINT_TORQUES__BUILDER_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__JOINT_TORQUES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_pkg/msg/detail/joint_torques__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_pkg
{

namespace msg
{

namespace builder
{

class Init_JointTorques_torques
{
public:
  Init_JointTorques_torques()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_pkg::msg::JointTorques torques(::my_robot_pkg::msg::JointTorques::_torques_type arg)
  {
    msg_.torques = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_pkg::msg::JointTorques msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_pkg::msg::JointTorques>()
{
  return my_robot_pkg::msg::builder::Init_JointTorques_torques();
}

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__JOINT_TORQUES__BUILDER_HPP_
