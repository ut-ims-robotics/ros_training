2D SLAM with a robot
---------------------

Now that we have tested some SLAM packages in a simulation, 
let's try them out on a real robot - Clearbot. We will be using Google Cartographer.

Copying necessary files to your workspace
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1.  For starters, ssh to your robot and go to your workspace's source folder.

2.  In your source folder, use

    .. code-block:: bash

        catkin_create_pkg <your_package_name>

    where your package name could be something along the lines of *my_mapping*.
    You don't need any build dependencies because this package will only hold launch and configuration files.

3.  Create a folder named *launch* in your package.

4.  Create a folder named *configuration* in your package.

5.  Using **roscp** (http://wiki.ros.org/rosbash#roscp),
    copy *teleop_cartographer_2d.launch*
    and *navstack.launch*
    and *teleop_carto_with_navstack.launch*
    from *robotont_teleop* package
    into your new package's *launch* folder.

6.  Using **roscp**, copy the following files from *robotont_teleop*
    into your package's configuration folder:

    .. code-block:: bash

        robotont_cartographer_2d.lua
        robotont_cartographer_localization_2d.lua
        robotont_depth_camera_2d.lua
        costmap_common.yaml
        costmap_exploration.yaml
        costmap_global_laser.yaml
        costmap_global_static.yaml
        costmap_local.yaml
        laser_params.yaml
        planner.yaml

7.  Do **catkin build** and source the workspace.

Now you have a package with launch and
configuration files that you can safely modify.

Configuring and launching Google Cartographer
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Next task is to modify your copied launch files
to include the configuration files from your package.

1.  Open *teleop_cartographer_2d.launch* from your package.

2.  Change the launch file so that it reads configuration files from your package.
    (NOTE: You have to change paths in 2 places.)

Now that you have configured the launch files, let's try running the SLAM package.

1.  In robot's terminal, run **roscore**.

2.  In another robot terminal, launch

    .. code-block:: bash

        roslaunch <your_package_name> teleop_cartographer_2d.launch

    This will run the mapping software.

3.  In the PC, launch:

    .. code-block:: bash

        roslaunch robotont_description display_2dmapping.launch

    This will launch preconfigured RViz environment.

4.  In the PC, launch:

    .. code-block:: bash

        roslaunch robotont_teleop teleop_pc_side.launch

    From this terminal, you can control the robot.

5.  Now you should be able to map the world.

Tuning Google Cartographer
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Although last step will already produce a map, it could be better (or worse).
Therefore, you have the chance to try tuning the algorithm
and maybe get a better result.

1.  




.. Cartographer configuration files are located in robotont_teleop/configuration_files.
