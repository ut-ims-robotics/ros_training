MoveGroup C++ Interface
=======================

This excercise introduces how to program robot manipulators uing MoveIt MoveGroup C++ Interface. The API for MoveGroup C++ interface can be found here_.
To illustrate some of the capabilities of the interface, we'll be using ``movegroup_interface_demo`` package in collaboration with xArm7 ROS support.

   :code:`$ git clone https://github.com/ut-ims-robotics/movegroup_interface_demo.git`
 
   :code:`$ catkin build`

The general workflow for using MoveIt MoveGroup interface in your program code can be summarized in the following steps:

1. Initialize ROS.

2. Create an instance of MoveGroup that corresponds to the *robot* you program for.

3. Use an appropriate MoveGroup interface method to set target pose for the manipulator.

4. Trigger motion-planning from current pose to the target pose by using a method from the MoveGroup API.

5. If motion plan was successfully generated, execute the motion on the robot.

In order to demonstrate and investigate the capabilites of MoveGroup interface, first start xArm7 with MoveIt. Keep the RViz window visible as you
run different nodes from the ``movegroup_interface_demo`` package.

   :code:`$ roslaunch xarm7_moveit_config demo.launch`

   .. figure:: ../_static/pics/moveit_gui_xarm7.png
      :width: 600pt

Planning to a Pose Goal
-----------------------

   :code:`$ rosrun movegroup_interface_demo pose_goal`

Look into the source code ``src/pose_goal.cpp`` to understand how MoveGroup Interface is being used. All the explanations are provided within the
source file. Feel free to tinker with the contents of the source code to see the effects. Remember to ``catkin build`` after every time you change something in the source code.

Planning to a Named Goal
------------------------

   :code:`$ rosrun movegroup_interface_demo named_goal`

Look into the source code ``src/named_goal.cpp`` to understand how MoveGroup Interface is being used. All the explanations are provided within the
source file. Feel free to tinker with the contents of the source code to see the effects. Remember to ``catkin build`` after every time you change something in the source code.

Planning to a Joint Value Goal
------------------------------

   :code:`$ rosrun movegroup_interface_demo joint_value_goal`

Look into the source code ``src/joint_value_goal.cpp`` to understand how MoveGroup Interface is being used. All the explanations are provided within the
source file. Feel free to tinker with the contents of the source code to see the effects. Remember to ``catkin build`` after every time you change something in the source code.


Computing a Cartesian Path
--------------------------

   :code:`$ rosrun movegroup_interface_demo cartesian_path`

Look into the source code ``src/cartesian_path.cpp`` to understand how MoveGroup Interface is being used. All the explanations are provided within the
source file. Feel free to tinker with the contents of the source code to see the effects. Remember to ``catkin build`` after every time you change something in the source code.

Individual task
---------------

Create a program (it can be a new node within ``movegroup_interface_demo`` or in a standalone package) that makes the robot end-effector travel through
4 consecutive points. Feel free to use any of the methods illustrated above.

.. _here: http://docs.ros.org/kinetic/api/moveit_ros_planning_interface/html/classmoveit_1_1planning__interface_1_1MoveGroupInterface.html