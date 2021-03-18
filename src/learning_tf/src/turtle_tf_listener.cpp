#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_listener");
  ros::NodeHandle node;

  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv;
  add_turtle.call(srv);

  ros::Publisher turtle_vel = node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);

  tf::TransformListener listener;					//创建监听器对象;开始接收tf转换

  ros::Rate rate(10.0);
  while (node.ok()){
    tf::StampedTransform transform;
    try{
    	 ros::Time now = ros::Time::now();
    	listener.waitForTransform("/turtle2", "/turtle1",
                               now, ros::Duration(5.0));  		//每个监听器有一个缓冲区，它存储来自不同tf广播者的所有坐标变换。 当广播者发出变换时，变换进入缓冲区之前需要一些时间（通常是几个毫秒）。 因此，当您在时间“now”请求坐标系变换时，您应该等待几毫秒以获得该信息
        listener.lookupTransform("/turtle2", "/turtle1",
                               now, transform);	//从turtle2坐标系开始转换到turtle1坐标系;变换的时间，提供ros::Time(0)即会给出最近的可用的变换;结果存放的变换对象
//      listener.lookupTransform("/turtle2", "/carrot1",
//                               ros::Time(0), transform);
		}
    
    
    catch (tf::TransformException &ex) {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }

    geometry_msgs::Twist vel_msg;
    vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(),
                                    transform.getOrigin().x());
    vel_msg.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
                                  pow(transform.getOrigin().y(), 2));
    turtle_vel.publish(vel_msg);
	//变换用于计算龟的新的线性和角速度，基于它与龟的距离和角度。
	//新的速度发布在话题"turtle2/cmd_vel"中，turtlesim将使用它来更新turtle2的运动
    rate.sleep();
  }
  return 0;
}
