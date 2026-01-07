// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from go2_tutorial_inter:action/Nav.idl
// generated code does not contain a copyright notice
#include "go2_tutorial_inter/action/detail/nav__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
go2_tutorial_inter__action__Nav_Goal__init(go2_tutorial_inter__action__Nav_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // goal
  return true;
}

void
go2_tutorial_inter__action__Nav_Goal__fini(go2_tutorial_inter__action__Nav_Goal * msg)
{
  if (!msg) {
    return;
  }
  // goal
}

bool
go2_tutorial_inter__action__Nav_Goal__are_equal(const go2_tutorial_inter__action__Nav_Goal * lhs, const go2_tutorial_inter__action__Nav_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal
  if (lhs->goal != rhs->goal) {
    return false;
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_Goal__copy(
  const go2_tutorial_inter__action__Nav_Goal * input,
  go2_tutorial_inter__action__Nav_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // goal
  output->goal = input->goal;
  return true;
}

go2_tutorial_inter__action__Nav_Goal *
go2_tutorial_inter__action__Nav_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_Goal * msg = (go2_tutorial_inter__action__Nav_Goal *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_tutorial_inter__action__Nav_Goal));
  bool success = go2_tutorial_inter__action__Nav_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_tutorial_inter__action__Nav_Goal__destroy(go2_tutorial_inter__action__Nav_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_tutorial_inter__action__Nav_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_tutorial_inter__action__Nav_Goal__Sequence__init(go2_tutorial_inter__action__Nav_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_Goal * data = NULL;

  if (size) {
    data = (go2_tutorial_inter__action__Nav_Goal *)allocator.zero_allocate(size, sizeof(go2_tutorial_inter__action__Nav_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_tutorial_inter__action__Nav_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_tutorial_inter__action__Nav_Goal__fini(&data[i - 1]);
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
go2_tutorial_inter__action__Nav_Goal__Sequence__fini(go2_tutorial_inter__action__Nav_Goal__Sequence * array)
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
      go2_tutorial_inter__action__Nav_Goal__fini(&array->data[i]);
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

go2_tutorial_inter__action__Nav_Goal__Sequence *
go2_tutorial_inter__action__Nav_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_Goal__Sequence * array = (go2_tutorial_inter__action__Nav_Goal__Sequence *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_tutorial_inter__action__Nav_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_tutorial_inter__action__Nav_Goal__Sequence__destroy(go2_tutorial_inter__action__Nav_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_tutorial_inter__action__Nav_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_tutorial_inter__action__Nav_Goal__Sequence__are_equal(const go2_tutorial_inter__action__Nav_Goal__Sequence * lhs, const go2_tutorial_inter__action__Nav_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_Goal__Sequence__copy(
  const go2_tutorial_inter__action__Nav_Goal__Sequence * input,
  go2_tutorial_inter__action__Nav_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_tutorial_inter__action__Nav_Goal);
    go2_tutorial_inter__action__Nav_Goal * data =
      (go2_tutorial_inter__action__Nav_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_tutorial_inter__action__Nav_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          go2_tutorial_inter__action__Nav_Goal__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `point`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
go2_tutorial_inter__action__Nav_Result__init(go2_tutorial_inter__action__Nav_Result * msg)
{
  if (!msg) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__init(&msg->point)) {
    go2_tutorial_inter__action__Nav_Result__fini(msg);
    return false;
  }
  return true;
}

void
go2_tutorial_inter__action__Nav_Result__fini(go2_tutorial_inter__action__Nav_Result * msg)
{
  if (!msg) {
    return;
  }
  // point
  geometry_msgs__msg__Point__fini(&msg->point);
}

bool
go2_tutorial_inter__action__Nav_Result__are_equal(const go2_tutorial_inter__action__Nav_Result * lhs, const go2_tutorial_inter__action__Nav_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_Result__copy(
  const go2_tutorial_inter__action__Nav_Result * input,
  go2_tutorial_inter__action__Nav_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  return true;
}

go2_tutorial_inter__action__Nav_Result *
go2_tutorial_inter__action__Nav_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_Result * msg = (go2_tutorial_inter__action__Nav_Result *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_tutorial_inter__action__Nav_Result));
  bool success = go2_tutorial_inter__action__Nav_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_tutorial_inter__action__Nav_Result__destroy(go2_tutorial_inter__action__Nav_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_tutorial_inter__action__Nav_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_tutorial_inter__action__Nav_Result__Sequence__init(go2_tutorial_inter__action__Nav_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_Result * data = NULL;

  if (size) {
    data = (go2_tutorial_inter__action__Nav_Result *)allocator.zero_allocate(size, sizeof(go2_tutorial_inter__action__Nav_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_tutorial_inter__action__Nav_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_tutorial_inter__action__Nav_Result__fini(&data[i - 1]);
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
go2_tutorial_inter__action__Nav_Result__Sequence__fini(go2_tutorial_inter__action__Nav_Result__Sequence * array)
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
      go2_tutorial_inter__action__Nav_Result__fini(&array->data[i]);
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

go2_tutorial_inter__action__Nav_Result__Sequence *
go2_tutorial_inter__action__Nav_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_Result__Sequence * array = (go2_tutorial_inter__action__Nav_Result__Sequence *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_tutorial_inter__action__Nav_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_tutorial_inter__action__Nav_Result__Sequence__destroy(go2_tutorial_inter__action__Nav_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_tutorial_inter__action__Nav_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_tutorial_inter__action__Nav_Result__Sequence__are_equal(const go2_tutorial_inter__action__Nav_Result__Sequence * lhs, const go2_tutorial_inter__action__Nav_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_Result__Sequence__copy(
  const go2_tutorial_inter__action__Nav_Result__Sequence * input,
  go2_tutorial_inter__action__Nav_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_tutorial_inter__action__Nav_Result);
    go2_tutorial_inter__action__Nav_Result * data =
      (go2_tutorial_inter__action__Nav_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_tutorial_inter__action__Nav_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          go2_tutorial_inter__action__Nav_Result__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
go2_tutorial_inter__action__Nav_Feedback__init(go2_tutorial_inter__action__Nav_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // distance
  return true;
}

void
go2_tutorial_inter__action__Nav_Feedback__fini(go2_tutorial_inter__action__Nav_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // distance
}

bool
go2_tutorial_inter__action__Nav_Feedback__are_equal(const go2_tutorial_inter__action__Nav_Feedback * lhs, const go2_tutorial_inter__action__Nav_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_Feedback__copy(
  const go2_tutorial_inter__action__Nav_Feedback * input,
  go2_tutorial_inter__action__Nav_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // distance
  output->distance = input->distance;
  return true;
}

go2_tutorial_inter__action__Nav_Feedback *
go2_tutorial_inter__action__Nav_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_Feedback * msg = (go2_tutorial_inter__action__Nav_Feedback *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_tutorial_inter__action__Nav_Feedback));
  bool success = go2_tutorial_inter__action__Nav_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_tutorial_inter__action__Nav_Feedback__destroy(go2_tutorial_inter__action__Nav_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_tutorial_inter__action__Nav_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_tutorial_inter__action__Nav_Feedback__Sequence__init(go2_tutorial_inter__action__Nav_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_Feedback * data = NULL;

  if (size) {
    data = (go2_tutorial_inter__action__Nav_Feedback *)allocator.zero_allocate(size, sizeof(go2_tutorial_inter__action__Nav_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_tutorial_inter__action__Nav_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_tutorial_inter__action__Nav_Feedback__fini(&data[i - 1]);
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
go2_tutorial_inter__action__Nav_Feedback__Sequence__fini(go2_tutorial_inter__action__Nav_Feedback__Sequence * array)
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
      go2_tutorial_inter__action__Nav_Feedback__fini(&array->data[i]);
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

go2_tutorial_inter__action__Nav_Feedback__Sequence *
go2_tutorial_inter__action__Nav_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_Feedback__Sequence * array = (go2_tutorial_inter__action__Nav_Feedback__Sequence *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_tutorial_inter__action__Nav_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_tutorial_inter__action__Nav_Feedback__Sequence__destroy(go2_tutorial_inter__action__Nav_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_tutorial_inter__action__Nav_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_tutorial_inter__action__Nav_Feedback__Sequence__are_equal(const go2_tutorial_inter__action__Nav_Feedback__Sequence * lhs, const go2_tutorial_inter__action__Nav_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_Feedback__Sequence__copy(
  const go2_tutorial_inter__action__Nav_Feedback__Sequence * input,
  go2_tutorial_inter__action__Nav_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_tutorial_inter__action__Nav_Feedback);
    go2_tutorial_inter__action__Nav_Feedback * data =
      (go2_tutorial_inter__action__Nav_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_tutorial_inter__action__Nav_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          go2_tutorial_inter__action__Nav_Feedback__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "go2_tutorial_inter/action/detail/nav__functions.h"

bool
go2_tutorial_inter__action__Nav_SendGoal_Request__init(go2_tutorial_inter__action__Nav_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    go2_tutorial_inter__action__Nav_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!go2_tutorial_inter__action__Nav_Goal__init(&msg->goal)) {
    go2_tutorial_inter__action__Nav_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
go2_tutorial_inter__action__Nav_SendGoal_Request__fini(go2_tutorial_inter__action__Nav_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  go2_tutorial_inter__action__Nav_Goal__fini(&msg->goal);
}

bool
go2_tutorial_inter__action__Nav_SendGoal_Request__are_equal(const go2_tutorial_inter__action__Nav_SendGoal_Request * lhs, const go2_tutorial_inter__action__Nav_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!go2_tutorial_inter__action__Nav_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_SendGoal_Request__copy(
  const go2_tutorial_inter__action__Nav_SendGoal_Request * input,
  go2_tutorial_inter__action__Nav_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!go2_tutorial_inter__action__Nav_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

go2_tutorial_inter__action__Nav_SendGoal_Request *
go2_tutorial_inter__action__Nav_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_SendGoal_Request * msg = (go2_tutorial_inter__action__Nav_SendGoal_Request *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_tutorial_inter__action__Nav_SendGoal_Request));
  bool success = go2_tutorial_inter__action__Nav_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_tutorial_inter__action__Nav_SendGoal_Request__destroy(go2_tutorial_inter__action__Nav_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_tutorial_inter__action__Nav_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence__init(go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_SendGoal_Request * data = NULL;

  if (size) {
    data = (go2_tutorial_inter__action__Nav_SendGoal_Request *)allocator.zero_allocate(size, sizeof(go2_tutorial_inter__action__Nav_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_tutorial_inter__action__Nav_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_tutorial_inter__action__Nav_SendGoal_Request__fini(&data[i - 1]);
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
go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence__fini(go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence * array)
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
      go2_tutorial_inter__action__Nav_SendGoal_Request__fini(&array->data[i]);
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

go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence *
go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence * array = (go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence__destroy(go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence__are_equal(const go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence * lhs, const go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence__copy(
  const go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence * input,
  go2_tutorial_inter__action__Nav_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_tutorial_inter__action__Nav_SendGoal_Request);
    go2_tutorial_inter__action__Nav_SendGoal_Request * data =
      (go2_tutorial_inter__action__Nav_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_tutorial_inter__action__Nav_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          go2_tutorial_inter__action__Nav_SendGoal_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
go2_tutorial_inter__action__Nav_SendGoal_Response__init(go2_tutorial_inter__action__Nav_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    go2_tutorial_inter__action__Nav_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
go2_tutorial_inter__action__Nav_SendGoal_Response__fini(go2_tutorial_inter__action__Nav_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
go2_tutorial_inter__action__Nav_SendGoal_Response__are_equal(const go2_tutorial_inter__action__Nav_SendGoal_Response * lhs, const go2_tutorial_inter__action__Nav_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_SendGoal_Response__copy(
  const go2_tutorial_inter__action__Nav_SendGoal_Response * input,
  go2_tutorial_inter__action__Nav_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

go2_tutorial_inter__action__Nav_SendGoal_Response *
go2_tutorial_inter__action__Nav_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_SendGoal_Response * msg = (go2_tutorial_inter__action__Nav_SendGoal_Response *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_tutorial_inter__action__Nav_SendGoal_Response));
  bool success = go2_tutorial_inter__action__Nav_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_tutorial_inter__action__Nav_SendGoal_Response__destroy(go2_tutorial_inter__action__Nav_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_tutorial_inter__action__Nav_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence__init(go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_SendGoal_Response * data = NULL;

  if (size) {
    data = (go2_tutorial_inter__action__Nav_SendGoal_Response *)allocator.zero_allocate(size, sizeof(go2_tutorial_inter__action__Nav_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_tutorial_inter__action__Nav_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_tutorial_inter__action__Nav_SendGoal_Response__fini(&data[i - 1]);
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
go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence__fini(go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence * array)
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
      go2_tutorial_inter__action__Nav_SendGoal_Response__fini(&array->data[i]);
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

go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence *
go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence * array = (go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence__destroy(go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence__are_equal(const go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence * lhs, const go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence__copy(
  const go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence * input,
  go2_tutorial_inter__action__Nav_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_tutorial_inter__action__Nav_SendGoal_Response);
    go2_tutorial_inter__action__Nav_SendGoal_Response * data =
      (go2_tutorial_inter__action__Nav_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_tutorial_inter__action__Nav_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          go2_tutorial_inter__action__Nav_SendGoal_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
go2_tutorial_inter__action__Nav_GetResult_Request__init(go2_tutorial_inter__action__Nav_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    go2_tutorial_inter__action__Nav_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
go2_tutorial_inter__action__Nav_GetResult_Request__fini(go2_tutorial_inter__action__Nav_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
go2_tutorial_inter__action__Nav_GetResult_Request__are_equal(const go2_tutorial_inter__action__Nav_GetResult_Request * lhs, const go2_tutorial_inter__action__Nav_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_GetResult_Request__copy(
  const go2_tutorial_inter__action__Nav_GetResult_Request * input,
  go2_tutorial_inter__action__Nav_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

go2_tutorial_inter__action__Nav_GetResult_Request *
go2_tutorial_inter__action__Nav_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_GetResult_Request * msg = (go2_tutorial_inter__action__Nav_GetResult_Request *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_tutorial_inter__action__Nav_GetResult_Request));
  bool success = go2_tutorial_inter__action__Nav_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_tutorial_inter__action__Nav_GetResult_Request__destroy(go2_tutorial_inter__action__Nav_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_tutorial_inter__action__Nav_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_tutorial_inter__action__Nav_GetResult_Request__Sequence__init(go2_tutorial_inter__action__Nav_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_GetResult_Request * data = NULL;

  if (size) {
    data = (go2_tutorial_inter__action__Nav_GetResult_Request *)allocator.zero_allocate(size, sizeof(go2_tutorial_inter__action__Nav_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_tutorial_inter__action__Nav_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_tutorial_inter__action__Nav_GetResult_Request__fini(&data[i - 1]);
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
go2_tutorial_inter__action__Nav_GetResult_Request__Sequence__fini(go2_tutorial_inter__action__Nav_GetResult_Request__Sequence * array)
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
      go2_tutorial_inter__action__Nav_GetResult_Request__fini(&array->data[i]);
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

go2_tutorial_inter__action__Nav_GetResult_Request__Sequence *
go2_tutorial_inter__action__Nav_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_GetResult_Request__Sequence * array = (go2_tutorial_inter__action__Nav_GetResult_Request__Sequence *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_tutorial_inter__action__Nav_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_tutorial_inter__action__Nav_GetResult_Request__Sequence__destroy(go2_tutorial_inter__action__Nav_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_tutorial_inter__action__Nav_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_tutorial_inter__action__Nav_GetResult_Request__Sequence__are_equal(const go2_tutorial_inter__action__Nav_GetResult_Request__Sequence * lhs, const go2_tutorial_inter__action__Nav_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_GetResult_Request__Sequence__copy(
  const go2_tutorial_inter__action__Nav_GetResult_Request__Sequence * input,
  go2_tutorial_inter__action__Nav_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_tutorial_inter__action__Nav_GetResult_Request);
    go2_tutorial_inter__action__Nav_GetResult_Request * data =
      (go2_tutorial_inter__action__Nav_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_tutorial_inter__action__Nav_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          go2_tutorial_inter__action__Nav_GetResult_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "go2_tutorial_inter/action/detail/nav__functions.h"

bool
go2_tutorial_inter__action__Nav_GetResult_Response__init(go2_tutorial_inter__action__Nav_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!go2_tutorial_inter__action__Nav_Result__init(&msg->result)) {
    go2_tutorial_inter__action__Nav_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
go2_tutorial_inter__action__Nav_GetResult_Response__fini(go2_tutorial_inter__action__Nav_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  go2_tutorial_inter__action__Nav_Result__fini(&msg->result);
}

bool
go2_tutorial_inter__action__Nav_GetResult_Response__are_equal(const go2_tutorial_inter__action__Nav_GetResult_Response * lhs, const go2_tutorial_inter__action__Nav_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!go2_tutorial_inter__action__Nav_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_GetResult_Response__copy(
  const go2_tutorial_inter__action__Nav_GetResult_Response * input,
  go2_tutorial_inter__action__Nav_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!go2_tutorial_inter__action__Nav_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

go2_tutorial_inter__action__Nav_GetResult_Response *
go2_tutorial_inter__action__Nav_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_GetResult_Response * msg = (go2_tutorial_inter__action__Nav_GetResult_Response *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_tutorial_inter__action__Nav_GetResult_Response));
  bool success = go2_tutorial_inter__action__Nav_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_tutorial_inter__action__Nav_GetResult_Response__destroy(go2_tutorial_inter__action__Nav_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_tutorial_inter__action__Nav_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_tutorial_inter__action__Nav_GetResult_Response__Sequence__init(go2_tutorial_inter__action__Nav_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_GetResult_Response * data = NULL;

  if (size) {
    data = (go2_tutorial_inter__action__Nav_GetResult_Response *)allocator.zero_allocate(size, sizeof(go2_tutorial_inter__action__Nav_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_tutorial_inter__action__Nav_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_tutorial_inter__action__Nav_GetResult_Response__fini(&data[i - 1]);
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
go2_tutorial_inter__action__Nav_GetResult_Response__Sequence__fini(go2_tutorial_inter__action__Nav_GetResult_Response__Sequence * array)
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
      go2_tutorial_inter__action__Nav_GetResult_Response__fini(&array->data[i]);
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

go2_tutorial_inter__action__Nav_GetResult_Response__Sequence *
go2_tutorial_inter__action__Nav_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_GetResult_Response__Sequence * array = (go2_tutorial_inter__action__Nav_GetResult_Response__Sequence *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_tutorial_inter__action__Nav_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_tutorial_inter__action__Nav_GetResult_Response__Sequence__destroy(go2_tutorial_inter__action__Nav_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_tutorial_inter__action__Nav_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_tutorial_inter__action__Nav_GetResult_Response__Sequence__are_equal(const go2_tutorial_inter__action__Nav_GetResult_Response__Sequence * lhs, const go2_tutorial_inter__action__Nav_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_GetResult_Response__Sequence__copy(
  const go2_tutorial_inter__action__Nav_GetResult_Response__Sequence * input,
  go2_tutorial_inter__action__Nav_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_tutorial_inter__action__Nav_GetResult_Response);
    go2_tutorial_inter__action__Nav_GetResult_Response * data =
      (go2_tutorial_inter__action__Nav_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_tutorial_inter__action__Nav_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          go2_tutorial_inter__action__Nav_GetResult_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "go2_tutorial_inter/action/detail/nav__functions.h"

bool
go2_tutorial_inter__action__Nav_FeedbackMessage__init(go2_tutorial_inter__action__Nav_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    go2_tutorial_inter__action__Nav_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!go2_tutorial_inter__action__Nav_Feedback__init(&msg->feedback)) {
    go2_tutorial_inter__action__Nav_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
go2_tutorial_inter__action__Nav_FeedbackMessage__fini(go2_tutorial_inter__action__Nav_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  go2_tutorial_inter__action__Nav_Feedback__fini(&msg->feedback);
}

bool
go2_tutorial_inter__action__Nav_FeedbackMessage__are_equal(const go2_tutorial_inter__action__Nav_FeedbackMessage * lhs, const go2_tutorial_inter__action__Nav_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!go2_tutorial_inter__action__Nav_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_FeedbackMessage__copy(
  const go2_tutorial_inter__action__Nav_FeedbackMessage * input,
  go2_tutorial_inter__action__Nav_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!go2_tutorial_inter__action__Nav_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

go2_tutorial_inter__action__Nav_FeedbackMessage *
go2_tutorial_inter__action__Nav_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_FeedbackMessage * msg = (go2_tutorial_inter__action__Nav_FeedbackMessage *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_tutorial_inter__action__Nav_FeedbackMessage));
  bool success = go2_tutorial_inter__action__Nav_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_tutorial_inter__action__Nav_FeedbackMessage__destroy(go2_tutorial_inter__action__Nav_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_tutorial_inter__action__Nav_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence__init(go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_FeedbackMessage * data = NULL;

  if (size) {
    data = (go2_tutorial_inter__action__Nav_FeedbackMessage *)allocator.zero_allocate(size, sizeof(go2_tutorial_inter__action__Nav_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_tutorial_inter__action__Nav_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_tutorial_inter__action__Nav_FeedbackMessage__fini(&data[i - 1]);
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
go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence__fini(go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence * array)
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
      go2_tutorial_inter__action__Nav_FeedbackMessage__fini(&array->data[i]);
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

go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence *
go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence * array = (go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence *)allocator.allocate(sizeof(go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence__destroy(go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence__are_equal(const go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence * lhs, const go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence__copy(
  const go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence * input,
  go2_tutorial_inter__action__Nav_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_tutorial_inter__action__Nav_FeedbackMessage);
    go2_tutorial_inter__action__Nav_FeedbackMessage * data =
      (go2_tutorial_inter__action__Nav_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_tutorial_inter__action__Nav_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          go2_tutorial_inter__action__Nav_FeedbackMessage__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_tutorial_inter__action__Nav_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
