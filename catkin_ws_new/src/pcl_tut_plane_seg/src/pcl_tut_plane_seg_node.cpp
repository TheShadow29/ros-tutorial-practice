#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
//#include <pcl/ros/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/sample_consensus/model_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include<visualization_msgs/Marker.h>
ros::Publisher pub;
ros::Publisher pub_marker;

void cloud_cb(const sensor_msgs::PointCloud2ConstPtr&);
//void show_marker(pcl_msgs::ModelCoefficients);


void 
cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
	// Convert the sensor_msgs/PointCloud2 data to pcl/PointCloud
	pcl::PointCloud<pcl::PointXYZ> cloud;
	pcl::fromROSMsg (*input, cloud);
	ROS_INFO_STREAM("Input received ");
	pcl::ModelCoefficients coefficients;
	pcl::PointIndices inliers;
	// Create the segmentation object
	pcl::SACSegmentation<pcl::PointXYZ> seg;
	// Optional
	seg.setOptimizeCoefficients (true);
	// Mandatory
	seg.setModelType (pcl::SACMODEL_PLANE);
	seg.setMethodType (pcl::SAC_RANSAC);
	seg.setDistanceThreshold (0.01);

	seg.setInputCloud (cloud.makeShared ());
	seg.segment (inliers, coefficients); 
	
	
	// Publish the model coefficients
	pcl_msgs::ModelCoefficients ros_coefficients;
	pcl_conversions::fromPCL(coefficients, ros_coefficients);
	ros::Rate r(1);
	uint32_t shape = visualization_msgs::Marker::ARROW;

//		uint32_t shape = visualization_msgs::Marker::CUBE;
	while (ros::ok())
	{
		//create visualization msg obj called marker
		visualization_msgs::Marker marker;
		//set frame id
		marker.header.frame_id = "/asus_frame";
		marker.header.stamp = ros::Time::now();
		//namespace and id
		//marker.ns = "basic_shapes";
		//marker.id = 0;
		//shape is cube initially
		marker.type = shape;
		// Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
		marker.action = visualization_msgs::Marker::ADD;


		// Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
		
		
		marker.pose.position.x = 0;
		marker.pose.position.y = 0;
		marker.pose.position.z = 0;
		marker.pose.orientation.x = 0.0;
		marker.pose.orientation.y = 0.0;
		marker.pose.orientation.z = 0.0;
		marker.pose.orientation.w = 1.0;
 

		// Set the scale of the marker -- 1x1x1 here means 1m on a side
		float scale1 = 0.1;
		
		marker.scale.x = 1.0 * scale1;
		marker.scale.y = 1.0 * scale1;
		marker.scale.z = 1.0 * scale1;

		//Color of the marker
		marker.color.r = 0.0f;
		marker.color.g = 1.0f;
		marker.color.b = 0.0f;
		marker.color.a = 1.0;



		marker.lifetime = ros::Duration();


		// Publish the marker
		//if no subscribers prompt so
		while (pub_marker.getNumSubscribers() < 1)
		{
			if (!ros::ok())
			{
				return;
			}
			ROS_WARN_ONCE("Please create a subscriber to the marker");
			sleep(1);
		}
		pub_marker.publish(marker);
		pub.publish(ros_coefficients);

		// Cycle between different shapes


		r.sleep();
	}
	
	// while(ros::ok())
	// {	
	// 	visualization_msgs::Marker marker_plane;
	// 	marker_plane.header.stamp = ros::Time::now();
	// 	marker_plane.header.frame_id = "asus_frame";
	// 	marker_plane.type = shape;
	// 	marker_plane.id = 0;
	// 	marker_plane.action = visualization_msgs::Marker::ADD;

	// 	marker_plane.pose.position.x = 0;
	// 	marker_plane.pose.position.y = 0;
	// 	marker_plane.pose.position.z = 0;
	// 	marker_plane.pose.orientation.x = 0.0;
	// 	marker_plane.pose.orientation.y = 0.0;
	// 	marker_plane.pose.orientation.z = 0.0;
	// 	marker_plane.pose.orientation.w = 0.0;

	// 	marker_plane.scale.x = 1000;
	// 	marker_plane.scale.y = 1000;
	// 	marker_plane.scale.z = 1000;

	// 	marker_plane.color.r = 0;
	// 	marker_plane.color.g = 1;
	// 	marker_plane.color.b = 0;

	// 	marker_plane.lifetime = ros::Duration();

	// 	while (pub_marker.getNumSubscribers() < 1)
	// 	{
	// 		if (!ros::ok())
	// 		{
	// 			return;
	// 		}
	// 		ROS_WARN_ONCE("Please create a subscriber to the marker");
	// 		sleep(1);
	// 	}
	// 	pub.publish(ros_coefficients);
	// 	pub_marker.publish(marker_plane);
	// 	ros::spinOnce();
	// 	rate.sleep();
	// }

//	show_marker(ros_coefficients);
	//pub.publish(ros_coefficients);
	//ros::spin();
	// while(ros::ok())
	// {
		
	// 	pub.publish (ros_coefficients);
	// 	ros::spinOnce();
	// 	rate.sleep();
	// }
}

int
main (int argc, char** argv)
{
	// Initialize ROS
	ros::init (argc, argv, "my_pcl_tutorial");
	ros::NodeHandle nh;

	// Create a ROS subscriber for the input point cloud
	ros::Subscriber sub = nh.subscribe ("/matcher/cloud", 1, cloud_cb);

	// Create a ROS publisher for the output model coefficients
	pub = nh.advertise<pcl_msgs::ModelCoefficients> ("output", 1);
	pub_marker = nh.advertise<visualization_msgs::Marker>("marker_for_pc",1);
	
	// Spin
	ros::spin ();
}

// void show_marker(pcl_msgs::ModelCoefficients ros_coefficients)
// {

	
// }
