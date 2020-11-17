
#include "point_to_laserscan.h"


/**************************************************************************************************************************************************

测量的激光扫描角度，逆时针为正
设备坐标帧的0度面向前（沿着X轴方向）
 
Header header
float32 angle_min        # scan的开始角度 [弧度]
float32 angle_max        # scan的结束角度 [弧度]
float32 angle_increment  # 测量的角度间的距离 [弧度]
float32 time_increment   # 测量间的时间 [秒]
float32 scan_time        # 扫描间的时间 [秒]
float32 range_min        # 最小的测量距离 [米]
float32 range_max        # 最大的测量距离 [米]
float32[] ranges         # 测量的距离数据 [米] (注意: 值 < range_min 或 > range_max 应当被丢弃)
float32[] intensities    # 强度数据 [device-specific units]

**************************************************************************************************************************************************/





int main(int argc, char **argv)
{
  ros::init(argc, argv, "process_points");
  ros::NodeHandle nh;

  Point2laserscan point2laserscan(nh);

  ros::spin();
  return 0;
}
