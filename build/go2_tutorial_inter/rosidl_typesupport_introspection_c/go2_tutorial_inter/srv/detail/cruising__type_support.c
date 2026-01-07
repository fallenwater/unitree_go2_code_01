// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from go2_tutorial_inter:srv/Cruising.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "go2_tutorial_inter/srv/detail/cruising__rosidl_typesupport_introspection_c.h"
#include "go2_tutorial_inter/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "go2_tutorial_inter/srv/detail/cruising__functions.h"
#include "go2_tutorial_inter/srv/detail/cruising__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  go2_tutorial_inter__srv__Cruising_Request__init(message_memory);
}

void Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_fini_function(void * message_memory)
{
  go2_tutorial_inter__srv__Cruising_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_message_member_array[1] = {
  {
    "flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_tutorial_inter__srv__Cruising_Request, flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_message_members = {
  "go2_tutorial_inter__srv",  // message namespace
  "Cruising_Request",  // message name
  1,  // number of fields
  sizeof(go2_tutorial_inter__srv__Cruising_Request),
  Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_message_member_array,  // message members
  Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_message_type_support_handle = {
  0,
  &Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_go2_tutorial_inter
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_tutorial_inter, srv, Cruising_Request)() {
  if (!Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_message_type_support_handle.typesupport_identifier) {
    Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Cruising_Request__rosidl_typesupport_introspection_c__Cruising_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "go2_tutorial_inter/srv/detail/cruising__rosidl_typesupport_introspection_c.h"
// already included above
// #include "go2_tutorial_inter/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "go2_tutorial_inter/srv/detail/cruising__functions.h"
// already included above
// #include "go2_tutorial_inter/srv/detail/cruising__struct.h"


// Include directives for member types
// Member `point`
#include "geometry_msgs/msg/point.h"
// Member `point`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  go2_tutorial_inter__srv__Cruising_Response__init(message_memory);
}

void Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_fini_function(void * message_memory)
{
  go2_tutorial_inter__srv__Cruising_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_message_member_array[1] = {
  {
    "point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_tutorial_inter__srv__Cruising_Response, point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_message_members = {
  "go2_tutorial_inter__srv",  // message namespace
  "Cruising_Response",  // message name
  1,  // number of fields
  sizeof(go2_tutorial_inter__srv__Cruising_Response),
  Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_message_member_array,  // message members
  Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_message_type_support_handle = {
  0,
  &Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_go2_tutorial_inter
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_tutorial_inter, srv, Cruising_Response)() {
  Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_message_type_support_handle.typesupport_identifier) {
    Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Cruising_Response__rosidl_typesupport_introspection_c__Cruising_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "go2_tutorial_inter/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "go2_tutorial_inter/srv/detail/cruising__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers go2_tutorial_inter__srv__detail__cruising__rosidl_typesupport_introspection_c__Cruising_service_members = {
  "go2_tutorial_inter__srv",  // service namespace
  "Cruising",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // go2_tutorial_inter__srv__detail__cruising__rosidl_typesupport_introspection_c__Cruising_Request_message_type_support_handle,
  NULL  // response message
  // go2_tutorial_inter__srv__detail__cruising__rosidl_typesupport_introspection_c__Cruising_Response_message_type_support_handle
};

static rosidl_service_type_support_t go2_tutorial_inter__srv__detail__cruising__rosidl_typesupport_introspection_c__Cruising_service_type_support_handle = {
  0,
  &go2_tutorial_inter__srv__detail__cruising__rosidl_typesupport_introspection_c__Cruising_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_tutorial_inter, srv, Cruising_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_tutorial_inter, srv, Cruising_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_go2_tutorial_inter
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_tutorial_inter, srv, Cruising)() {
  if (!go2_tutorial_inter__srv__detail__cruising__rosidl_typesupport_introspection_c__Cruising_service_type_support_handle.typesupport_identifier) {
    go2_tutorial_inter__srv__detail__cruising__rosidl_typesupport_introspection_c__Cruising_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)go2_tutorial_inter__srv__detail__cruising__rosidl_typesupport_introspection_c__Cruising_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_tutorial_inter, srv, Cruising_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_tutorial_inter, srv, Cruising_Response)()->data;
  }

  return &go2_tutorial_inter__srv__detail__cruising__rosidl_typesupport_introspection_c__Cruising_service_type_support_handle;
}
