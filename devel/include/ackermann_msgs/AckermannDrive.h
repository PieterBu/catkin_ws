// Generated by gencpp from file ackermann_msgs/AckermannDrive.msg
// DO NOT EDIT!


#ifndef ACKERMANN_MSGS_MESSAGE_ACKERMANNDRIVE_H
#define ACKERMANN_MSGS_MESSAGE_ACKERMANNDRIVE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ackermann_msgs
{
template <class ContainerAllocator>
struct AckermannDrive_
{
  typedef AckermannDrive_<ContainerAllocator> Type;

  AckermannDrive_()
    : steering_angle(0.0)
    , steering_angle_velocity(0.0)
    , speed(0.0)
    , acceleration(0.0)
    , jerk(0.0)  {
    }
  AckermannDrive_(const ContainerAllocator& _alloc)
    : steering_angle(0.0)
    , steering_angle_velocity(0.0)
    , speed(0.0)
    , acceleration(0.0)
    , jerk(0.0)  {
    }



   typedef float _steering_angle_type;
  _steering_angle_type steering_angle;

   typedef float _steering_angle_velocity_type;
  _steering_angle_velocity_type steering_angle_velocity;

   typedef float _speed_type;
  _speed_type speed;

   typedef float _acceleration_type;
  _acceleration_type acceleration;

   typedef float _jerk_type;
  _jerk_type jerk;




  typedef boost::shared_ptr< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> const> ConstPtr;

}; // struct AckermannDrive_

typedef ::ackermann_msgs::AckermannDrive_<std::allocator<void> > AckermannDrive;

typedef boost::shared_ptr< ::ackermann_msgs::AckermannDrive > AckermannDrivePtr;
typedef boost::shared_ptr< ::ackermann_msgs::AckermannDrive const> AckermannDriveConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ackermann_msgs::AckermannDrive_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ackermann_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'ackermann_msgs': ['/home/pieter/catkin_ws/src/tas_car/simulation/ackermann_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3512e91b48d69674a0e86fadf1ea8231";
  }

  static const char* value(const ::ackermann_msgs::AckermannDrive_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3512e91b48d69674ULL;
  static const uint64_t static_value2 = 0xa0e86fadf1ea8231ULL;
};

template<class ContainerAllocator>
struct DataType< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ackermann_msgs/AckermannDrive";
  }

  static const char* value(const ::ackermann_msgs::AckermannDrive_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> >
{
  static const char* value()
  {
    return "## Driving command for a car-like vehicle using Ackermann steering.\n\
#  $Id$\n\
\n\
# Assumes Ackermann front-wheel steering. The left and right front\n\
# wheels are generally at different angles. To simplify, the commanded\n\
# angle corresponds to the yaw of a virtual wheel located at the\n\
# center of the front axle, like on a tricycle.  Positive yaw is to\n\
# the left. (This is *not* the angle of the steering wheel inside the\n\
# passenger compartment.)\n\
#\n\
# Zero steering angle velocity means change the steering angle as\n\
# quickly as possible. Positive velocity indicates a desired absolute\n\
# rate of change either left or right. The controller tries not to\n\
# exceed this limit in either direction, but sometimes it might.\n\
#\n\
float32 steering_angle          # desired virtual angle (radians)\n\
float32 steering_angle_velocity # desired rate of change (radians/s)\n\
\n\
# Drive at requested speed, acceleration and jerk (the 1st, 2nd and\n\
# 3rd derivatives of position). All are measured at the vehicle's\n\
# center of rotation, typically the center of the rear axle. The\n\
# controller tries not to exceed these limits in either direction, but\n\
# sometimes it might.\n\
#\n\
# Speed is the desired scalar magnitude of the velocity vector.\n\
# Direction is forward unless the sign is negative, indicating reverse.\n\
#\n\
# Zero acceleration means change speed as quickly as\n\
# possible. Positive acceleration indicates a desired absolute\n\
# magnitude; that includes deceleration.\n\
#\n\
# Zero jerk means change acceleration as quickly as possible. Positive\n\
# jerk indicates a desired absolute rate of acceleration change in\n\
# either direction (increasing or decreasing).\n\
#\n\
float32 speed                   # desired forward speed (m/s)\n\
float32 acceleration            # desired acceleration (m/s^2)\n\
float32 jerk                    # desired jerk (m/s^3)\n\
";
  }

  static const char* value(const ::ackermann_msgs::AckermannDrive_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.steering_angle);
      stream.next(m.steering_angle_velocity);
      stream.next(m.speed);
      stream.next(m.acceleration);
      stream.next(m.jerk);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct AckermannDrive_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ackermann_msgs::AckermannDrive_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ackermann_msgs::AckermannDrive_<ContainerAllocator>& v)
  {
    s << indent << "steering_angle: ";
    Printer<float>::stream(s, indent + "  ", v.steering_angle);
    s << indent << "steering_angle_velocity: ";
    Printer<float>::stream(s, indent + "  ", v.steering_angle_velocity);
    s << indent << "speed: ";
    Printer<float>::stream(s, indent + "  ", v.speed);
    s << indent << "acceleration: ";
    Printer<float>::stream(s, indent + "  ", v.acceleration);
    s << indent << "jerk: ";
    Printer<float>::stream(s, indent + "  ", v.jerk);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ACKERMANN_MSGS_MESSAGE_ACKERMANNDRIVE_H
