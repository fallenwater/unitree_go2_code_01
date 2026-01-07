// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_tutorial_inter:action/Nav.idl
// generated code does not contain a copyright notice

#ifndef GO2_TUTORIAL_INTER__ACTION__DETAIL__NAV__BUILDER_HPP_
#define GO2_TUTORIAL_INTER__ACTION__DETAIL__NAV__BUILDER_HPP_

#include "go2_tutorial_inter/action/detail/nav__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace go2_tutorial_inter
{

namespace action
{

namespace builder
{

class Init_Nav_Goal_goal
{
public:
  Init_Nav_Goal_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::go2_tutorial_inter::action::Nav_Goal goal(::go2_tutorial_inter::action::Nav_Goal::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::action::Nav_Goal>()
{
  return go2_tutorial_inter::action::builder::Init_Nav_Goal_goal();
}

}  // namespace go2_tutorial_inter


namespace go2_tutorial_inter
{

namespace action
{

namespace builder
{

class Init_Nav_Result_point
{
public:
  Init_Nav_Result_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::go2_tutorial_inter::action::Nav_Result point(::go2_tutorial_inter::action::Nav_Result::_point_type arg)
  {
    msg_.point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::action::Nav_Result>()
{
  return go2_tutorial_inter::action::builder::Init_Nav_Result_point();
}

}  // namespace go2_tutorial_inter


namespace go2_tutorial_inter
{

namespace action
{

namespace builder
{

class Init_Nav_Feedback_distance
{
public:
  Init_Nav_Feedback_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::go2_tutorial_inter::action::Nav_Feedback distance(::go2_tutorial_inter::action::Nav_Feedback::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::action::Nav_Feedback>()
{
  return go2_tutorial_inter::action::builder::Init_Nav_Feedback_distance();
}

}  // namespace go2_tutorial_inter


namespace go2_tutorial_inter
{

namespace action
{

namespace builder
{

class Init_Nav_SendGoal_Request_goal
{
public:
  explicit Init_Nav_SendGoal_Request_goal(::go2_tutorial_inter::action::Nav_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::go2_tutorial_inter::action::Nav_SendGoal_Request goal(::go2_tutorial_inter::action::Nav_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_SendGoal_Request msg_;
};

class Init_Nav_SendGoal_Request_goal_id
{
public:
  Init_Nav_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Nav_SendGoal_Request_goal goal_id(::go2_tutorial_inter::action::Nav_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Nav_SendGoal_Request_goal(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::action::Nav_SendGoal_Request>()
{
  return go2_tutorial_inter::action::builder::Init_Nav_SendGoal_Request_goal_id();
}

}  // namespace go2_tutorial_inter


namespace go2_tutorial_inter
{

namespace action
{

namespace builder
{

class Init_Nav_SendGoal_Response_stamp
{
public:
  explicit Init_Nav_SendGoal_Response_stamp(::go2_tutorial_inter::action::Nav_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::go2_tutorial_inter::action::Nav_SendGoal_Response stamp(::go2_tutorial_inter::action::Nav_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_SendGoal_Response msg_;
};

class Init_Nav_SendGoal_Response_accepted
{
public:
  Init_Nav_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Nav_SendGoal_Response_stamp accepted(::go2_tutorial_inter::action::Nav_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Nav_SendGoal_Response_stamp(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::action::Nav_SendGoal_Response>()
{
  return go2_tutorial_inter::action::builder::Init_Nav_SendGoal_Response_accepted();
}

}  // namespace go2_tutorial_inter


namespace go2_tutorial_inter
{

namespace action
{

namespace builder
{

class Init_Nav_GetResult_Request_goal_id
{
public:
  Init_Nav_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::go2_tutorial_inter::action::Nav_GetResult_Request goal_id(::go2_tutorial_inter::action::Nav_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::action::Nav_GetResult_Request>()
{
  return go2_tutorial_inter::action::builder::Init_Nav_GetResult_Request_goal_id();
}

}  // namespace go2_tutorial_inter


namespace go2_tutorial_inter
{

namespace action
{

namespace builder
{

class Init_Nav_GetResult_Response_result
{
public:
  explicit Init_Nav_GetResult_Response_result(::go2_tutorial_inter::action::Nav_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::go2_tutorial_inter::action::Nav_GetResult_Response result(::go2_tutorial_inter::action::Nav_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_GetResult_Response msg_;
};

class Init_Nav_GetResult_Response_status
{
public:
  Init_Nav_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Nav_GetResult_Response_result status(::go2_tutorial_inter::action::Nav_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Nav_GetResult_Response_result(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::action::Nav_GetResult_Response>()
{
  return go2_tutorial_inter::action::builder::Init_Nav_GetResult_Response_status();
}

}  // namespace go2_tutorial_inter


namespace go2_tutorial_inter
{

namespace action
{

namespace builder
{

class Init_Nav_FeedbackMessage_feedback
{
public:
  explicit Init_Nav_FeedbackMessage_feedback(::go2_tutorial_inter::action::Nav_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::go2_tutorial_inter::action::Nav_FeedbackMessage feedback(::go2_tutorial_inter::action::Nav_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_FeedbackMessage msg_;
};

class Init_Nav_FeedbackMessage_goal_id
{
public:
  Init_Nav_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Nav_FeedbackMessage_feedback goal_id(::go2_tutorial_inter::action::Nav_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Nav_FeedbackMessage_feedback(msg_);
  }

private:
  ::go2_tutorial_inter::action::Nav_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::action::Nav_FeedbackMessage>()
{
  return go2_tutorial_inter::action::builder::Init_Nav_FeedbackMessage_goal_id();
}

}  // namespace go2_tutorial_inter

#endif  // GO2_TUTORIAL_INTER__ACTION__DETAIL__NAV__BUILDER_HPP_
