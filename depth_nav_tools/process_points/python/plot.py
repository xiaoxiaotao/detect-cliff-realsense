#!/usr/bin/env python

import os
import rospy
from depth_nav_msgs.msg import *


rospy.init_node('point_plot', anonymous=True)

# def callback:

#     rospy.loginfo(rospy.get_master,)

# rospy.Subscriber("/cliff_detector/points", Point32List, callback)