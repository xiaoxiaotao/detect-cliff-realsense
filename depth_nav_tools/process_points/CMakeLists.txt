cmake_minimum_required(VERSION 2.8.3)
project(process_points)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)

add_compile_options(
  -Wall
  -O3
  -Werror
)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  image_geometry
  image_transport
  nodelet
  dynamic_reconfigure
  sensor_msgs
  depth_nav_msgs
  rospy
)
find_package( Boost )

include_directories(${Boost_INCLUDE_DIRS})



find_package( OpenCV REQUIRED )
catkin_package(
  # INCLUDE_DIRS include
  # CATKIN_DEPENDS ${CATKIN_PACKAGE_DEPENDENCIES}
)

include_directories(
  # include 
  ${catkin_INCLUDE_DIRS}
  /home/tao/cliff_detect_ws/src/depth_nav_tools/process_points/include/
  ${OpenCV_INCLUDE_DIRS}  
  )
add_executable(
  process_points 
  src/main.cpp
  src/point_to_laserscan.cpp
  )
target_link_libraries(
  process_points  
  ${catkin_LIBRARIES}
  ${Boost_LIBRARIES}
  ${OpenCV_LIBS} 
  )
