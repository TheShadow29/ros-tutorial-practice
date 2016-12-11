#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include<sensor_msgs/PointCloud2.h>
#include<pcl_conversions/pcl_conversions.h>
#include<pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
int main (int argc, char **argv)
{
	ros::init(argc, argv, "create_pcd_to_bag");
	ros::NodeHandle n;
	ros::Publisher pub_pc = n.advertise<sensor_msgs::PointCloud2>("pc_out", 1000);

//	pcl::PointCloud<pcl::PointXYZ> pc;
	pcl::PointCloud<pcl::PointXYZ>::Ptr pc(new pcl::PointCloud<pcl::PointXYZ>);
	if(pcl::io::loadPCDFile<pcl::PointXYZ>("/home/arktheshadow/ARK-Linux/Programming/ROS/ros-tutorial-practice/catkin_ws_new/src/create_point_cloud_bag/src/file.pcd",*pc) == -1)
	{
		PCL_ERROR("Couldn't read the file \n");
		return -1;
	}
	sensor_msgs::PointCloud2 msg_pc;
	// pc.width = 200;
	// pc.height = 100;
	// pc.is_dense = false;
	// pc.points.resize(pc.width * pc.height);

	// for(size_t i=0; i < pc.height; ++i)
	// {

	// 	for(size_t j=0; j < pc.width; ++j)
	// 	{
	// 		// ROS_INFO_STREAM("STARTEDj " << j );
	// 		const size_t k = pc.width * i + j;
	// 		pc.points[k].x = 0.1 * i;
	// 		pc.points[k].y = 0.2 * j;
	// 		pc.points[k].z = 1.5;
	// 	}

	// }

	ROS_INFO_STREAM("Initial PC created");

	ros::Rate rate(1);
	while(ros::ok())
	{
		// for (size_t i = 0; i < pc.height; ++i)
		// {
		// 	for (size_t j = 0; j < pc.width; ++j)
		// 	{
		// 		const size_t k = pc.width*i + j;
		// 		pc.points[k].z -= 0.1;
		// 	}
		// }
	

	
		pcl::toROSMsg(*pc, msg_pc);
		msg_pc.header.stamp = ros::Time::now();
		msg_pc.header.frame_id = "/frame_pc";
		pub_pc.publish(msg_pc);
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}
