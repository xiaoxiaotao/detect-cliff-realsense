#include "point_to_laserscan.h"
#include <numeric>


void Point2laserscan::Point2laserscan_init(){

   sub_points = nh_.subscribe<depth_nav_msgs::Point32List>("/cliff_detector/points", 100, boost::bind(&Point2laserscan::PointsCallback, this, _1));
   scan_pub = nh_.advertise<sensor_msgs::LaserScan>("/cliff/scan", 50);

}

void Point2laserscan::PointsCallback(const depth_nav_msgs::Point32ListConstPtr &points){


  
   std::cout<<"point size:"<<points->size<<std::endl;
   if(points->size>0){

      std::vector<float> fov;
      for(auto point : points->points){

         if(point.x>0){
            map_corrd.insert(map<float, float>::value_type(float(std::atan2(point.z,point.x)),sqrt(point.x * point.x + point.z * point.z)));
         }else{
            map_corrd.insert(map<float, float>::value_type(3.1415926-float(std::atan2(point.z,-point.x)),sqrt(point.x * point.x + point.z * point.z)));
         }
      }

      for(auto temp : map_corrd)
         fov.push_back(temp.first);
           
      float horizontal_fov=fov[fov.size()-1]-fov[0];
      int horizontal_resolution=int(10*horizontal_fov*180/3.1415926);
      sensor_msgs::LaserScan scan;
      
      scan.scan_time=1.0 / 30.0;
      scan.header.frame_id="camera_depth_frame";
      scan.time_increment = 0;
      scan.angle_increment=horizontal_fov / horizontal_resolution;
      scan.angle_min=fov[0];
      scan.angle_max=3.1415926;
      scan.range_min= 0.45;
      scan.range_max=5.0;
      scan.ranges.resize(horizontal_resolution+5);

      for(auto point: points->points){

         if(point.x>0){

            //std::cout<<int((std::atan2(point.z,point.x)-scan.angle_min)/scan.angle_increment)<<std::endl;
            scan.ranges[round((std::atan2(point.z,point.x)-scan.angle_min)/scan.angle_increment)] = sqrt(point.x * point.x + point.z * point.z);

         }else{

            //std::cout<<int((3.1415926-std::atan2(point.z,-point.x)-scan.angle_min)/scan.angle_increment)<<std::endl;
            scan.ranges[round((3.1415926-std::atan2(point.z,-point.x)-scan.angle_min)/scan.angle_increment)] = sqrt(point.x * point.x + point.z * point.z);
         }

    

      scan_pub.publish(scan);
      fov.clear();
      map_corrd.clear();

      }

   }

}


