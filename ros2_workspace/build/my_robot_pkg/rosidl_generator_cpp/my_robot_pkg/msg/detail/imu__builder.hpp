// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_pkg:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__IMU__BUILDER_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_pkg/msg/detail/imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_pkg
{

namespace msg
{

namespace builder
{

class Init_Imu_gyro_z
{
public:
  explicit Init_Imu_gyro_z(::my_robot_pkg::msg::Imu & msg)
  : msg_(msg)
  {}
  ::my_robot_pkg::msg::Imu gyro_z(::my_robot_pkg::msg::Imu::_gyro_z_type arg)
  {
    msg_.gyro_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_pkg::msg::Imu msg_;
};

class Init_Imu_gyro_y
{
public:
  explicit Init_Imu_gyro_y(::my_robot_pkg::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_gyro_z gyro_y(::my_robot_pkg::msg::Imu::_gyro_y_type arg)
  {
    msg_.gyro_y = std::move(arg);
    return Init_Imu_gyro_z(msg_);
  }

private:
  ::my_robot_pkg::msg::Imu msg_;
};

class Init_Imu_gyro_x
{
public:
  explicit Init_Imu_gyro_x(::my_robot_pkg::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_gyro_y gyro_x(::my_robot_pkg::msg::Imu::_gyro_x_type arg)
  {
    msg_.gyro_x = std::move(arg);
    return Init_Imu_gyro_y(msg_);
  }

private:
  ::my_robot_pkg::msg::Imu msg_;
};

class Init_Imu_acc_z
{
public:
  explicit Init_Imu_acc_z(::my_robot_pkg::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_gyro_x acc_z(::my_robot_pkg::msg::Imu::_acc_z_type arg)
  {
    msg_.acc_z = std::move(arg);
    return Init_Imu_gyro_x(msg_);
  }

private:
  ::my_robot_pkg::msg::Imu msg_;
};

class Init_Imu_acc_y
{
public:
  explicit Init_Imu_acc_y(::my_robot_pkg::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_acc_z acc_y(::my_robot_pkg::msg::Imu::_acc_y_type arg)
  {
    msg_.acc_y = std::move(arg);
    return Init_Imu_acc_z(msg_);
  }

private:
  ::my_robot_pkg::msg::Imu msg_;
};

class Init_Imu_acc_x
{
public:
  Init_Imu_acc_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Imu_acc_y acc_x(::my_robot_pkg::msg::Imu::_acc_x_type arg)
  {
    msg_.acc_x = std::move(arg);
    return Init_Imu_acc_y(msg_);
  }

private:
  ::my_robot_pkg::msg::Imu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_pkg::msg::Imu>()
{
  return my_robot_pkg::msg::builder::Init_Imu_acc_x();
}

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__IMU__BUILDER_HPP_
