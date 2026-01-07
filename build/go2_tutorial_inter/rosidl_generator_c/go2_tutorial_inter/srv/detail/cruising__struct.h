// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_tutorial_inter:srv/Cruising.idl
// generated code does not contain a copyright notice

#ifndef GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__STRUCT_H_
#define GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/Cruising in the package go2_tutorial_inter.
typedef struct go2_tutorial_inter__srv__Cruising_Request
{
  int32_t flag;
} go2_tutorial_inter__srv__Cruising_Request;

// Struct for a sequence of go2_tutorial_inter__srv__Cruising_Request.
typedef struct go2_tutorial_inter__srv__Cruising_Request__Sequence
{
  go2_tutorial_inter__srv__Cruising_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_tutorial_inter__srv__Cruising_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in srv/Cruising in the package go2_tutorial_inter.
typedef struct go2_tutorial_inter__srv__Cruising_Response
{
  geometry_msgs__msg__Point point;
} go2_tutorial_inter__srv__Cruising_Response;

// Struct for a sequence of go2_tutorial_inter__srv__Cruising_Response.
typedef struct go2_tutorial_inter__srv__Cruising_Response__Sequence
{
  go2_tutorial_inter__srv__Cruising_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_tutorial_inter__srv__Cruising_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__STRUCT_H_
