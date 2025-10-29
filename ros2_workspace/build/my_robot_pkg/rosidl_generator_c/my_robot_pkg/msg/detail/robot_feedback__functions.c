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
// Member `l_big`
// Member `l_small`
// Member `r_big`
// Member `r_small`
// Member `l_wheel`
// Member `r_wheel`
#include "my_robot_pkg/msg/detail/motor_feedback__functions.h"
// Member `imu`
#include "my_robot_pkg/msg/detail/imu__functions.h"

bool
my_robot_pkg__msg__RobotFeedback__init(my_robot_pkg__msg__RobotFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // l_big
  if (!my_robot_pkg__msg__MotorFeedback__init(&msg->l_big)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  // l_small
  if (!my_robot_pkg__msg__MotorFeedback__init(&msg->l_small)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  // r_big
  if (!my_robot_pkg__msg__MotorFeedback__init(&msg->r_big)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  // r_small
  if (!my_robot_pkg__msg__MotorFeedback__init(&msg->r_small)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  // l_wheel
  if (!my_robot_pkg__msg__MotorFeedback__init(&msg->l_wheel)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  // r_wheel
  if (!my_robot_pkg__msg__MotorFeedback__init(&msg->r_wheel)) {
    my_robot_pkg__msg__RobotFeedback__fini(msg);
    return false;
  }
  // imu
  if (!my_robot_pkg__msg__Imu__init(&msg->imu)) {
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
  // l_big
  my_robot_pkg__msg__MotorFeedback__fini(&msg->l_big);
  // l_small
  my_robot_pkg__msg__MotorFeedback__fini(&msg->l_small);
  // r_big
  my_robot_pkg__msg__MotorFeedback__fini(&msg->r_big);
  // r_small
  my_robot_pkg__msg__MotorFeedback__fini(&msg->r_small);
  // l_wheel
  my_robot_pkg__msg__MotorFeedback__fini(&msg->l_wheel);
  // r_wheel
  my_robot_pkg__msg__MotorFeedback__fini(&msg->r_wheel);
  // imu
  my_robot_pkg__msg__Imu__fini(&msg->imu);
}

bool
my_robot_pkg__msg__RobotFeedback__are_equal(const my_robot_pkg__msg__RobotFeedback * lhs, const my_robot_pkg__msg__RobotFeedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // l_big
  if (!my_robot_pkg__msg__MotorFeedback__are_equal(
      &(lhs->l_big), &(rhs->l_big)))
  {
    return false;
  }
  // l_small
  if (!my_robot_pkg__msg__MotorFeedback__are_equal(
      &(lhs->l_small), &(rhs->l_small)))
  {
    return false;
  }
  // r_big
  if (!my_robot_pkg__msg__MotorFeedback__are_equal(
      &(lhs->r_big), &(rhs->r_big)))
  {
    return false;
  }
  // r_small
  if (!my_robot_pkg__msg__MotorFeedback__are_equal(
      &(lhs->r_small), &(rhs->r_small)))
  {
    return false;
  }
  // l_wheel
  if (!my_robot_pkg__msg__MotorFeedback__are_equal(
      &(lhs->l_wheel), &(rhs->l_wheel)))
  {
    return false;
  }
  // r_wheel
  if (!my_robot_pkg__msg__MotorFeedback__are_equal(
      &(lhs->r_wheel), &(rhs->r_wheel)))
  {
    return false;
  }
  // imu
  if (!my_robot_pkg__msg__Imu__are_equal(
      &(lhs->imu), &(rhs->imu)))
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
  // l_big
  if (!my_robot_pkg__msg__MotorFeedback__copy(
      &(input->l_big), &(output->l_big)))
  {
    return false;
  }
  // l_small
  if (!my_robot_pkg__msg__MotorFeedback__copy(
      &(input->l_small), &(output->l_small)))
  {
    return false;
  }
  // r_big
  if (!my_robot_pkg__msg__MotorFeedback__copy(
      &(input->r_big), &(output->r_big)))
  {
    return false;
  }
  // r_small
  if (!my_robot_pkg__msg__MotorFeedback__copy(
      &(input->r_small), &(output->r_small)))
  {
    return false;
  }
  // l_wheel
  if (!my_robot_pkg__msg__MotorFeedback__copy(
      &(input->l_wheel), &(output->l_wheel)))
  {
    return false;
  }
  // r_wheel
  if (!my_robot_pkg__msg__MotorFeedback__copy(
      &(input->r_wheel), &(output->r_wheel)))
  {
    return false;
  }
  // imu
  if (!my_robot_pkg__msg__Imu__copy(
      &(input->imu), &(output->imu)))
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
