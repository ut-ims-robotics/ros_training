Motion planning with a multi robot system
=========================================

ROS and MoveIt make it very easy to control multi manipulator systems. To exemplify it, let us create a dual manipulator setup using two xArm7s. The steps
are analogous to what we have learned already today.

1. Create a URDF for the dual manipulator system;

2. generate MoveIt configuration package for the system;

3. control the movement of manipulators using either MoveIt GUI or MoveGroup C++ Interface.

In order to take advantage of the modularity in ROS we'll be using XACRO to create URDF for our system. To quote xacro's ROS `wiki page`_, *'With xacro,
we can construct shorter and more readable XML files by using macros that expand to larger XML expressions.'*

Locate ``dual_xarm7.urdf.xacro`` in ``dual_manipulator_support`` package. This xacro-file demonstrates how to include an existing robot description to higher level system.
Modify the xacro-file to include another xArm7 with a prefix ``right_`` and position it on the ``platform`` link next to the already included xArm7.

   .. figure:: ../_static/pics/moveit_dual_xarm7.png
      :width: 600pt

The easiest way to visualize the system and also confirm the validity of the xacro is to launch MoveIt Setup Assistant and load the xacro-file.

Once the xacro-file is described, use the Setup Assistant to generate MoveIt configuration package. The process of using the Setup Assistant in analogous
to what we did before. However, on *Planning Groups* tab it is best to define 3 different groups: one for each manipulator and the third one to include them as
subgroups.

   .. figure:: ../_static/pics/moveit_dual_planning_groups.png
      :width: 600pt

Once we have saved the MoveIt configuration package, we can test it by launching its ``demo.launch``.

In ``movegroup_interface_demo`` package we can find a ``dual_pose_goal`` node to illustrate planning for dual manipulator system.

.. _`wiki page`: http://wiki.ros.org/xacro