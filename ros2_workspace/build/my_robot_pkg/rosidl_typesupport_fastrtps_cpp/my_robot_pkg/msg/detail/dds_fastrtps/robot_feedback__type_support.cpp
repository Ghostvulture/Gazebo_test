// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from my_robot_pkg:msg/RobotFeedback.idl
// generated code does not contain a copyright notice
#include "my_robot_pkg/msg/detail/robot_feedback__rosidl_typesupport_fastrtps_cpp.hpp"
#include "my_robot_pkg/msg/detail/robot_feedback__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace my_robot_pkg
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const my_robot_pkg::msg::MotorFeedback &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  my_robot_pkg::msg::MotorFeedback &);
size_t get_serialized_size(
  const my_robot_pkg::msg::MotorFeedback &,
  size_t current_alignment);
size_t
max_serialized_size_MotorFeedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace my_robot_pkg

// functions for my_robot_pkg::msg::MotorFeedback already declared above

// functions for my_robot_pkg::msg::MotorFeedback already declared above

// functions for my_robot_pkg::msg::MotorFeedback already declared above

// functions for my_robot_pkg::msg::MotorFeedback already declared above

// functions for my_robot_pkg::msg::MotorFeedback already declared above

namespace my_robot_pkg
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const my_robot_pkg::msg::Imu &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  my_robot_pkg::msg::Imu &);
size_t get_serialized_size(
  const my_robot_pkg::msg::Imu &,
  size_t current_alignment);
size_t
max_serialized_size_Imu(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace my_robot_pkg


namespace my_robot_pkg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_robot_pkg
cdr_serialize(
  const my_robot_pkg::msg::RobotFeedback & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: l_big
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.l_big,
    cdr);
  // Member: l_small
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.l_small,
    cdr);
  // Member: r_big
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.r_big,
    cdr);
  // Member: r_small
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.r_small,
    cdr);
  // Member: l_wheel
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.l_wheel,
    cdr);
  // Member: r_wheel
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.r_wheel,
    cdr);
  // Member: imu
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.imu,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_robot_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  my_robot_pkg::msg::RobotFeedback & ros_message)
{
  // Member: l_big
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.l_big);

  // Member: l_small
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.l_small);

  // Member: r_big
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.r_big);

  // Member: r_small
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.r_small);

  // Member: l_wheel
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.l_wheel);

  // Member: r_wheel
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.r_wheel);

  // Member: imu
  my_robot_pkg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.imu);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_robot_pkg
get_serialized_size(
  const my_robot_pkg::msg::RobotFeedback & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: l_big

  current_alignment +=
    my_robot_pkg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.l_big, current_alignment);
  // Member: l_small

  current_alignment +=
    my_robot_pkg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.l_small, current_alignment);
  // Member: r_big

  current_alignment +=
    my_robot_pkg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.r_big, current_alignment);
  // Member: r_small

  current_alignment +=
    my_robot_pkg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.r_small, current_alignment);
  // Member: l_wheel

  current_alignment +=
    my_robot_pkg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.l_wheel, current_alignment);
  // Member: r_wheel

  current_alignment +=
    my_robot_pkg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.r_wheel, current_alignment);
  // Member: imu

  current_alignment +=
    my_robot_pkg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.imu, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_robot_pkg
max_serialized_size_RobotFeedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: l_big
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        my_robot_pkg::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorFeedback(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: l_small
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        my_robot_pkg::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorFeedback(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: r_big
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        my_robot_pkg::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorFeedback(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: r_small
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        my_robot_pkg::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorFeedback(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: l_wheel
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        my_robot_pkg::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorFeedback(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: r_wheel
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        my_robot_pkg::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorFeedback(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: imu
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        my_robot_pkg::msg::typesupport_fastrtps_cpp::max_serialized_size_Imu(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_robot_pkg::msg::RobotFeedback;
    is_plain =
      (
      offsetof(DataType, imu) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RobotFeedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const my_robot_pkg::msg::RobotFeedback *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotFeedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<my_robot_pkg::msg::RobotFeedback *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotFeedback__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const my_robot_pkg::msg::RobotFeedback *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotFeedback__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotFeedback(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotFeedback__callbacks = {
  "my_robot_pkg::msg",
  "RobotFeedback",
  _RobotFeedback__cdr_serialize,
  _RobotFeedback__cdr_deserialize,
  _RobotFeedback__get_serialized_size,
  _RobotFeedback__max_serialized_size
};

static rosidl_message_type_support_t _RobotFeedback__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotFeedback__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace my_robot_pkg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_my_robot_pkg
const rosidl_message_type_support_t *
get_message_type_support_handle<my_robot_pkg::msg::RobotFeedback>()
{
  return &my_robot_pkg::msg::typesupport_fastrtps_cpp::_RobotFeedback__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, my_robot_pkg, msg, RobotFeedback)() {
  return &my_robot_pkg::msg::typesupport_fastrtps_cpp::_RobotFeedback__handle;
}

#ifdef __cplusplus
}
#endif
