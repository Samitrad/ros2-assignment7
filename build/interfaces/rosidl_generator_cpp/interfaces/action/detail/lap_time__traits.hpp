// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:action/LapTime.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__ACTION__DETAIL__LAP_TIME__TRAITS_HPP_
#define INTERFACES__ACTION__DETAIL__LAP_TIME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/action/detail/lap_time__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const LapTime_Goal & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LapTime_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LapTime_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::LapTime_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::LapTime_Goal & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::LapTime_Goal>()
{
  return "interfaces::action::LapTime_Goal";
}

template<>
inline const char * name<interfaces::action::LapTime_Goal>()
{
  return "interfaces/action/LapTime_Goal";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::action::LapTime_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::action::LapTime_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const LapTime_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: total_time
  {
    out << "total_time: ";
    rosidl_generator_traits::value_to_yaml(msg.total_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LapTime_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: total_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_time: ";
    rosidl_generator_traits::value_to_yaml(msg.total_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LapTime_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::LapTime_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::LapTime_Result & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::LapTime_Result>()
{
  return "interfaces::action::LapTime_Result";
}

template<>
inline const char * name<interfaces::action::LapTime_Result>()
{
  return "interfaces/action/LapTime_Result";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::action::LapTime_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::action::LapTime_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const LapTime_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: elapsed_time
  {
    out << "elapsed_time: ";
    rosidl_generator_traits::value_to_yaml(msg.elapsed_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LapTime_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: elapsed_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elapsed_time: ";
    rosidl_generator_traits::value_to_yaml(msg.elapsed_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LapTime_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::LapTime_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::LapTime_Feedback & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::LapTime_Feedback>()
{
  return "interfaces::action::LapTime_Feedback";
}

template<>
inline const char * name<interfaces::action::LapTime_Feedback>()
{
  return "interfaces/action/LapTime_Feedback";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::action::LapTime_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::action::LapTime_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "interfaces/action/detail/lap_time__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const LapTime_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LapTime_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LapTime_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::LapTime_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::LapTime_SendGoal_Request & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::LapTime_SendGoal_Request>()
{
  return "interfaces::action::LapTime_SendGoal_Request";
}

template<>
inline const char * name<interfaces::action::LapTime_SendGoal_Request>()
{
  return "interfaces/action/LapTime_SendGoal_Request";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<interfaces::action::LapTime_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<interfaces::action::LapTime_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<interfaces::action::LapTime_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<interfaces::action::LapTime_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const LapTime_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LapTime_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LapTime_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::LapTime_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::LapTime_SendGoal_Response & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::LapTime_SendGoal_Response>()
{
  return "interfaces::action::LapTime_SendGoal_Response";
}

template<>
inline const char * name<interfaces::action::LapTime_SendGoal_Response>()
{
  return "interfaces/action/LapTime_SendGoal_Response";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<interfaces::action::LapTime_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<interfaces::action::LapTime_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::LapTime_SendGoal>()
{
  return "interfaces::action::LapTime_SendGoal";
}

template<>
inline const char * name<interfaces::action::LapTime_SendGoal>()
{
  return "interfaces/action/LapTime_SendGoal";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::action::LapTime_SendGoal_Request>::value &&
    has_fixed_size<interfaces::action::LapTime_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::action::LapTime_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::action::LapTime_SendGoal_Request>::value &&
    has_bounded_size<interfaces::action::LapTime_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<interfaces::action::LapTime_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::action::LapTime_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::action::LapTime_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const LapTime_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LapTime_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LapTime_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::LapTime_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::LapTime_GetResult_Request & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::LapTime_GetResult_Request>()
{
  return "interfaces::action::LapTime_GetResult_Request";
}

template<>
inline const char * name<interfaces::action::LapTime_GetResult_Request>()
{
  return "interfaces/action/LapTime_GetResult_Request";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<interfaces::action::LapTime_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<interfaces::action::LapTime_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "interfaces/action/detail/lap_time__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const LapTime_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LapTime_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LapTime_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::LapTime_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::LapTime_GetResult_Response & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::LapTime_GetResult_Response>()
{
  return "interfaces::action::LapTime_GetResult_Response";
}

template<>
inline const char * name<interfaces::action::LapTime_GetResult_Response>()
{
  return "interfaces/action/LapTime_GetResult_Response";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<interfaces::action::LapTime_Result>::value> {};

template<>
struct has_bounded_size<interfaces::action::LapTime_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<interfaces::action::LapTime_Result>::value> {};

template<>
struct is_message<interfaces::action::LapTime_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::LapTime_GetResult>()
{
  return "interfaces::action::LapTime_GetResult";
}

template<>
inline const char * name<interfaces::action::LapTime_GetResult>()
{
  return "interfaces/action/LapTime_GetResult";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::action::LapTime_GetResult_Request>::value &&
    has_fixed_size<interfaces::action::LapTime_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::action::LapTime_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::action::LapTime_GetResult_Request>::value &&
    has_bounded_size<interfaces::action::LapTime_GetResult_Response>::value
  >
{
};

template<>
struct is_service<interfaces::action::LapTime_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::action::LapTime_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::action::LapTime_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "interfaces/action/detail/lap_time__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const LapTime_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LapTime_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LapTime_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::LapTime_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::LapTime_FeedbackMessage & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::LapTime_FeedbackMessage>()
{
  return "interfaces::action::LapTime_FeedbackMessage";
}

template<>
inline const char * name<interfaces::action::LapTime_FeedbackMessage>()
{
  return "interfaces/action/LapTime_FeedbackMessage";
}

template<>
struct has_fixed_size<interfaces::action::LapTime_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<interfaces::action::LapTime_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<interfaces::action::LapTime_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<interfaces::action::LapTime_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<interfaces::action::LapTime_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<interfaces::action::LapTime>
  : std::true_type
{
};

template<>
struct is_action_goal<interfaces::action::LapTime_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<interfaces::action::LapTime_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<interfaces::action::LapTime_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // INTERFACES__ACTION__DETAIL__LAP_TIME__TRAITS_HPP_
