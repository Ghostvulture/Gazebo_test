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
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'motors'
#include "my_robot_pkg/msg/detail/motor_feedback__struct.hpp"
// Member 'angular_velocity'
// Member 'linear_acceleration'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

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
  : header(_init),
    angular_velocity(_init),
    linear_acceleration(_init)
  {
    (void)_init;
  }

  explicit RobotFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    angular_velocity(_alloc, _init),
    linear_acceleration(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _motors_type =
    std::vector<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>>>;
  _motors_type motors;
  using _angular_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _angular_velocity_type angular_velocity;
  using _linear_acceleration_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _linear_acceleration_type linear_acceleration;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__motors(
    const std::vector<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<my_robot_pkg::msg::MotorFeedback_<ContainerAllocator>>> & _arg)
  {
    this->motors = _arg;
    return *this;
  }
  Type & set__angular_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->angular_velocity = _arg;
    return *this;
  }
  Type & set__linear_acceleration(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->linear_acceleration = _arg;
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
    if (this->header != other.header) {
      return false;
    }
    if (this->motors != other.motors) {
      return false;
    }
    if (this->angular_velocity != other.angular_velocity) {
      return false;
    }
    if (this->linear_acceleration != other.linear_acceleration) {
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
