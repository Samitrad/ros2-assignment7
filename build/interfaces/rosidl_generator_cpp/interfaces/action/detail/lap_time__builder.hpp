// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:action/LapTime.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__ACTION__DETAIL__LAP_TIME__BUILDER_HPP_
#define INTERFACES__ACTION__DETAIL__LAP_TIME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/action/detail/lap_time__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::LapTime_Goal>()
{
  return ::interfaces::action::LapTime_Goal(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_LapTime_Result_total_time
{
public:
  Init_LapTime_Result_total_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::LapTime_Result total_time(::interfaces::action::LapTime_Result::_total_time_type arg)
  {
    msg_.total_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::LapTime_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::LapTime_Result>()
{
  return interfaces::action::builder::Init_LapTime_Result_total_time();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_LapTime_Feedback_elapsed_time
{
public:
  Init_LapTime_Feedback_elapsed_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::LapTime_Feedback elapsed_time(::interfaces::action::LapTime_Feedback::_elapsed_time_type arg)
  {
    msg_.elapsed_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::LapTime_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::LapTime_Feedback>()
{
  return interfaces::action::builder::Init_LapTime_Feedback_elapsed_time();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_LapTime_SendGoal_Request_goal
{
public:
  explicit Init_LapTime_SendGoal_Request_goal(::interfaces::action::LapTime_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::action::LapTime_SendGoal_Request goal(::interfaces::action::LapTime_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::LapTime_SendGoal_Request msg_;
};

class Init_LapTime_SendGoal_Request_goal_id
{
public:
  Init_LapTime_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LapTime_SendGoal_Request_goal goal_id(::interfaces::action::LapTime_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_LapTime_SendGoal_Request_goal(msg_);
  }

private:
  ::interfaces::action::LapTime_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::LapTime_SendGoal_Request>()
{
  return interfaces::action::builder::Init_LapTime_SendGoal_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_LapTime_SendGoal_Response_stamp
{
public:
  explicit Init_LapTime_SendGoal_Response_stamp(::interfaces::action::LapTime_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::LapTime_SendGoal_Response stamp(::interfaces::action::LapTime_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::LapTime_SendGoal_Response msg_;
};

class Init_LapTime_SendGoal_Response_accepted
{
public:
  Init_LapTime_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LapTime_SendGoal_Response_stamp accepted(::interfaces::action::LapTime_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_LapTime_SendGoal_Response_stamp(msg_);
  }

private:
  ::interfaces::action::LapTime_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::LapTime_SendGoal_Response>()
{
  return interfaces::action::builder::Init_LapTime_SendGoal_Response_accepted();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_LapTime_GetResult_Request_goal_id
{
public:
  Init_LapTime_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::LapTime_GetResult_Request goal_id(::interfaces::action::LapTime_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::LapTime_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::LapTime_GetResult_Request>()
{
  return interfaces::action::builder::Init_LapTime_GetResult_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_LapTime_GetResult_Response_result
{
public:
  explicit Init_LapTime_GetResult_Response_result(::interfaces::action::LapTime_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::LapTime_GetResult_Response result(::interfaces::action::LapTime_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::LapTime_GetResult_Response msg_;
};

class Init_LapTime_GetResult_Response_status
{
public:
  Init_LapTime_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LapTime_GetResult_Response_result status(::interfaces::action::LapTime_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_LapTime_GetResult_Response_result(msg_);
  }

private:
  ::interfaces::action::LapTime_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::LapTime_GetResult_Response>()
{
  return interfaces::action::builder::Init_LapTime_GetResult_Response_status();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_LapTime_FeedbackMessage_feedback
{
public:
  explicit Init_LapTime_FeedbackMessage_feedback(::interfaces::action::LapTime_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::interfaces::action::LapTime_FeedbackMessage feedback(::interfaces::action::LapTime_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::LapTime_FeedbackMessage msg_;
};

class Init_LapTime_FeedbackMessage_goal_id
{
public:
  Init_LapTime_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LapTime_FeedbackMessage_feedback goal_id(::interfaces::action::LapTime_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_LapTime_FeedbackMessage_feedback(msg_);
  }

private:
  ::interfaces::action::LapTime_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::LapTime_FeedbackMessage>()
{
  return interfaces::action::builder::Init_LapTime_FeedbackMessage_goal_id();
}

}  // namespace interfaces

#endif  // INTERFACES__ACTION__DETAIL__LAP_TIME__BUILDER_HPP_
