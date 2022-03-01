#include"ros/ros.h"
#include"speed_pkg/OddEvenCheck.h"
#include<iostream>
int main(int argc,char**argv)
{
    ros::init(argc,argv,"odd_even_client_node");
    ros::NodeHandle client_handle;
    ros::ServiceClient client =client_handle.serviceClient<speed_pkg::OddEvenCheck>("odd_even_check");
    speed_pkg::OddEvenCheck odd_even_check_srv;

    unsigned long long int input_num{};
    std::cout<<"Type '0' to quit program!\n";

    while(ros::ok())
    {
        std::cout<<"Enter Number ..";
        std::cin>>input_num;
        odd_even_check_srv.request.number =input_num;
        if(input_num==0)
        {
            ROS_INFO("Quiting Application ....");
            return 0;
        };
        if(client.call(odd_even_check_srv))
        {
            std::string res{odd_even_check_srv.response.answer};
            std::cout<<res<<"\n...\n";

        }else
        {
            ROS_ERROR("OddEvenCheck Service Call failed!");
            return -1;
        };

        std::cin.clear();


    }
}