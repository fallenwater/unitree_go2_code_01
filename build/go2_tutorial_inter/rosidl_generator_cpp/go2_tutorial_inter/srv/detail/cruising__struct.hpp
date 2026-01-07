// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from go2_tutorial_inter:srv/Cruising.idl
// generated code does not contain a copyright notice

#ifndef GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__STRUCT_HPP_
#define GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__go2_tutorial_inter__srv__Cruising_Request __attribute__((deprecated))
#else
# define DEPRECATED__go2_tutorial_inter__srv__Cruising_Request __declspec(deprecated)
#endif

namespace go2_tutorial_inter
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Cruising_Request_
{
  using Type = Cruising_Request_<ContainerAllocator>;

  explicit Cruising_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = 0l;
    }
  }

  explicit Cruising_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = 0l;
    }
  }

  // field types and members
  using _flag_type =
    int32_t;
  _flag_type flag;

  // setters for named parameter idiom
  Type & set__flag(
    const int32_t & _arg)
  {
    this->flag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__go2_tutorial_inter__srv__Cruising_Request
    std::shared_ptr<go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__go2_tutorial_inter__srv__Cruising_Request
    std::shared_ptr<go2_tutorial_inter::srv::Cruising_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Cruising_Request_ & other) const
  {
    if (this->flag != other.flag) {
      return false;
    }
    return true;
  }
  bool operator!=(const Cruising_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Cruising_Request_

// alias to use template instance with default allocator
using Cruising_Request =
  go2_tutorial_inter::srv::Cruising_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace go2_tutorial_inter


// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__go2_tutorial_inter__srv__Cruising_Response __attribute__((deprecated))
#else
# define DEPRECATED__go2_tutorial_inter__srv__Cruising_Response __declspec(deprecated)
#endif

namespace go2_tutorial_inter
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Cruising_Response_
{
  using Type = Cruising_Response_<ContainerAllocator>;

  explicit Cruising_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_init)
  {
    (void)_init;
  }

  explicit Cruising_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _point_type point;

  // setters for named parameter idiom
  Type & set__point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__go2_tutorial_inter__srv__Cruising_Response
    std::shared_ptr<go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__go2_tutorial_inter__srv__Cruising_Response
    std::shared_ptr<go2_tutorial_inter::srv::Cruising_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Cruising_Response_ & other) const
  {
    if (this->point != other.point) {
      return false;
    }
    return true;
  }
  bool operator!=(const Cruising_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Cruising_Response_

// alias to use template instance with default allocator
using Cruising_Response =
  go2_tutorial_inter::srv::Cruising_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace go2_tutorial_inter

namespace go2_tutorial_inter
{

namespace srv
{

struct Cruising
{
  using Request = go2_tutorial_inter::srv::Cruising_Request;
  using Response = go2_tutorial_inter::srv::Cruising_Response;
};

}  // namespace srv

}  // namespace go2_tutorial_inter

#endif  // GO2_TUTORIAL_INTER__SRV__DETAIL__CRUISING__STRUCT_HPP_
