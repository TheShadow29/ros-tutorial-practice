#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include<pcl_conversions/pcl_conversions.h>
#include<pcl/point_cloud.h>
#include<pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

ros::Publisher pub;


void cloud_cb(const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
	//Create container for data
	//sensor_msgs::PointCloud2 output;

	pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;
	pcl::PCLPointCloud2ConstPtr cloud_ptr(cloud);
	pcl::PCLPointCloud2 cloud_filtered;
	
	//pcl_conversions
	pcl_conversions::toPCL(*cloud_msg,*cloud);
	
    //Do data processing here
	
	// output = *input;
	//create the filtering object
	pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
	sor.setInputCloud(cloud_ptr);
	sor.setLeafSize(0.1f,0.1f,0.1f);
	sor.filter(cloud_filtered);

	//Convert to ros obj
	sensor_msgs::PointCloud2 output;
	pcl_conversions::fromPCL(cloud_filtered,output);

	//Publish the data
	pub.publish(output);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "my_pcl_tutorial");
	ros::NodeHandle nh;

	//Create ROS subscriber
	ros::Subscriber sub = nh.subscribe("input",1,cloud_cb);

	//Create ROS publisher for output point cloud
	pub = nh.advertise<sensor_msgs::PointCloud2>("output",1);

	//Spin
	ros::spin();
}
