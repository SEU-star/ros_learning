#coding=utf-8
#!/usr/bin/env python    

import roslib;roslib.load_manifest('learning_tf')  
import rospy  
import tf  
import turtlesim.msg  

def handle_turtle_pose(msg, turtlename):  
    br = tf.TransformBroadcaster()  #创建一个TransformBroadcaster对象
    br.sendTransform((msg.x, msg.y, 0),  
                     tf.transformations.quaternion_from_euler(0, 0, msg.theta),  
                     rospy.Time.now(),  
                     turtlename,  
                     "world")  #发布乌龟的平移和翻转  

if __name__ == '__main__':  
    rospy.init_node('turtle_tf_broadcaster')  
    turtlename = rospy.get_param('~turtle')   #获取海龟的名字（turtle1，turtle2）  
    rospy.Subscriber('/%s/pose' % turtlename,  
                     turtlesim.msg.Pose,  
                     handle_turtle_pose,  
                     turtlename)   #订阅 topic "turtleX/pose"  
    rospy.spin()

