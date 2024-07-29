// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:srv/FindClosestWall.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__STRUCT_H_
#define INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/FindClosestWall in the package interfaces.
typedef struct interfaces__srv__FindClosestWall_Request
{
  uint8_t structure_needs_at_least_one_member;
} interfaces__srv__FindClosestWall_Request;

// Struct for a sequence of interfaces__srv__FindClosestWall_Request.
typedef struct interfaces__srv__FindClosestWall_Request__Sequence
{
  interfaces__srv__FindClosestWall_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__FindClosestWall_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/FindClosestWall in the package interfaces.
typedef struct interfaces__srv__FindClosestWall_Response
{
  double distance;
} interfaces__srv__FindClosestWall_Response;

// Struct for a sequence of interfaces__srv__FindClosestWall_Response.
typedef struct interfaces__srv__FindClosestWall_Response__Sequence
{
  interfaces__srv__FindClosestWall_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__FindClosestWall_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__STRUCT_H_
