# generated from rosidl_generator_py/resource/_idl.py.em
# with input from go2_tutorial_inter:srv/Cruising.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Cruising_Request(type):
    """Metaclass of message 'Cruising_Request'."""

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
            module = import_type_support('go2_tutorial_inter')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'go2_tutorial_inter.srv.Cruising_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cruising__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cruising__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cruising__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cruising__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cruising__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Cruising_Request(metaclass=Metaclass_Cruising_Request):
    """Message class 'Cruising_Request'."""

    __slots__ = [
        '_flag',
    ]

    _fields_and_field_types = {
        'flag': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.flag = kwargs.get('flag', int())

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
        if self.flag != other.flag:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def flag(self):
        """Message field 'flag'."""
        return self._flag

    @flag.setter
    def flag(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'flag' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'flag' field must be an integer in [-2147483648, 2147483647]"
        self._flag = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_Cruising_Response(type):
    """Metaclass of message 'Cruising_Response'."""

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
            module = import_type_support('go2_tutorial_inter')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'go2_tutorial_inter.srv.Cruising_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cruising__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cruising__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cruising__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cruising__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cruising__response

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Cruising_Response(metaclass=Metaclass_Cruising_Response):
    """Message class 'Cruising_Response'."""

    __slots__ = [
        '_point',
    ]

    _fields_and_field_types = {
        'point': 'geometry_msgs/Point',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.point = kwargs.get('point', Point())

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
        if self.point != other.point:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def point(self):
        """Message field 'point'."""
        return self._point

    @point.setter
    def point(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'point' field must be a sub message of type 'Point'"
        self._point = value


class Metaclass_Cruising(type):
    """Metaclass of service 'Cruising'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('go2_tutorial_inter')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'go2_tutorial_inter.srv.Cruising')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__cruising

            from go2_tutorial_inter.srv import _cruising
            if _cruising.Metaclass_Cruising_Request._TYPE_SUPPORT is None:
                _cruising.Metaclass_Cruising_Request.__import_type_support__()
            if _cruising.Metaclass_Cruising_Response._TYPE_SUPPORT is None:
                _cruising.Metaclass_Cruising_Response.__import_type_support__()


class Cruising(metaclass=Metaclass_Cruising):
    from go2_tutorial_inter.srv._cruising import Cruising_Request as Request
    from go2_tutorial_inter.srv._cruising import Cruising_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
