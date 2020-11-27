#include<ros/ros.h>
#include<std_msgs/Int16.h>
#include<iostream>

std_msgs::Int16 key_msg;

int commandnum;

ros::Publisher command_pub;


void timer_callback(const ros::TimerEvent& e){
    key_msg.data = 100;
    command_pub.publish(key_msg);
}

int main(int argc,char **argv){
    std::cout << "start" << std::endl;
    ros::init(argc,argv,"tusin_check");
    ros::NodeHandle n;
    ros::Rate loop_rate(1000);

    command_pub = n.advertise<std_msgs::Int16>("command",50);

    ros::Timer timer = n.createTimer(ros::Duration(0.1),timer_callback);

    while(ros::ok()){
        ros::spinOnce();
        loop_rate.sleep();
    }
}
