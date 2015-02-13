#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>

#include <tf/transform_datatypes.h>


/************************************/
  // place your functions here
double distanceFormula(double x1, double y1, double x2, double y2) {
	double d = sqrt((pow(x2-x1,2))+(pow(y2-y1,2)));
	return d; 
}
double bearing(double x1, double y1, double x2, double y2) {
	double thetaT = atan2((y2-y1),(x2-x1));
	return thetaT;		
}

/************************************/


/***
  ignore these functions

***/
double red_x, red_y, blue_x, blue_y;
double red_theta, blue_theta;

double getRotationFromMsg( geometry_msgs::Quaternion q )
{

  double yaw;
  yaw = tf::getYaw(q);
  return yaw;
}

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  red_x = msg->pose.pose.position.x;
  red_y = msg->pose.pose.position.y;
  red_theta = getRotationFromMsg(msg->pose.pose.orientation);
}

void odom2Callback(const nav_msgs::Odometry::ConstPtr& msg)
{
  blue_x = msg->pose.pose.position.x;
  blue_y = msg->pose.pose.position.y;
  blue_theta = getRotationFromMsg(msg->pose.pose.orientation);
}


int main( int argc, char* argv[] )
{
	// this code initializes a connection to the robot
	ros::init(argc,argv,"follower");
	ros::NodeHandle nh;
	ros::Rate loop_rate(10);

	ros::Publisher cmd_vel = nh.advertise<geometry_msgs::Twist>("/robot_1/cmd_vel",1000);
  ros::Subscriber odom_sub = nh.subscribe("/robot_0/base_pose_ground_truth",1000,odomCallback);
  ros::Subscriber odom2_sub = nh.subscribe("/robot_1/base_pose_ground_truth",1000,odom2Callback);

	geometry_msgs::Twist cmd_vel_msg;
	double des_vel = 1.0;

	// loop forever
	while( ros::ok() )
	{
		// by default, the robot will move forward at 1 meter / second
		double lvel = des_vel;
		
		// by default, the robot will not turn at all
		double rvel = 0;


			//place your code here /***************************************/
		//if blue closes in on red within 2.0, then slow down
		double temp = bearing(blue_x, blue_y, red_x, red_y) - blue_theta;
		
		if(distanceFormula(blue_x, blue_y, red_x, red_y) < 2.5) {
			lvel = 0.5;
		} else {
			lvel = des_vel;
		}
			
		// if temp  
		if(temp > 0) {
			rvel = 0.75;
		} else if(temp < 0) {
			rvel = -0.75;
		}

		if(temp == 0) {
			rvel = 0;
		}



		
			/***************************************/
		// send the speeds to the robot
		cmd_vel_msg.linear.x = lvel;
		cmd_vel_msg.angular.z = rvel;
		cmd_vel.publish(cmd_vel_msg);
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}

