#include <ros/ros.h>
#include "learning_pkg/Person.h"

//接收到订阅的消息后，会进入回调函数

void personInfoCallback(const learning_pkg::Person::ConstPtr& msg)
{
	//接收的消息打印出来
	ROS_INFO("Person Info: name:%s, age:%d, sex:%d", msg->name.c_str(),msg->age,msg->sex);

}

int main(int argc, char **argv)
{
	//初始化ROS节点
	ros::init(argc, argv, "person_subscriber");

	//创建节点句柄 管理节点
	ros::NodeHandle n;


	//创建一个subscriber，订阅名为：/turtle1/pose话题，队列长度为10;回调函数
        ros::Subscriber person_sub = n.subscribe("/person_info",10,personInfoCallback);

	//循环的等待回调函数不断查看是否有消息进来，有的话就进入回调函数
	ros::spin();

	return 0;
	
}
