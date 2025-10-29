# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_robot_pkg:msg/RobotFeedback.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotFeedback(type):
    """Metaclass of message 'RobotFeedback'."""

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
                'my_robot_pkg.msg.RobotFeedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_feedback
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_feedback

            from my_robot_pkg.msg import Imu
            if Imu.__class__._TYPE_SUPPORT is None:
                Imu.__class__.__import_type_support__()

            from my_robot_pkg.msg import MotorFeedback
            if MotorFeedback.__class__._TYPE_SUPPORT is None:
                MotorFeedback.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotFeedback(metaclass=Metaclass_RobotFeedback):
    """Message class 'RobotFeedback'."""

    __slots__ = [
        '_l_big',
        '_l_small',
        '_r_big',
        '_r_small',
        '_l_wheel',
        '_r_wheel',
        '_imu',
    ]

    _fields_and_field_types = {
        'l_big': 'my_robot_pkg/MotorFeedback',
        'l_small': 'my_robot_pkg/MotorFeedback',
        'r_big': 'my_robot_pkg/MotorFeedback',
        'r_small': 'my_robot_pkg/MotorFeedback',
        'l_wheel': 'my_robot_pkg/MotorFeedback',
        'r_wheel': 'my_robot_pkg/MotorFeedback',
        'imu': 'my_robot_pkg/Imu',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['my_robot_pkg', 'msg'], 'MotorFeedback'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['my_robot_pkg', 'msg'], 'MotorFeedback'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['my_robot_pkg', 'msg'], 'MotorFeedback'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['my_robot_pkg', 'msg'], 'MotorFeedback'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['my_robot_pkg', 'msg'], 'MotorFeedback'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['my_robot_pkg', 'msg'], 'MotorFeedback'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['my_robot_pkg', 'msg'], 'Imu'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from my_robot_pkg.msg import MotorFeedback
        self.l_big = kwargs.get('l_big', MotorFeedback())
        from my_robot_pkg.msg import MotorFeedback
        self.l_small = kwargs.get('l_small', MotorFeedback())
        from my_robot_pkg.msg import MotorFeedback
        self.r_big = kwargs.get('r_big', MotorFeedback())
        from my_robot_pkg.msg import MotorFeedback
        self.r_small = kwargs.get('r_small', MotorFeedback())
        from my_robot_pkg.msg import MotorFeedback
        self.l_wheel = kwargs.get('l_wheel', MotorFeedback())
        from my_robot_pkg.msg import MotorFeedback
        self.r_wheel = kwargs.get('r_wheel', MotorFeedback())
        from my_robot_pkg.msg import Imu
        self.imu = kwargs.get('imu', Imu())

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
        if self.l_big != other.l_big:
            return False
        if self.l_small != other.l_small:
            return False
        if self.r_big != other.r_big:
            return False
        if self.r_small != other.r_small:
            return False
        if self.l_wheel != other.l_wheel:
            return False
        if self.r_wheel != other.r_wheel:
            return False
        if self.imu != other.imu:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def l_big(self):
        """Message field 'l_big'."""
        return self._l_big

    @l_big.setter
    def l_big(self, value):
        if __debug__:
            from my_robot_pkg.msg import MotorFeedback
            assert \
                isinstance(value, MotorFeedback), \
                "The 'l_big' field must be a sub message of type 'MotorFeedback'"
        self._l_big = value

    @builtins.property
    def l_small(self):
        """Message field 'l_small'."""
        return self._l_small

    @l_small.setter
    def l_small(self, value):
        if __debug__:
            from my_robot_pkg.msg import MotorFeedback
            assert \
                isinstance(value, MotorFeedback), \
                "The 'l_small' field must be a sub message of type 'MotorFeedback'"
        self._l_small = value

    @builtins.property
    def r_big(self):
        """Message field 'r_big'."""
        return self._r_big

    @r_big.setter
    def r_big(self, value):
        if __debug__:
            from my_robot_pkg.msg import MotorFeedback
            assert \
                isinstance(value, MotorFeedback), \
                "The 'r_big' field must be a sub message of type 'MotorFeedback'"
        self._r_big = value

    @builtins.property
    def r_small(self):
        """Message field 'r_small'."""
        return self._r_small

    @r_small.setter
    def r_small(self, value):
        if __debug__:
            from my_robot_pkg.msg import MotorFeedback
            assert \
                isinstance(value, MotorFeedback), \
                "The 'r_small' field must be a sub message of type 'MotorFeedback'"
        self._r_small = value

    @builtins.property
    def l_wheel(self):
        """Message field 'l_wheel'."""
        return self._l_wheel

    @l_wheel.setter
    def l_wheel(self, value):
        if __debug__:
            from my_robot_pkg.msg import MotorFeedback
            assert \
                isinstance(value, MotorFeedback), \
                "The 'l_wheel' field must be a sub message of type 'MotorFeedback'"
        self._l_wheel = value

    @builtins.property
    def r_wheel(self):
        """Message field 'r_wheel'."""
        return self._r_wheel

    @r_wheel.setter
    def r_wheel(self, value):
        if __debug__:
            from my_robot_pkg.msg import MotorFeedback
            assert \
                isinstance(value, MotorFeedback), \
                "The 'r_wheel' field must be a sub message of type 'MotorFeedback'"
        self._r_wheel = value

    @builtins.property
    def imu(self):
        """Message field 'imu'."""
        return self._imu

    @imu.setter
    def imu(self, value):
        if __debug__:
            from my_robot_pkg.msg import Imu
            assert \
                isinstance(value, Imu), \
                "The 'imu' field must be a sub message of type 'Imu'"
        self._imu = value
