#include "ros/ros.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"




int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "static_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    geometry_msgs::PointStamped point;
    point.header.frame_id = "laser";
    point.header.stamp = ros::Time::now();
    point.point.x = 2.0;
    point.point.y = 3.0;
    point.point.z = 5.0;
    //添加休眠
    ros::Duration(1).sleep();

    ros::Rate rate(10);

    while (ros::ok() )
    {
        geometry_msgs::PointStamped pose_out;
        pose_out = buffer.transform(point,"base_link");

        //输出
        ROS_INFO("转换后的坐标值 (%.2f,%.2f,%.2f) 参考的坐标系%s" , 
        pose_out.point.x, 
        pose_out.point.y, 
        pose_out.point.z,
        pose_out.header.frame_id.c_str());
        
        rate.sleep();
        ros::spinOnce();
    }
    
    
    return 0;
}
