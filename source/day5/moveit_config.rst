MoveIt Configuration package
============================
Now that we have a urdf-file describing our robot, we can use MoveIt Setup Assistant to generate all the configuration files needed to make our robot work with MoveIt.

Working with MoveIt Setup Assistant
-----------------------------------

In order to launch MoveIt Setup Assistant:

   :code:`$ roslaunch moveit_setup_assistant setup_assistant.launch`

   .. figure:: ../_static/pics/moveit_setup_01.png
      :width: 600pt

Next:

1. click on *Create New MoveIt Configuration Package*,
2. use *Browse* button to select the urdf-file created in previous task, and
3. click on *Load Files* button.

   .. figure:: ../_static/pics/moveit_setup_01-after.png
      :width: 600pt

On *Self-Collisions* tab:

1. slide *Sampling Density* to the highest possible level and
2. click on *Generate Collision Matrix*. 

   .. figure:: ../_static/pics/moveit_setup_02-after.png
      :width: 600pt

On *Virtual Joints* tab click on *Add Virtual Joint*, fill it with the following information, and save it.

   .. figure:: ../_static/pics/moveit_setup_03-after.png
      :width: 600pt

The final look on *Virtual Joints* tab should appear as follows.

   .. figure:: ../_static/pics/moveit_setup_03-after2.png
      :width: 600pt

On *Planning Groups* tab, click on *Add Group* and fill it as follows.

   .. figure:: ../_static/pics/moveit_setup_04-after.png
      :width: 600pt

Next we will define the planning group by adding a kinematic chain. Use ``base_link`` as *Base Link* and ``tool0`` as *Tip Link*.

   .. figure:: ../_static/pics/moveit_setup_04-after2.png
      :width: 600pt

The final view on the *Planning Groups* tab should look as follows.

   .. figure:: ../_static/pics/moveit_setup_04-after3.png
      :width: 600pt

On *Robot Poses* tab, click on *Add Pose* to create one predefined pose for your robot. Based on your preference, choose the joint values and name for the pose.
The final view on the *Robot Poses* tab could look as follows.

   .. figure:: ../_static/pics/moveit_setup_05-after2.png
      :width: 600pt

On *End Effectors* tab, click on *Add Effector*. It is important to make ``tool0`` your parent link for the end effector.

   .. figure:: ../_static/pics/moveit_setup_06-after.png
      :width: 600pt

No changes are required on *Passive Joints*, *ROS Control*, *Simulation*, and *3D Perception* tabs.

Fill in the *Author Information* tab with your name and e-mail.

On *Configuration Files* tab, it is necessary to define a name for your MoveIt configuration package. It is a good practice to all always name these packages in the
form of ``robotname_moveit_config``. So in current case ``my_robot_moveit_config`` is the recommended name. Choose the ``src/`` folder in your catkin workspace
as the location of the configuration package.

    .. figure:: ../_static/pics/moveit_setup_12-after.png
      :width: 600pt

Click on *Generate Package* and exit the Setup Assistant.

Testing the MoveIt configuration package
----------------------------------------

Among other files, the Setup Assistant generated the ``demo.launch`` for the robot.

   :code:`$ roslaunch my_robot_moveit_config demo.launch`

On *Planning* tab, make a tic in *Allow Approx IK Solutions* checkbox. Verify that the interactive markers, planning, and executing is working for the robot.

    .. figure:: ../_static/pics/moveit_setup_working.png
      :width: 600pt