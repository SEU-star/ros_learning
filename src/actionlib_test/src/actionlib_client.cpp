#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include "actionlib_test/DoDishesAction.h"

typedef actionlib::SimpleActionClient<actionlib_test::DoDishesAction> DoDishesClient;

// 当action完成后，最后会调用此回调函数1次
void doneCb(const actionlib::SimpleClientGoalState& state,
            const actionlib_test::DoDishesResultConstPtr& result)
{
    ROS_INFO("Yay! The dishes are now clean");
    ros::shutdown();
}
 
// 当action激活后，最开始会调用此回调函数1次
void activeCb()
{
    ROS_INFO("Goal just went active");
}
 
// 收到feedback后调用的回调函数，在不停执行action
void feedbackCb(const actionlib_test::DoDishesFeedbackConstPtr& feedback)
{
    ROS_INFO(" percent_complete : %f ", feedback->percent_complete);
}
 
int main(int argc, char** argv)
{
    ros::init(argc, argv, "do_dishes_client");
    
    // 定义一个客户端
    DoDishesClient client("/do_dishes", true);
    
    // 等待服务器端
    ROS_INFO("Waiting for action server to start.");
    client.waitForServer();
    
    ROS_INFO("Action server started, sending goal.");
    // 创建一个action的goal
    actionlib_test::DoDishesGoal goal;
    goal.dishwasher_id = 1;
 
    // 发送action的goal给服务器端，并且设置回调函数
    client.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);
    client.waitForResult();//返回action最后的结果
    std::cout << "State: " << client.getState().toString() << std::endl;
    ros::spin();
    
    return 0;
}
