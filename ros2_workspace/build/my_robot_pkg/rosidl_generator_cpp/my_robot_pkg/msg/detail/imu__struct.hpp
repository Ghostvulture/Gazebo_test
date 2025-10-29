// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_pkg:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__IMU__STRUCT_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__IMU__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_pkg__msg__Imu __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_pkg__msg__Imu __declspec(deprecated)
#endif

namespace my_robot_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Imu_
{
  using Type = Imu_<ContainerAllocator>;

  explicit Imu_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acc_x = 0.0;
      this->acc_y = 0.0;
      this->acc_z = 0.0;
      this->gyro_x = 0.0;
      this->gyro_y = 0.0;
      this->gyro_z = 0.0;
    }
  }

  explicit Imu_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acc_x = 0.0;
      this->acc_y = 0.0;
      this->acc_z = 0.0;
      this->gyro_x = 0.0;
      this->gyro_y = 0.0;
      this->gyro_z = 0.0;
    }
  }

  // field types and members
  using _acc_x_type =
    double;
  _acc_x_type acc_x;
  using _acc_y_type =
    double;
  _acc_y_type acc_y;
  using _acc_z_type =
    double;
  _acc_z_type acc_z;
  using _gyro_x_type =
    double;
  _gyro_x_type gyro_x;
  using _gyro_y_type =
    double;
  _gyro_y_type gyro_y;
  using _gyro_z_type =
    double;
  _gyro_z_type gyro_z;

  // setters for named parameter idiom
  Type & set__acc_x(
    const double & _arg)
  {
    this->acc_x = _arg;
    return *this;
  }
  Type & set__acc_y(
    const double & _arg)
  {
    this->acc_y = _arg;
    return *this;
  }
  Type & set__acc_z(
    const double & _arg)
  {
    this->acc_z = _arg;
    return *this;
  }
  Type & set__gyro_x(
    const double & _arg)
  {
    this->gyro_x = _arg;
    return *this;
  }
  Type & set__gyro_y(
    const double & _arg)
  {
    this->gyro_y = _arg;
    return *this;
  }
  Type & set__gyro_z(
    const double & _arg)
  {
    this->gyro_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_pkg::msg::Imu_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_pkg::msg::Imu_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_pkg::msg::Imu_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_pkg::msg::Imu_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_pkg::msg::Imu_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_pkg::msg::Imu_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_pkg::msg::Imu_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_pkg::msg::Imu_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_pkg::msg::Imu_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_pkg::msg::Imu_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_pkg__msg__Imu
    std::shared_ptr<my_robot_pkg::msg::Imu_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_pkg__msg__Imu
    std::shared_ptr<my_robot_pkg::msg::Imu_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Imu_ & other) const
  {
    if (this->acc_x != other.acc_x) {
      return false;
    }
    if (this->acc_y != other.acc_y) {
      return false;
    }
    if (this->acc_z != other.acc_z) {
      return false;
    }
    if (this->gyro_x != other.gyro_x) {
      return false;
    }
    if (this->gyro_y != other.gyro_y) {
      return false;
    }
    if (this->gyro_z != other.gyro_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Imu_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Imu_

// alias to use template instance with default allocator
using Imu =
  my_robot_pkg::msg::Imu_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__IMU__STRUCT_HPP_
