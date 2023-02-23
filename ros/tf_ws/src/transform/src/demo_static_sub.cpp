#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2_ros/buffer.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h" // 调用transform必须包含该头文件

int main(int argc, char *argv[])
{
    // 初始化ROS节点
    ros::init(argc, argv, "tf_sub");
    ros::NodeHandle nh;

    // 创建TF订阅节点
    tf2_ros::Buffer buffer;

    tf2_ros::TransformListener listener(buffer);
    ros::Rate rate(10);

    while (ros::ok())
    {
        // 生成一个坐标点（相对于子级坐标系）
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id = "laser";
        point_laser.header.stamp = ros::Time::now();
        point_laser.point.x = 1;
        point_laser.point.y = 2;
        point_laser.point.z = 7.3;

        /* 转换坐标点（相对父级坐标系）
        新建一个坐标点，用于接收转换结果
        -----使用try语句或休眠，否则可能由于缓存接收而导致坐标转换失败 */

        try
        {
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_laser, "base_link");
            ROS_INFO("data after tramsformed is %.2f,%.2f,%.2f", point_base.point.x, point_base.point.y, point_base.point.z);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            ROS_INFO("something went wrong!!!");
        }

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
