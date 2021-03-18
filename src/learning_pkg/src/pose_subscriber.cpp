#include <ros/ros.h>
#include "turtlesim/Pose.h"

//接收到订阅的消息后，会进入回调函数

void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
	//接收的消息打印出来
	ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x, msg->y);

}

int main(int argc, char **argv)
{
	//初始化ROS节点
	ros::init(argc, argv, "pose_subscriber");

	//创建节点句柄 管理节点
	ros::NodeHandle n;


	//创建一个subscriber，订阅名为：/turtle1/pose话题，队列长度为10;回调函数
        ros::Subscriber pose_sub = n.subscribe("/turtle1/pose",10,poseCallback);

	//循环的等待回调函数不断查看是否有消息进来，有的话就进入回调函数
	ros::spin();

	return 0;
	
}
