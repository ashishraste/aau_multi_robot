/*
Publish a message indicating charging is complete.
(explore controller will wait for this before resuming exploration,
and voltage_simulate will indicate full charge once it receives this.)
*/
#include <ros/ros.h>
#include <std_msgs/Empty.h>
using namespace std;
int main(int argc, char** argv) {
	ROS_INFO("Charge_signal launching...");
	ros::init(argc, argv, "charge_signal");
	ros::NodeHandle n;
	ros::Publisher charge_pub = n.advertise<std_msgs::Empty>("charge_complete", 1000);
	std_msgs::Empty empty_msg;
	ros::Rate loop_rate(0.004);
	while ( ros::ok() ) {
		charge_pub.publish(empty_msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
