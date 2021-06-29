#include "ros/ros.h"
#include "iostream"
#include <yaml-cpp/yaml.h>

typedef struct
{
    float max_roadwheel_angle;
    float min_roadwheel_angle;
    float min_radius;
    float max_speed;
    float wheel_base;
    float wheel_track;
    float width;
    float length;
    float steer_clearance;
    float steer_offset;
}vehicle_params_t;

vehicle_params_t vehicle_params_;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "yaml_test_node");
    ros::NodeHandle nh_private_("~");
    
//	vehicle_params_.max_roadwheel_angle = nh_private_.param<float>("vehicle/max_roadwheel_angle",0.0);
//	vehicle_params_.min_roadwheel_angle = nh_private_.param<float>("vehicle/min_roadwheel_angle",0.0);
//	vehicle_params_.min_radius          = nh_private_.param<float>("vehicle/min_radius",0.0);
//	vehicle_params_.max_speed = nh_private_.param<float>("vehicle/max_speed",0.0);
//	vehicle_params_.wheel_base = nh_private_.param<float>("vehicle/wheel_base",0.0);
//	vehicle_params_.wheel_track = nh_private_.param<float>("vehicle/wheel_track",0.0);
//	vehicle_params_.width = nh_private_.param<float>("vehicle/width",0.0);
//	vehicle_params_.length = nh_private_.param<float>("vehicle/length",0.0);
//	vehicle_params_.steer_clearance = nh_private_.param<float>("vehicle/steer_clearance",0.0);
//	vehicle_params_.steer_offset = nh_private_.param<float>("vehicle/steer_offset", 0.0);
	
	vehicle_params_.max_roadwheel_angle = nh_private_.param<float>("max_roadwheel_angle",0.0);
	vehicle_params_.min_roadwheel_angle = nh_private_.param<float>("min_roadwheel_angle",0.0);
	vehicle_params_.min_radius          = nh_private_.param<float>("min_radius",0.0);
	vehicle_params_.max_speed = nh_private_.param<float>("max_speed",0.0);
	vehicle_params_.wheel_base = nh_private_.param<float>("wheel_base",0.0);
	vehicle_params_.wheel_track = nh_private_.param<float>("wheel_track",0.0);
	vehicle_params_.width = nh_private_.param<float>("width",0.0);
	vehicle_params_.length = nh_private_.param<float>("length",0.0);
	vehicle_params_.steer_clearance = nh_private_.param<float>("steer_clearance",0.0);
	vehicle_params_.steer_offset = nh_private_.param<float>("steer_offset", 0.0);
	
	std::cout << "max_roadwheel_angle: " << vehicle_params_.max_roadwheel_angle << std::endl;
	
	return 0;
}
