#include <depth_nav_msgs/Point32List.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <sensor_msgs/LaserScan.h>
#include <boost/bind.hpp>
#include <iostream>
#include <ros/ros.h>
#include <opencv2/opencv.hpp>




using namespace std;

class Point2laserscan{


    public:



        Point2laserscan(ros::NodeHandle nh) : nh_(nh)
        {
            ROS_INFO("---------- Point2laserscan init -----------");
            Point2laserscan_init();
        }
        virtual ~Point2laserscan() {}
        virtual void Point2laserscan_init();


        void PointsCallback(const depth_nav_msgs::Point32ListConstPtr& points);
        void fieldOfView(double & min, double & max, double x1, double y1,double xc, double yc, double x2, double y2);
        
        



    public:

        double laser_frequency = 10;
        std::map<float,float> map_corrd;
        ros::Subscriber sub_points;
        ros::Publisher scan_pub;
        ros::NodeHandle nh_;


};


