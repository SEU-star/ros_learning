#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;//创建一个TransformBroadcaster对象,后面用这个发送base_link到base_laser的转换

  while(n.ok()){
    broadcaster.sendTransform(
    tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.2)),
        ros::Time::now(),"base_link", "base_laser"));
    r.sleep();
  }
}
/*****************************************
首先，我们传递旋转变换，它由Quaternion指定，用于需要在两个坐标系之间发生的任何旋转。在这种情况下，我们希望应用无旋转，因此，我们在一个发送Quaternion从俯仰，滚动和偏航值等于零构成。
其次，Vector3任何我们想申请转换。然而，我们想要应用平移，因此我们创建一个Vector3，其对应于激光器的x偏移10cm和距离机器人基座20cm的z偏移。
第三，我们需要给正在发布的变换发送时间戳，我们将使用ros::Time::now()。
第四，我们需要传递我们正在创建的链接的父节点的名称，在这种情况下为“base_link”。
第五，我们需要传递我们正在创建的链接的子节点的名称，在本例中为“base_laser”。
*****************************************/
