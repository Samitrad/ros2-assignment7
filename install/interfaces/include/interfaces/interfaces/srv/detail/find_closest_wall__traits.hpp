// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/FindClosestWall.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/srv/detail/find_closest_wall__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const FindClosestWall_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FindClosestWall_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FindClosestWall_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::FindClosestWall_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::FindClosestWall_Request & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::FindClosestWall_Request>()
{
  return "interfaces::srv::FindClosestWall_Request";
}

template<>
inline const char * name<interfaces::srv::FindClosestWall_Request>()
{
  return "interfaces/srv/FindClosestWall_Request";
}

template<>
struct has_fixed_size<interfaces::srv::FindClosestWall_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::FindClosestWall_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::FindClosestWall_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const FindClosestWall_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FindClosestWall_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FindClosestWall_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::FindClosestWall_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::FindClosestWall_Response & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::FindClosestWall_Response>()
{
  return "interfaces::srv::FindClosestWall_Response";
}

template<>
inline const char * name<interfaces::srv::FindClosestWall_Response>()
{
  return "interfaces/srv/FindClosestWall_Response";
}

template<>
struct has_fixed_size<interfaces::srv::FindClosestWall_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::FindClosestWall_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::FindClosestWall_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::FindClosestWall>()
{
  return "interfaces::srv::FindClosestWall";
}

template<>
inline const char * name<interfaces::srv::FindClosestWall>()
{
  return "interfaces/srv/FindClosestWall";
}

template<>
struct has_fixed_size<interfaces::srv::FindClosestWall>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::FindClosestWall_Request>::value &&
    has_fixed_size<interfaces::srv::FindClosestWall_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::FindClosestWall>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::FindClosestWall_Request>::value &&
    has_bounded_size<interfaces::srv::FindClosestWall_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::FindClosestWall>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::FindClosestWall_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::FindClosestWall_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__TRAITS_HPP_
