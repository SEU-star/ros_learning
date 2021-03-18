#include <ros/ros.h>
#include <tf/transform_broadcaster.h>     					//tf包提供了TransformBroadcaster的实现,以帮助发布变换更加容易
#include <turtlesim/Pose.h>

std::string turtle_name;

void poseCallback(const turtlesim::PoseConstPtr& msg)
{
  static tf::TransformBroadcaster br;						//创建了一个TransformBroadcaster对象,基于它通过线路发送转换
  tf::Transform transform;									//创建了一个transform对象,并将信息从2D乌龟姿势复制到3D变换中(定义存放转换信息的变量)
  transform.setOrigin( tf::Vector3(msg->x, msg->y, 0.0) );	//求得变换矩阵中的t(假设是要发布一个子坐标系为”turtle1”父坐标系为“world”，那么其中(msg->x,msg->y,0.0)是指“turtle1”的坐标原点在“world”坐标系下的坐标。)
  tf::Quaternion q;
  q.setRPY(0, 0, msg->theta);
  transform.setRotation(q);									//设施旋转
  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
  //使用TransformBroadcaster发送需要四个参数:1.传递转换本身	
  										   //2.给发布的变换给一个时间戳	
  										   //3.传递父框架的名称(父坐标系)
  										   //4.需要传递的(子坐标系名字
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "my_tf_broadcaster"); 
  if (argc != 2)
  {
  	ROS_ERROR("need turtle name as argument"); 
  	return -1;
  }
  turtle_name = argv[1];

  ros::NodeHandle node;
  ros::Subscriber sub = node.subscribe(turtle_name+"/pose", 10, &poseCallback);

  ros::spin();
  return 0;
}
