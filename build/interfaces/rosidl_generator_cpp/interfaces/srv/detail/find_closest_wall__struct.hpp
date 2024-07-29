// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/FindClosestWall.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__FindClosestWall_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__FindClosestWall_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindClosestWall_Request_
{
  using Type = FindClosestWall_Request_<ContainerAllocator>;

  explicit FindClosestWall_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit FindClosestWall_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::FindClosestWall_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::FindClosestWall_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::FindClosestWall_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::FindClosestWall_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FindClosestWall_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FindClosestWall_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FindClosestWall_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FindClosestWall_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::FindClosestWall_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::FindClosestWall_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__FindClosestWall_Request
    std::shared_ptr<interfaces::srv::FindClosestWall_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__FindClosestWall_Request
    std::shared_ptr<interfaces::srv::FindClosestWall_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindClosestWall_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindClosestWall_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindClosestWall_Request_

// alias to use template instance with default allocator
using FindClosestWall_Request =
  interfaces::srv::FindClosestWall_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__FindClosestWall_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__FindClosestWall_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FindClosestWall_Response_
{
  using Type = FindClosestWall_Response_<ContainerAllocator>;

  explicit FindClosestWall_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
    }
  }

  explicit FindClosestWall_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
    }
  }

  // field types and members
  using _distance_type =
    double;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::FindClosestWall_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::FindClosestWall_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::FindClosestWall_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::FindClosestWall_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FindClosestWall_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FindClosestWall_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::FindClosestWall_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::FindClosestWall_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::FindClosestWall_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::FindClosestWall_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__FindClosestWall_Response
    std::shared_ptr<interfaces::srv::FindClosestWall_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__FindClosestWall_Response
    std::shared_ptr<interfaces::srv::FindClosestWall_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindClosestWall_Response_ & other) const
  {
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindClosestWall_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindClosestWall_Response_

// alias to use template instance with default allocator
using FindClosestWall_Response =
  interfaces::srv::FindClosestWall_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct FindClosestWall
{
  using Request = interfaces::srv::FindClosestWall_Request;
  using Response = interfaces::srv::FindClosestWall_Response;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__FIND_CLOSEST_WALL__STRUCT_HPP_
