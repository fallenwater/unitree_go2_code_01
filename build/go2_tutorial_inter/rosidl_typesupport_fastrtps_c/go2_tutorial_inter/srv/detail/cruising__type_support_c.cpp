// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from go2_tutorial_inter:srv/Cruising.idl
// generated code does not contain a copyright notice
#include "go2_tutorial_inter/srv/detail/cruising__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "go2_tutorial_inter/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "go2_tutorial_inter/srv/detail/cruising__struct.h"
#include "go2_tutorial_inter/srv/detail/cruising__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Cruising_Request__ros_msg_type = go2_tutorial_inter__srv__Cruising_Request;

static bool _Cruising_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Cruising_Request__ros_msg_type * ros_message = static_cast<const _Cruising_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: flag
  {
    cdr << ros_message->flag;
  }

  return true;
}

static bool _Cruising_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Cruising_Request__ros_msg_type * ros_message = static_cast<_Cruising_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: flag
  {
    cdr >> ros_message->flag;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_go2_tutorial_inter
size_t get_serialized_size_go2_tutorial_inter__srv__Cruising_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Cruising_Request__ros_msg_type * ros_message = static_cast<const _Cruising_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name flag
  {
    size_t item_size = sizeof(ros_message->flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Cruising_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_go2_tutorial_inter__srv__Cruising_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_go2_tutorial_inter
size_t max_serialized_size_go2_tutorial_inter__srv__Cruising_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: flag
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Cruising_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_go2_tutorial_inter__srv__Cruising_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Cruising_Request = {
  "go2_tutorial_inter::srv",
  "Cruising_Request",
  _Cruising_Request__cdr_serialize,
  _Cruising_Request__cdr_deserialize,
  _Cruising_Request__get_serialized_size,
  _Cruising_Request__max_serialized_size
};

static rosidl_message_type_support_t _Cruising_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Cruising_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, go2_tutorial_inter, srv, Cruising_Request)() {
  return &_Cruising_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "go2_tutorial_inter/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "go2_tutorial_inter/srv/detail/cruising__struct.h"
// already included above
// #include "go2_tutorial_inter/srv/detail/cruising__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/point__functions.h"  // point

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_go2_tutorial_inter
size_t get_serialized_size_geometry_msgs__msg__Point(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_go2_tutorial_inter
size_t max_serialized_size_geometry_msgs__msg__Point(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_go2_tutorial_inter
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point)();


using _Cruising_Response__ros_msg_type = go2_tutorial_inter__srv__Cruising_Response;

static bool _Cruising_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Cruising_Response__ros_msg_type * ros_message = static_cast<const _Cruising_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: point
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->point, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Cruising_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Cruising_Response__ros_msg_type * ros_message = static_cast<_Cruising_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: point
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->point))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_go2_tutorial_inter
size_t get_serialized_size_go2_tutorial_inter__srv__Cruising_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Cruising_Response__ros_msg_type * ros_message = static_cast<const _Cruising_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name point

  current_alignment += get_serialized_size_geometry_msgs__msg__Point(
    &(ros_message->point), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Cruising_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_go2_tutorial_inter__srv__Cruising_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_go2_tutorial_inter
size_t max_serialized_size_go2_tutorial_inter__srv__Cruising_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: point
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Cruising_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_go2_tutorial_inter__srv__Cruising_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Cruising_Response = {
  "go2_tutorial_inter::srv",
  "Cruising_Response",
  _Cruising_Response__cdr_serialize,
  _Cruising_Response__cdr_deserialize,
  _Cruising_Response__get_serialized_size,
  _Cruising_Response__max_serialized_size
};

static rosidl_message_type_support_t _Cruising_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Cruising_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, go2_tutorial_inter, srv, Cruising_Response)() {
  return &_Cruising_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "go2_tutorial_inter/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "go2_tutorial_inter/srv/cruising.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Cruising__callbacks = {
  "go2_tutorial_inter::srv",
  "Cruising",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, go2_tutorial_inter, srv, Cruising_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, go2_tutorial_inter, srv, Cruising_Response)(),
};

static rosidl_service_type_support_t Cruising__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Cruising__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, go2_tutorial_inter, srv, Cruising)() {
  return &Cruising__handle;
}

#if defined(__cplusplus)
}
#endif
