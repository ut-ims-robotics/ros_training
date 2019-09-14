Create Catkin Workspace
=======================

In this exercise, we will create a ROS catkin workspace.

Any ROS project begins with making a workspace. The workspace will contain all the things related to this project. Typically you would have multiple workspaces and switch between them or combine them by extending one from another. 

We will consider this training as one project and create a single workspace that will be used throughout the training. All your developed packages will be developed in this workspace. To keep consistency with other ROS tutorials, we name the workspace ``catkin_ws`` and place it under the home directory.

Further information
-------------------

* Steps to creating a workspace:  `Creating a Workspace <http://wiki.ros.org/catkin/Tutorials/create_a_workspace>`_
* Using a catkin workspace:  `Using a workspace <http://wiki.ros.org/catkin/Tutorials/using_a_workspace>`_


Create a Catkin Workspace
-------------------------

#. Start by creating a root directory for the workspace:

   .. code-block:: bash

      cd 
      mkdir -p catkin_ws/src

#. Next, we need to initialize the workspace. But before doing that, we have to be sure which workspace our new `catkin_ws` is going to extend. The rule is that the new initialized workspace will always extend the workspace that is currently sourced.

#. This training is accompanied with support packages placed in separate workspace located at ``~/clearbot_ros_ws``. The plan is to initialize our new ``catkin_ws`` so that it would extend the ``clearbot_ros_ws``. So the only thing we need to do is make sure we have sourced ``clearbot_ros_ws`` before using the init command:

   .. code-block:: bash

      source ~/clearbot_ros_ws/devel/setup.bash
      cd ~/catkin_ws
      catkin init
      
#. The output of the ``catkin init`` command tells you which workspaces were extended:
   
   .. code-block:: bash

      ...
      Extending:             [env] /home/academy/clearbot_ros_ws/devel:/opt/ros/kinetic
      ...

  .. note:: Look for the statement "Workspace configuration appears valid", showing that your catkin workspace was created successfully. If you forgot to create the ``src`` directory, or did not run `catkin init` from the workspace root (both common mistakes), you'll get an error message like "WARNING: Source space does not yet exist".

#. Build the workspace. This command may be issued anywhere under the workspace root-directory (i.e. ``catkin_ws``).

   .. code-block:: bash

      catkin build
      ls

   * See that the ``catkin_ws``).directory now contains additional directories (build, devel, logs).

#. These new directories can be safely deleted at any time (either manually, or using ``catkin clean``). Re-run ``catkin build`` to re-create the build/devel/logs directories.

   .. code-block:: bash

      catkin clean
      ls
      catkin build
      ls


   .. note:: Catkin never changes any files in the ``src`` directory. 

#. Make the workspace visible to ROS. Source the setup file in the devel directory.

   .. code-block:: bash

      source ~/catkin_ws/devel/setup.bash


   * This file MUST be sourced for every new terminal. Add this to your ``~/.bashrc`` file to source your new workspace automatically each time a new terminal is opened:

     .. code-block:: bash

        echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc

