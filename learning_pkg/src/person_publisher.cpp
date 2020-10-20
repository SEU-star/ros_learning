
#include <ros/ros.h>
#include "learning_pkg/Person.h"

int main(int agrc, char **agrv)
{
	//ros节点初始化
	ros::init(agrc, agrv,"person_publisher");

	//创建节点句柄
	ros::NodeHandle n;

	//创建一个Publisher，发布名字为/turtle1/cmd_vel的topic,消息类型为:geometry_msgs::Twist队列长度为10;
	ros::Publisher person_info_pub = n.advertise<learning_pkg::Person>("/person_info",10);
	
	//设置循环频率
	ros::Rate loop_rate(10);


	while (ros::ok())
	{
		//初始化geometry_msgs::Twist类型的消息
		learning_pkg::Person person_msg;
		person_msg.sex = learning_pkg::Person::male;
		person_msg.name = "star";
		person_msg.age = 18;

		//发布消息
		person_info_pub.publish(person_msg);

		ROS_INFO("Publish Person info: name:%s  age:%d  sex:%d",person_msg.name.c_str(),person_msg.age,person_msg.sex);
		
		//按照循环频率延时
		loop_rate.sleep();
	
	}
	return 0;
}
