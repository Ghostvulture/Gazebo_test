// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_robot_pkg:msg/MotorFeedback.idl
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
#include "my_robot_pkg/msg/detail/motor_feedback__struct.h"
#include "my_robot_pkg/msg/detail/motor_feedback__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_robot_pkg__msg__motor_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("my_robot_pkg.msg._motor_feedback.MotorFeedback", full_classname_dest, 46) == 0);
  }
  my_robot_pkg__msg__MotorFeedback * ros_message = _ros_message;
  {  // pos_fdb
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_fdb");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_fdb = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // sbd_fdb
    PyObject * field = PyObject_GetAttrString(_pymsg, "sbd_fdb");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->sbd_fdb = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tor_fdb
    PyObject * field = PyObject_GetAttrString(_pymsg, "tor_fdb");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tor_fdb = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_robot_pkg__msg__motor_feedback__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MotorFeedback */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_robot_pkg.msg._motor_feedback");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MotorFeedback");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_robot_pkg__msg__MotorFeedback * ros_message = (my_robot_pkg__msg__MotorFeedback *)raw_ros_message;
  {  // pos_fdb
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_fdb);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_fdb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sbd_fdb
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->sbd_fdb);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sbd_fdb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tor_fdb
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tor_fdb);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tor_fdb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
