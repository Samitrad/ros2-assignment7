// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/FindClosestWall.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/find_closest_wall__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::FindClosestWall_Request>()
{
  return ::interfaces::srv::FindClosestWall_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_FindClosestWall_Response_distance
{
public:
  Init_FindClosestWall_Response_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::FindClosestWall_Response distance(::interfaces::srv::FindClosestWall_Response::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::FindClosestWall_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::FindClosestWall_Response>()
{
  return interfaces::srv::builder::Init_FindClosestWall_Response_distance();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__BUILDER_HPP_
