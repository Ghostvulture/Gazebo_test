# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_robot_pkg:msg/MotorFeedback.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MotorFeedback(type):
    """Metaclass of message 'MotorFeedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_robot_pkg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_robot_pkg.msg.MotorFeedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor_feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor_feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor_feedback
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor_feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor_feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MotorFeedback(metaclass=Metaclass_MotorFeedback):
    """Message class 'MotorFeedback'."""

    __slots__ = [
        '_pos_fdb',
        '_sbd_fdb',
        '_tor_fdb',
    ]

    _fields_and_field_types = {
        'pos_fdb': 'double',
        'sbd_fdb': 'double',
        'tor_fdb': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pos_fdb = kwargs.get('pos_fdb', float())
        self.sbd_fdb = kwargs.get('sbd_fdb', float())
        self.tor_fdb = kwargs.get('tor_fdb', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pos_fdb != other.pos_fdb:
            return False
        if self.sbd_fdb != other.sbd_fdb:
            return False
        if self.tor_fdb != other.tor_fdb:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pos_fdb(self):
        """Message field 'pos_fdb'."""
        return self._pos_fdb

    @pos_fdb.setter
    def pos_fdb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_fdb' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pos_fdb' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pos_fdb = value

    @builtins.property
    def sbd_fdb(self):
        """Message field 'sbd_fdb'."""
        return self._sbd_fdb

    @sbd_fdb.setter
    def sbd_fdb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'sbd_fdb' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'sbd_fdb' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._sbd_fdb = value

    @builtins.property
    def tor_fdb(self):
        """Message field 'tor_fdb'."""
        return self._tor_fdb

    @tor_fdb.setter
    def tor_fdb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tor_fdb' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tor_fdb' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tor_fdb = value
