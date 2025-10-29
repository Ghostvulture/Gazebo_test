// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_pkg:msg/RobotFeedback.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__STRUCT_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'l_big'
// Member 'l_small'
// Member 'r_big'
// Member 'r_small'
// Member 'l_wheel'
// Member 'r_wheel'
#include "my_robot_pkg/msg/detail/motor_feedback__struct.hpp"
// Member 'imu'
#include "my_robot_pkg/msg/detail/imu__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_pkg__msg__RobotFeedback __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_pkg__msg__RobotFeedback __declspec(deprecated)
#endif

namespace my_robot_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotFeedback_
{
  using Type = RobotFeedback_<ContainerAllocator>;

  explicit RobotFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : l_big(_init),
    l_small(_init),
    r_big(_init),
    r_small(_init),
    l_wheel(_init),
    r_wheel(_init),
    imu(_init)
  {
    (void)_init;
  }

  explicit RobotFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : l_big(_alloc, _init),
    l_small(_alloc, _init),
    r_big(_alloc, _init),
    r_small(_alloc, _init),
    l_wheel(_alloc, _init),
    r_wheel(_alloc, _init),
    imu(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _l_big_type =
    my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>;
  _l_big_type l_big;
  using _l_small_type =
    my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>;
  _l_small_type l_small;
  using _r_big_type =
    my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>;
  _r_big_type r_big;
  using _r_small_type =
    my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>;
  _r_small_type r_small;
  using _l_wheel_type =
    my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>;
  _l_wheel_type l_wheel;
  using _r_wheel_type =
    my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>;
  _r_wheel_type r_wheel;
  using _imu_type =
    my_robot_pkg::msg::Imu_<ContainerAllocator>;
  _imu_type imu;

  // setters for named parameter idiom
  Type & set__l_big(
    const my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> & _arg)
  {
    this->l_big = _arg;
    return *this;
  }
  Type & set__l_small(
    const my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> & _arg)
  {
    this->l_small = _arg;
    return *this;
  }
  Type & set__r_big(
    const my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> & _arg)
  {
    this->r_big = _arg;
    return *this;
  }
  Type & set__r_small(
    const my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> & _arg)
  {
    this->r_small = _arg;
    return *this;
  }
  Type & set__l_wheel(
    const my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> & _arg)
  {
    this->l_wheel = _arg;
    return *this;
  }
  Type & set__r_wheel(
    const my_robot_pkg::msg::MotorFeedback_<ContainerAllocator> & _arg)
  {
    this->r_wheel = _arg;
    return *this;
  }
  Type & set__imu(
    const my_robot_pkg::msg::Imu_<ContainerAllocator> & _arg)
  {
    this->imu = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_pkg::msg::RobotFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_pkg::msg::RobotFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_pkg::msg::RobotFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_pkg::msg::RobotFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_pkg::msg::RobotFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_pkg::msg::RobotFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_pkg::msg::RobotFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_pkg::msg::RobotFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_pkg::msg::RobotFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_pkg::msg::RobotFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_pkg__msg__RobotFeedback
    std::shared_ptr<my_robot_pkg::msg::RobotFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_pkg__msg__RobotFeedback
    std::shared_ptr<my_robot_pkg::msg::RobotFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotFeedback_ & other) const
  {
    if (this->l_big != other.l_big) {
      return false;
    }
    if (this->l_small != other.l_small) {
      return false;
    }
    if (this->r_big != other.r_big) {
      return false;
    }
    if (this->r_small != other.r_small) {
      return false;
    }
    if (this->l_wheel != other.l_wheel) {
      return false;
    }
    if (this->r_wheel != other.r_wheel) {
      return false;
    }
    if (this->imu != other.imu) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotFeedback_

// alias to use template instance with default allocator
using RobotFeedback =
  my_robot_pkg::msg::RobotFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__ROBOT_FEEDBACK__STRUCT_HPP_
