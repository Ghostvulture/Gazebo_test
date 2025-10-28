// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_pkg:msg/MotorFeedback.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__STRUCT_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_pkg__msg__MotorFeedback __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_pkg__msg__MotorFeedback __declspec(deprecated)
#endif

namespace my_robot_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorFeedback_
{
  using Type = MotorFeedback_<ContainerAllocator>;

  explicit MotorFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0.0;
      this->velocity = 0.0;
      this->torque = 0.0;
    }
  }

  explicit MotorFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0.0;
      this->velocity = 0.0;
      this->torque = 0.0;
    }
  }

  // field types and members
  using _position_type =
    double;
  _position_type position;
  using _velocity_type =
    double;
  _velocity_type velocity;
  using _torque_type =
    double;
  _torque_type torque;

  // setters for named parameter idiom
  Type & set__position(
    const double & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__velocity(
    const double & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__torque(
    const double & _arg)
  {
    this->torque = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_pkg__msg__MotorFeedback
    std::shared_ptr<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_pkg__msg__MotorFeedback
    std::shared_ptr<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorFeedback_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->torque != other.torque) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorFeedback_

// alias to use template instance with default allocator
using MotorFeedback =
  my_robot_pkg::msg::MotorFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__MOTOR_FEEDBACK__STRUCT_HPP_
