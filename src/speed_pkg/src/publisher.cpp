#include "ros/ros.h"
#include "std_msgs/Float32.h"

#define RPM 120
int main(int argc, char **argv)
{
    ros::init(argc, argv, "rpm_pub_node");
    ros::NodeHandle rpm_handle;
    ros::Publisher rpm_pub = rpm_handle.advertise<std_msgs::Float32>("rpm", 10);
    ros::Rate pub_rate(5);
    ROS_INFO("Publishing RPM ...");

    while (ros::ok())
    {
        std_msgs::Float32 rpm;
        rpm.data = RPM;
        rpm_pub.publish(rpm);
        pub_rate.sleep();
    };

    return 0;
};
