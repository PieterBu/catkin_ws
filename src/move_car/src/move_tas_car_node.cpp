#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseStamped.h"


class Car{

	public:

	float pose_x;
	float pose_y;
	float pose_z;

	float orient_x;
	float orient_y;
	float orient_z;
	float orient_w;

	void callBackGetPosition(const geometry_msgs::PoseWithCovarianceStamped& positon);
};

void Car::callBackGetPosition(const geometry_msgs::PoseWithCovarianceStamped& position){
    pose_x= position.pose.pose.position.x;
    pose_y= position.pose.pose.position.y;
    pose_z= position.pose.pose.position.z;

    orient_x= position.pose.pose.orientation.x;
    orient_y= position.pose.pose.orientation.y;
    orient_z= position.pose.pose.orientation.z;
    orient_w= position.pose.pose.orientation.w;

    ROS_INFO("x [%f]", pose_x);
}

int main(int argc, char** argv){

    ros::init(argc, argv, "move_tas_car_node");
    ros::NodeHandle n;

    Car my_car;
    geometry_msgs::PoseStamped goal;

    ros::Publisher  move_car= n.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal", 1);
    ros::Subscriber pose_car= n.subscribe("amcl_pose", 1, &Car::callBackGetPosition, &my_car);
    goal.pose.position.x= my_car.pose_x+1;

    move_car.publish(goal);

    ros::spin();
    return 0;
}
