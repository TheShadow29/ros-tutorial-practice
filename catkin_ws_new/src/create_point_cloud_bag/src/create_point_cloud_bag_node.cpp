#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include<sensor_msgs/PointCloud2.h>
#include<pcl_conversions/pcl_conversions.h>
#include<pcl/point_cloud.h>
#include <pcl/point_types.h>

int main (int argc, char **argv)
{
	ros::init(argc, argv, "create_pcd_to_bag");
	ros::NodeHandle n;
	ros::Publisher pub_pc = n.advertise<sensor_msgs::PointCloud2>("pc_out", 1000);

	pcl::PointCloud<pcl::PointXYZ> pc;
	sensor_msgs::PointCloud2 msg_pc;
	pc.width = 200;
	pc.height = 100;
	pc.is_dense = false;
	pc.points.resize(pc.width * pc.height);

	for(size_t i=0; i < pc.height; ++i)
	{

		for(size_t j=0; j < pc.width; ++j)
		{
			// ROS_INFO_STREAM("STARTEDj " << j );
			const size_t k = pc.width * i + j;
			pc.points[k].x = 0.1 * i;
			pc.points[k].y = 0.2 * j;
			pc.points[k].z = 1.5;
		}

	}

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
	

	
		pcl::toROSMsg(pc, msg_pc);
		msg_pc.header.stamp = ros::Time::now();
		msg_pc.header.frame_id = "/frame_pc";
		pub_pc.publish(msg_pc);
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}

// #include <ros/ros.h>
// #include <sensor_msgs/PointCloud2.h>
// #include <visualization_msgs/Marker.h>
// #include <pcl_conversions/pcl_conversions.h>
// #include <pcl/point_cloud.h>
// #include <pcl/point_types.h>
// #include <pcl/sample_consensus/model_types.h>
// #include <pcl/sample_consensus/method_types.h>
// #include <pcl/segmentation/sac_segmentation.h>
// #include <pcl/ModelCoefficients.h>


// ros::Publisher vis_pub; //ros publisher to publish markers

// void ProcessInputPointCloud2(const sensor_msgs::PointCloud2ConstPtr& input)
// {

// 	//---------Initializing Segmenter--------------//

// 	//------------Done Initializing Segmenter-----//
// 	std::string frame;
	
// 	pcl::PointCloud<pcl::PointXYZ> tempCloud;
// 	if((input->height*input->width)>0)
// 	{
// 		frame = input->header.frame_id;
// 		pcl::PointCloud<pcl::PointXYZ> cloud;
// 		fromROSMsg (*input,cloud);
// 		// extractPlanes(cloud,seg,frame,vis_pub);
							
// 	}
	
// };



// int main(int argc, char **argv)
// {
//   ros::init(argc, argv, "planeSegmenter");

//   ros::NodeHandle n;
//   vis_pub = n.advertise<visualization_msgs::Marker>("/planesegmentation/planeVisualization", 1);
 
//   ros::Subscriber sub = n.subscribe("/matcher/cloud", 1, ProcessInputPointCloud2);

//   ros::spin();

//   return 0;
// }




// // #include <ros/ros.h>
// // #include <sensor_msgs/PointCloud2.h>
// // #include <pcl_conversions/pcl_conversions.h>
// // #include <pcl/point_cloud.h>
// // #include <pcl/point_types.h>

// // ros::Publisher pub;

// // int
// // main (int argc, char** argv)
// // {
// //   // Initialize ROS
// //   ros::init (argc, argv, "create_point_cloud_to_bag");
// //   ros::NodeHandle nh;

// //   // Create a ROS publisher for the output point cloud
// //   pub = nh.advertise<sensor_msgs::PointCloud2> ("msg", 1);

// //   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  
// //   cloud->width = 15;
// //   cloud->height = 1;
// //   cloud->points.resize(cloud->height * cloud->width);

// //   for(int i = 0; i < cloud->points.size(); i++)
// //   {
// // 	  // cloud->points[i].x = 1024*rand()/ (RAND_MAX + 1.0f);
// // 	  // cloud->points[i].y = 1024*rand()/ (RAND_MAX + 1.0f);
// // 	  // cloud->points[i].z = 1024*rand()/ (RAND_MAX + 1.0f);

// // 	  cloud->points[i].x = i
// // 	  cloud->points[i].y = i+1
// // 	  cloud->points[i].z = i+2

// //   }
// //   sensor_msgs::PointCloud2 output_msg;
// //   pcl::toROSMsg(*cloud, output_msg);

// //   pub.publish(output_msg);
  
// //   // Spin
// //   ros::spin ();
// // }
