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
		
		// Subtract blue's theta from the bearing to get the angle that it needs to turn by
		double temp = (bearing(blue_x, blue_y, red_x, red_y) - blue_theta);

		// Variable to easily define 2PI
		double threeSixtyNoScope = (2*M_PI);

		// If temp is bigger or smaller than PI, then subtract or add 2PI, respectively
		if(temp >= M_PI) {
			temp = temp - threeSixtyNoScope;	
		} else if(temp <= -M_PI) {
			temp = temp + threeSixtyNoScope;
		}

		// If blue robot closes in within 2.0 of red robot, then slow down
		if(distanceFormula(blue_x, blue_y, red_x, red_y) < 2.0) {
			lvel = 0.5;
		} else {
			lvel = des_vel;
		}
			
		// if temp is greater than zero, but less than PI, rotate right by 0.75
		// similarly, if temp is less than zero, but greater than -PI, then rotate by -0.75 
		if(temp > 0 && temp < M_PI) {
			rvel = 0.75;
		} else if(temp < 0 && temp > -M_PI){
			rvel = -0.75;
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

