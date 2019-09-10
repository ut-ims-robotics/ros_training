3D mapping
-------------

Although 3D mapping requires much more resources and is less developed field than 2D mapping, it is worth to try out how 3D mapping works in ROS using RTABMap.

1.  Create a ssh-connection to the robot and launch roscore to keep ROS running and prevent us from having to restart all nodes every time. (If you close the first roslaunch you ran, whole ROS system will collapse because it is the same as killing the core.)

2.  Create a ssh-connection to the robot and launch 

    .. code-block:: bash

        roslaunch robotont_teleop teleop_3dmapping.launch

3.  In another terminal in your PC, for visualization, run:

    .. code-block:: bash

        roslaunch robotont_description display_3dmapping.launch
4.  In another terminal, for controlling the robot, run:

    .. code-block:: bash

        roslaunch robotont_teleop teleop_pc_side.launch

5.  Drive around the room and try mapping it.

6.  You should notice, that default settings do not create a very good map.

Currently, it can be seen, that the mapping software needs some tuning.

For that, a simplified approach is made with launch files (arguments in robotont_teleop/launch/teleop_3dmapping.launch).
But if you want to explore more options/parameters, refer to http://wiki.ros.org/rtabmap_ros#rtabmap .

1.  Kill the process where you ran *teleop_3dmapping.launch* .

2.  Instead, run:

    .. code-block:: bash

        roslaunch robotont_teleop teleop_3dmapping.launch angular_update:=0.1 linear_update:=0.1 cell_size:=0.1

    And here you can change some values and hopefully get a better 3D map.
