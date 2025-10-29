// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_robot_pkg:msg/RobotFeedback.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_robot_pkg/msg/detail/robot_feedback__rosidl_typesupport_introspection_c.h"
#include "my_robot_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_robot_pkg/msg/detail/robot_feedback__functions.h"
#include "my_robot_pkg/msg/detail/robot_feedback__struct.h"


// Include directives for member types
// Member `l_big`
// Member `l_small`
// Member `r_big`
// Member `r_small`
// Member `l_wheel`
// Member `r_wheel`
#include "my_robot_pkg/msg/motor_feedback.h"
// Member `l_big`
// Member `l_small`
// Member `r_big`
// Member `r_small`
// Member `l_wheel`
// Member `r_wheel`
#include "my_robot_pkg/msg/detail/motor_feedback__rosidl_typesupport_introspection_c.h"
// Member `imu`
#include "my_robot_pkg/msg/imu.h"
// Member `imu`
#include "my_robot_pkg/msg/detail/imu__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_robot_pkg__msg__RobotFeedback__init(message_memory);
}

void my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_fini_function(void * message_memory)
{
  my_robot_pkg__msg__RobotFeedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_member_array[7] = {
  {
    "l_big",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_pkg__msg__RobotFeedback, l_big),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "l_small",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_pkg__msg__RobotFeedback, l_small),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "r_big",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_pkg__msg__RobotFeedback, r_big),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "r_small",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_pkg__msg__RobotFeedback, r_small),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "l_wheel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_pkg__msg__RobotFeedback, l_wheel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "r_wheel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_pkg__msg__RobotFeedback, r_wheel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "imu",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_pkg__msg__RobotFeedback, imu),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_members = {
  "my_robot_pkg__msg",  // message namespace
  "RobotFeedback",  // message name
  7,  // number of fields
  sizeof(my_robot_pkg__msg__RobotFeedback),
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_member_array,  // message members
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_init_function,  // function to initialize message memory (memory has to be allocated)
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_type_support_handle = {
  0,
  &my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_robot_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_pkg, msg, RobotFeedback)() {
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_pkg, msg, MotorFeedback)();
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_pkg, msg, MotorFeedback)();
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_pkg, msg, MotorFeedback)();
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_pkg, msg, MotorFeedback)();
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_pkg, msg, MotorFeedback)();
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_pkg, msg, MotorFeedback)();
  my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_pkg, msg, Imu)();
  if (!my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_type_support_handle.typesupport_identifier) {
    my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_robot_pkg__msg__RobotFeedback__rosidl_typesupport_introspection_c__RobotFeedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
