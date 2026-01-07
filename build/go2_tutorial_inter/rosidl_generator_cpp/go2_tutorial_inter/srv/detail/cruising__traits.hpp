// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from go2_tutorial_inter:srv/Cruising.idl
// generated code does not contain a copyright notice

#ifndef GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__TRAITS_HPP_
#define GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__TRAITS_HPP_

#include "go2_tutorial_inter/srv/detail/cruising__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<go2_tutorial_inter::srv::Cruising_Request>()
{
  return "go2_tutorial_inter::srv::Cruising_Request";
}

template<>
inline const char * name<go2_tutorial_inter::srv::Cruising_Request>()
{
  return "go2_tutorial_inter/srv/Cruising_Request";
}

template<>
struct has_fixed_size<go2_tutorial_inter::srv::Cruising_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<go2_tutorial_inter::srv::Cruising_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<go2_tutorial_inter::srv::Cruising_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<go2_tutorial_inter::srv::Cruising_Response>()
{
  return "go2_tutorial_inter::srv::Cruising_Response";
}

template<>
inline const char * name<go2_tutorial_inter::srv::Cruising_Response>()
{
  return "go2_tutorial_inter/srv/Cruising_Response";
}

template<>
struct has_fixed_size<go2_tutorial_inter::srv::Cruising_Response>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<go2_tutorial_inter::srv::Cruising_Response>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<go2_tutorial_inter::srv::Cruising_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<go2_tutorial_inter::srv::Cruising>()
{
  return "go2_tutorial_inter::srv::Cruising";
}

template<>
inline const char * name<go2_tutorial_inter::srv::Cruising>()
{
  return "go2_tutorial_inter/srv/Cruising";
}

template<>
struct has_fixed_size<go2_tutorial_inter::srv::Cruising>
  : std::integral_constant<
    bool,
    has_fixed_size<go2_tutorial_inter::srv::Cruising_Request>::value &&
    has_fixed_size<go2_tutorial_inter::srv::Cruising_Response>::value
  >
{
};

template<>
struct has_bounded_size<go2_tutorial_inter::srv::Cruising>
  : std::integral_constant<
    bool,
    has_bounded_size<go2_tutorial_inter::srv::Cruising_Request>::value &&
    has_bounded_size<go2_tutorial_inter::srv::Cruising_Response>::value
  >
{
};

template<>
struct is_service<go2_tutorial_inter::srv::Cruising>
  : std::true_type
{
};

template<>
struct is_service_request<go2_tutorial_inter::srv::Cruising_Request>
  : std::true_type
{
};

template<>
struct is_service_response<go2_tutorial_inter::srv::Cruising_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__TRAITS_HPP_
