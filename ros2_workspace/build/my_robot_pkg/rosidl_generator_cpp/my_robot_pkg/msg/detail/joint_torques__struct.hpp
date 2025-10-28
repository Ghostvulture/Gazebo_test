// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_pkg:msg/JointTorques.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_PKG__MSG__DETAIL__JOINT_TORQUES__STRUCT_HPP_
#define MY_ROBOT_PKG__MSG__DETAIL__JOINT_TORQUES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_pkg__msg__JointTorques __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_pkg__msg__JointTorques __declspec(deprecated)
#endif

namespace my_robot_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointTorques_
{
  using Type = JointTorques_<ContainerAllocator>;

  explicit JointTorques_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit JointTorques_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _torques_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _torques_type torques;

  // setters for named parameter idiom
  Type & set__torques(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->torques = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_pkg::msg::JointTorques_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_pkg::msg::JointTorques_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_pkg::msg::JointTorques_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_pkg::msg::JointTorques_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_pkg::msg::JointTorques_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_pkg::msg::JointTorques_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_pkg::msg::JointTorques_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_pkg::msg::JointTorques_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_pkg::msg::JointTorques_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_pkg::msg::JointTorques_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_pkg__msg__JointTorques
    std::shared_ptr<my_robot_pkg::msg::JointTorques_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_pkg__msg__JointTorques
    std::shared_ptr<my_robot_pkg::msg::JointTorques_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointTorques_ & other) const
  {
    if (this->torques != other.torques) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointTorques_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointTorques_

// alias to use template instance with default allocator
using JointTorques =
  my_robot_pkg::msg::JointTorques_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_pkg

#endif  // MY_ROBOT_PKG__MSG__DETAIL__JOINT_TORQUES__STRUCT_HPP_
