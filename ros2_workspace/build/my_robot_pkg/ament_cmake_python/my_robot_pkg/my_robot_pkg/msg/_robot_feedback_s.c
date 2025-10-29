// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_robot_pkg:msg/RobotFeedback.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "my_robot_pkg/msg/detail/robot_feedback__struct.h"
#include "my_robot_pkg/msg/detail/robot_feedback__functions.h"

bool my_robot_pkg__msg__motor_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * my_robot_pkg__msg__motor_feedback__convert_to_py(void * raw_ros_message);
bool my_robot_pkg__msg__motor_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * my_robot_pkg__msg__motor_feedback__convert_to_py(void * raw_ros_message);
bool my_robot_pkg__msg__motor_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * my_robot_pkg__msg__motor_feedback__convert_to_py(void * raw_ros_message);
bool my_robot_pkg__msg__motor_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * my_robot_pkg__msg__motor_feedback__convert_to_py(void * raw_ros_message);
bool my_robot_pkg__msg__motor_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * my_robot_pkg__msg__motor_feedback__convert_to_py(void * raw_ros_message);
bool my_robot_pkg__msg__motor_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * my_robot_pkg__msg__motor_feedback__convert_to_py(void * raw_ros_message);
bool my_robot_pkg__msg__imu__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * my_robot_pkg__msg__imu__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool my_robot_pkg__msg__robot_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[47];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("my_robot_pkg.msg._robot_feedback.RobotFeedback", full_classname_dest, 46) == 0);
  }
  my_robot_pkg__msg__RobotFeedback * ros_message = _ros_message;
  {  // l_big
    PyObject * field = PyObject_GetAttrString(_pymsg, "l_big");
    if (!field) {
      return false;
    }
    if (!my_robot_pkg__msg__motor_feedback__convert_from_py(field, &ros_message->l_big)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // l_small
    PyObject * field = PyObject_GetAttrString(_pymsg, "l_small");
    if (!field) {
      return false;
    }
    if (!my_robot_pkg__msg__motor_feedback__convert_from_py(field, &ros_message->l_small)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // r_big
    PyObject * field = PyObject_GetAttrString(_pymsg, "r_big");
    if (!field) {
      return false;
    }
    if (!my_robot_pkg__msg__motor_feedback__convert_from_py(field, &ros_message->r_big)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // r_small
    PyObject * field = PyObject_GetAttrString(_pymsg, "r_small");
    if (!field) {
      return false;
    }
    if (!my_robot_pkg__msg__motor_feedback__convert_from_py(field, &ros_message->r_small)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // l_wheel
    PyObject * field = PyObject_GetAttrString(_pymsg, "l_wheel");
    if (!field) {
      return false;
    }
    if (!my_robot_pkg__msg__motor_feedback__convert_from_py(field, &ros_message->l_wheel)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // r_wheel
    PyObject * field = PyObject_GetAttrString(_pymsg, "r_wheel");
    if (!field) {
      return false;
    }
    if (!my_robot_pkg__msg__motor_feedback__convert_from_py(field, &ros_message->r_wheel)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // imu
    PyObject * field = PyObject_GetAttrString(_pymsg, "imu");
    if (!field) {
      return false;
    }
    if (!my_robot_pkg__msg__imu__convert_from_py(field, &ros_message->imu)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_robot_pkg__msg__robot_feedback__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RobotFeedback */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_robot_pkg.msg._robot_feedback");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RobotFeedback");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_robot_pkg__msg__RobotFeedback * ros_message = (my_robot_pkg__msg__RobotFeedback *)raw_ros_message;
  {  // l_big
    PyObject * field = NULL;
    field = my_robot_pkg__msg__motor_feedback__convert_to_py(&ros_message->l_big);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "l_big", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // l_small
    PyObject * field = NULL;
    field = my_robot_pkg__msg__motor_feedback__convert_to_py(&ros_message->l_small);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "l_small", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // r_big
    PyObject * field = NULL;
    field = my_robot_pkg__msg__motor_feedback__convert_to_py(&ros_message->r_big);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "r_big", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // r_small
    PyObject * field = NULL;
    field = my_robot_pkg__msg__motor_feedback__convert_to_py(&ros_message->r_small);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "r_small", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // l_wheel
    PyObject * field = NULL;
    field = my_robot_pkg__msg__motor_feedback__convert_to_py(&ros_message->l_wheel);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "l_wheel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // r_wheel
    PyObject * field = NULL;
    field = my_robot_pkg__msg__motor_feedback__convert_to_py(&ros_message->r_wheel);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "r_wheel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // imu
    PyObject * field = NULL;
    field = my_robot_pkg__msg__imu__convert_to_py(&ros_message->imu);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "imu", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
