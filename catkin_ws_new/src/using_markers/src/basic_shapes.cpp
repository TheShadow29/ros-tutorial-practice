#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int show_marker();
ros::Publisher marker_pub;
int main( int argc, char** argv )
{
	//standard stuff
	ros::init(argc, argv, "basic_shapes");
	ros::NodeHandle n;

	marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
	show_marker();
}

int show_marker()
{
	uint32_t shape = visualization_msgs::Marker::CUBE;
	ros::Rate r(1);	
	while (ros::ok())
	{
		//create visualization msg obj called marker
		visualization_msgs::Marker marker;
		//set frame id
		marker.header.frame_id = "/my_frame";
		marker.header.stamp = ros::Time::now();
		//namespace and id
		marker.ns = "basic_shapes";
		marker.id = 0;
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

		marker.scale.x = 1.0;
		marker.scale.y = 1.0;
		marker.scale.z = 1.0;

		//Color of the marker
		marker.color.r = 0.0f;
		marker.color.g = 1.0f;
		marker.color.b = 0.0f;
		marker.color.a = 1.0;



		marker.lifetime = ros::Duration();


		// Publish the marker
		//if no subscribers prompt so
		while (marker_pub.getNumSubscribers() < 1)
		{
			if (!ros::ok())
			{
				return 0;
			}
			ROS_WARN_ONCE("Please create a subscriber to the marker");
			sleep(1);
		}
		marker_pub.publish(marker);


		// Cycle between different shapes
 
		switch (shape)
		{
		case visualization_msgs::Marker::CUBE:
			shape = visualization_msgs::Marker::SPHERE;
			break;
		case visualization_msgs::Marker::SPHERE:
			shape = visualization_msgs::Marker::ARROW;
			break;
		case visualization_msgs::Marker::ARROW:
			shape = visualization_msgs::Marker::CYLINDER;
			break;
		case visualization_msgs::Marker::CYLINDER:
			shape = visualization_msgs::Marker::CUBE;
			break;
		}



		r.sleep();
	}
	
}
