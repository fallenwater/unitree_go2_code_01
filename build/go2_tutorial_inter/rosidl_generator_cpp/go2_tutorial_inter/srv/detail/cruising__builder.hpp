// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_tutorial_inter:srv/Cruising.idl
// generated code does not contain a copyright notice

#ifndef GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__BUILDER_HPP_
#define GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__BUILDER_HPP_

#include "go2_tutorial_inter/srv/detail/cruising__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace go2_tutorial_inter
{

namespace srv
{

namespace builder
{

class Init_Cruising_Request_flag
{
public:
  Init_Cruising_Request_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::go2_tutorial_inter::srv::Cruising_Request flag(::go2_tutorial_inter::srv::Cruising_Request::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::srv::Cruising_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::srv::Cruising_Request>()
{
  return go2_tutorial_inter::srv::builder::Init_Cruising_Request_flag();
}

}  // namespace go2_tutorial_inter


namespace go2_tutorial_inter
{

namespace srv
{

namespace builder
{

class Init_Cruising_Response_point
{
public:
  Init_Cruising_Response_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::go2_tutorial_inter::srv::Cruising_Response point(::go2_tutorial_inter::srv::Cruising_Response::_point_type arg)
  {
    msg_.point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_tutorial_inter::srv::Cruising_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_tutorial_inter::srv::Cruising_Response>()
{
  return go2_tutorial_inter::srv::builder::Init_Cruising_Response_point();
}

}  // namespace go2_tutorial_inter

#endif  // GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__BUILDER_HPP_
