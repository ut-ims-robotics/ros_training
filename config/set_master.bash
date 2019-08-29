#!/bin/bash

echo -ne "Enter the number of a Clearbot [1-15]: "
read CLEARBOT_NUMBER
export ROS_MASTER_URI=http://192.168.200.$CLEARBOT_NUMBER:11311

echo -e "---------------------------------------------"
echo -e "ROS_MASTER_URI  =  $ROS_MASTER_URI"
echo -e "ROS_IP          =  $ROS_IP"
echo -e "---------------------------------------------"
echo "Done! This terminal is now configured to use ROS Master on Clearbot-$CLEARBOT_NUMBER"
