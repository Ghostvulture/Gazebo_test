// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_pkg:msg/RobotFeedback.idl
// generated code does not contain a copyright notice
#include "my_robot_pkg/msg/detail/robot_feedback__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `motors`
#include "my_robot_pkg/msg/detail/motor_feedback__functions.h"
// Member `angular_velocity`
// Member `linear_acceleration`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
my_robot_pkg__msg__RobotFeedback__init(my_robot_pkg__msg__RobotFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  // motors
  if (!my_robot_pkg__msg__MotorFeedback__Sequence__init(&msg->motors, 0)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->angular_velocity)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  // linear_acceleration
  if (!geometry_msgs__msg__Vector3__init(&msg->linear_acceleration)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_pkg__msg__RobotFeedback__fini(my_robot_pkg__msg__RobotFeedback * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // motors
  my_robot_pkg__msg__MotorFeedback__Sequence__fini(&msg->motors);
  // angular_velocity
  geometry_msgs__msg__Vector3__fini(&msg->angular_velocity);
  // linear_acceleration
  geometry_msgs__msg__Vector3__fini(&msg->linear_acceleration);
}

bool
my_robot_pkg__msg__RobotFeedback__are_equal(const my_robot_pkg__msg__RobotFeedback * lhs, const my_robot_pkg__msg__RobotFeedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // motors
  if (!my_robot_pkg__msg__MotorFeedback__Sequence__are_equal(
      &(lhs->motors), &(rhs->motors)))
  {
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->angular_velocity), &(rhs->angular_velocity)))
  {
    return false;
  }
  // linear_acceleration
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->linear_acceleration), &(rhs->linear_acceleration)))
  {
    return false;
  }
  return true;
}

bool
my_robot_pkg__msg__RobotFeedback__copy(
  const my_robot_pkg__msg__RobotFeedback * input,
  my_robot_pkg__msg__RobotFeedback * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // motors
  if (!my_robot_pkg__msg__MotorFeedback__Sequence__copy(
      &(input->motors), &(output->motors)))
  {
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->angular_velocity), &(output->angular_velocity)))
  {
    return false;
  }
  // linear_acceleration
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->linear_acceleration), &(output->linear_acceleration)))
  {
    return false;
  }
  return true;
}

my_robot_pkg__msg__RobotFeedback *
my_robot_pkg__msg__RobotFeedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_pkg__msg__RobotFeedback * msg = (my_robot_pkg__msg__RobotFeedback *)allocator.allocate(sizeof(my_robot_pkg__msg__RobotFeedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_pkg__msg__RobotFeedback));
  bool success = my_robot_pkg__msg__RobotFeedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_pkg__msg__RobotFeedback__destroy(my_robot_pkg__msg__RobotFeedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_pkg__msg__RobotFeedback__Sequence__init(my_robot_pkg__msg__RobotFeedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_pkg__msg__RobotFeedback * data = NULL;

  if (size) {
    data = (my_robot_pkg__msg__RobotFeedback *)allocator.zero_allocate(size, sizeof(my_robot_pkg__msg__RobotFeedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_pkg__msg__RobotFeedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_pkg__msg__RobotFeedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_robot_pkg__msg__RobotFeedback__Sequence__fini(my_robot_pkg__msg__RobotFeedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_robot_pkg__msg__RobotFeedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_robot_pkg__msg__RobotFeedback__Sequence *
my_robot_pkg__msg__RobotFeedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_pkg__msg__RobotFeedback__Sequence * array = (my_robot_pkg__msg__RobotFeedback__Sequence *)allocator.allocate(sizeof(my_robot_pkg__msg__RobotFeedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_pkg__msg__RobotFeedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_pkg__msg__RobotFeedback__Sequence__destroy(my_robot_pkg__msg__RobotFeedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_pkg__msg__RobotFeedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_pkg__msg__RobotFeedback__Sequence__are_equal(const my_robot_pkg__msg__RobotFeedback__Sequence * lhs, const my_robot_pkg__msg__RobotFeedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_pkg__msg__RobotFeedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_pkg__msg__RobotFeedback__Sequence__copy(
  const my_robot_pkg__msg__RobotFeedback__Sequence * input,
  my_robot_pkg__msg__RobotFeedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_pkg__msg__RobotFeedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_pkg__msg__RobotFeedback * data =
      (my_robot_pkg__msg__RobotFeedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_pkg__msg__RobotFeedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_pkg__msg__RobotFeedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_pkg__msg__RobotFeedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
