#include "ros/ros.h"
#include "std_msgs/Float32.h"
// #define WHEEL_RADIUS 12.5 / 100 // centimeters to -->> meter
#define PI 3.14285714286
float WHEEL_RADIUS;
void speed(const std_msgs::Float32 &rpm);
ros::Publisher speed_pub;
int main(int argc, char **argv)
{
    ros::init(argc, argv, "speed_sub_node");
    ROS_INFO("Speed Subscriber Node ....");
    ros::NodeHandle sub_handle;
    speed_pub = sub_handle.advertise<std_msgs::Float32>("speed", 10);
    ros::Subscriber speed_sub = sub_handle.subscribe("rpm", 10, speed);
    ros::spin();
    return 0;
};
void speed(const std_msgs::Float32 &rpm)
{
    ros::NodeHandle sub_callback_node_handle;
    std_msgs::Float32 __speed;
    if (sub_callback_node_handle.getParam("wheel_radius", WHEEL_RADIUS))
    {
        // __speed.data = WHEEL_RADIUS;
        __speed.data = ((2 * WHEEL_RADIUS * PI) + (rpm.data / 60));
        speed_pub.publish(__speed);
    }
    else
    {
        ROS_WARN("[V]--->WHEEL RADIUS NOT SET!");
    };
};
