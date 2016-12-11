#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
// PCL specific includes
//#include <pcl/ros/conversions.h>
#include<pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

ros::Publisher pub;

void 
cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
	pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;
	pcl::PCLPointCloud2ConstPtr cloud_ptr(cloud);
	pcl::PCLPointCloud2 cloud_filtered;

	pcl_conversions::toPCL(*input, *cloud);
	// ... do data processing

	sensor_msgs::PointCloud2 output;
  
	pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
	sor.setInputCloud(cloud_ptr);
	sor.setLeafSize(0.02f,0.02f,0.02f);
	sor.filter(cloud_filtered);  

	pcl_conversions::fromPCL(cloud_filtered,output);
	// Publish the data
	pub.publish (output);
}

int
main (int argc, char** argv)
{
	// Initialize ROS
	ros::init (argc, argv, "my_pcl_tutorial");
	ros::NodeHandle nh;

	// Create a ROS subscriber for the input point cloud
	ros::Subscriber sub = nh.subscribe ("/pc_out", 1, cloud_cb);

	// Create a ROS publisher for the output point cloud
	pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);

	// Spin
	ros::spin ();
}
