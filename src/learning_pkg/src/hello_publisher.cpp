#include <ros/ros.h>
#include <learning_pkg/Hello.h>




int main(int agrc, char **agrv)
{
	ros::init(agrc,agrv, "hello_publisher");

	ros::NodeHandle n;

	ros::Publisher hello_pub = n.advertise<learning_pkg::Hello>("hello",10);

	ros::Rate loop_rate(10);

	while(ros::ok())
	{
		learning_pkg::Hello hello_msg;
		hello_msg.open = "Hello";

		ROS_INFO("My name is: open:%s",hello_msg.open.c_str());
		loop_rate.sleep();
		
	}
	return 0;











 
}
