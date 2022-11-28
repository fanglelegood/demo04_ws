#include "ros/ros.h"
#include "turtlesim/Spawn.h"

//1.包含头文件
//2.初始化ROS节点
//3.创建节点句柄
//4.创建客户端对象
//5.组织数据并发送
//6.处理响应

int main(int argc, char  *argv[])
{
    ros::init(argc, argv, "wugui");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name= "turtle2";
    //判断服务器状态
    client.waitForExistence();
    bool flag = client.call(spawn);

    if(flag)
    {
        ROS_INFO("Spawn success");
    }
    else
    {
        ROS_ERROR("Spawn failed");
    }
    ros::spin();

    return 0;
}