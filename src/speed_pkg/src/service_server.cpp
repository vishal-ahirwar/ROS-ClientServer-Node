#include"ros/ros.h"
#include"speed_pkg/OddEvenCheck.h"
bool determineOddEven(speed_pkg::OddEvenCheck::Request&,speed_pkg::OddEvenCheck::Response&);

int main(int argc,char**argv)
{
    ros::init(argc,argv,"OddEvenCheck_service_server");
    ROS_INFO("Odd Even Check Server is running ...");

    ros::NodeHandle service_handle;

    ros::ServiceServer OddEven_Server =service_handle.advertiseService("odd_even_node",determineOddEven);
    ros::spin();
    return 0;

};
bool determineOddEven(speed_pkg::OddEvenCheck::Request& req,speed_pkg::OddEvenCheck::Response& res)
{
    if(req.number%2)
    {
        res.answer =" is ODD";
    }else
    {
        res.answer ="[V]--> Number is Even";

    };

    return true;

}