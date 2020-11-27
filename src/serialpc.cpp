#include<ros/ros.h>
#include<std_msgs/Int16.h>
#include<iostream>

std_msgs::Int16 key_msg;

int commandnum;

ros::Publisher command_pub;

int main(int argc,char **argv){
    ros::init(argc,argv,"pc_side");
    ros::NodeHandle n;
    ros::Rate loop_rate(1000);

    command_pub = n.advertise<std_msgs::Int16>("command",50);

    std::cout << "0 -> emergency command" << std::endl;
    std::cout << "over 0 -> send command and data" << std::endl;
    std::cout << "under 0 -> change the tempo" << std::endl;


    while(ros::ok()){
        std::cin >> commandnum;
        key_msg.data = commandnum;
        command_pub.publish(key_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
