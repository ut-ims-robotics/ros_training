Introduction to ROS
===================

Slides are available here: :download:`pdf <ros_intro_slides.pdf>`

In this exercise, we will setup ROS to be used from the terminal, and start roscore. 

In order to start programming in ROS, you should know how to install ROS on a new machine as well and check that the installation worked properly. This module will walk you through a few simple checks of your installed ROS system.


ROS Installation
----------------

 As ROS is already preinstalled to your system, this section can be fast forwarded. Nevertheless, You are still encouredged to have a look on the `installation instructions <http://wiki.ros.org/kinetic/Installation/Ubuntu>`_ needed to get ROS going on a freshly installed Ubuntu Linux.



Testing the environment
-----------------------

We believe we have a good installation of ROS but let's test it to make sure.

#. A good way to start is to ensure that environment variables like ROS_ROOT and ROS_PACKAGE_PATH are set:

   .. code-block:: bash

      printenv | grep ROS

#. If the variables are empty or do not contain paths to ROS workspaces you would like to work with, it is most likely that you might need to 'source' some setup.*sh files.
#. Let's do that by entering:

   .. code-block:: bash

      source /opt/ros/kinetic/setup.bash

#. Now we have sourced the default workspace for ROS kinetic.

#. Run the :code:`printenv | grep ROS` command again and verify that the variables have been set.

.. tip:: If you are ever having problems finding or using your ROS packages make sure that you have your environment properly setup.

.. note:: In a "bare" ROS install, you will need to run this command on every new shell you open to have access to the ROS commands. One of the setup steps in a *typical* ROS install is to add that command to the end of your :code:`~/.bashrc` file, which is run automatically in every new terminal window.

#. To check that your :code:`.bashrc` file has already been configured to source the ROS-kinetic `setup.bash` script:

   .. code-block:: bash

      tail ~/.bashrc

#. For ease of this workshop, use the following oneliner to add automatic sourcing to the :code:`.bashrc`:
  
   .. code-block:: bash

      echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc 

.. note:: As one can observe, we sourced the ROS environment for a specific ROS distribution (kinetic). Using this sourcing process allows you to install several ROS distributions (e.g. indigo and kinetic) on the same computer and switch between them by sourcing the distribution-specific `setup.bash` file.

.. seealso:: More information on configuring the environment can be found from:
   `ROS Wiki -- Installing and Configuring Your ROS Environment <http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment>`_.

Navigating the ROS Filesystem
=============================

Once you have learned the basic commands for navigating Linux filesystem, it is a matter of adding a prefix :code:`ros` and you are able to easily navigate between ROS packages in your sourced sourced workspaces.

In this section we will explore the following ROS commands: 

* rospack = ros + pack(age)
* roscd = ros + cd
* rosls = ros + ls

This naming pattern holds for many other ROS tools.


rospack Command
----------------

rospack allows you to get information about packages. In the following, we are only going to cover the find option, which returns the path to package. The command is used as follows:

.. code-block:: bash

      rospack find [package_name]

#. In the terminal configured for ROS, type:

   .. code-block:: bash

      rospack find roscpp

#. rospack should return :code:`/opt/ros/kinetic/share/roscpp` for the package location.

roscd Command
-------------

#. Type: :code:`roscd roscpp`, then type :code:`pwd`.

#. You will notice that the working directory was changed to where the :code:`roscpp` package is located.

rosls Command
-------------

With :code:`rosls`, you can directly get the file listing of a given package.

#. Try it out with:

   .. code-block:: bash

      rosls laser_geometry

#. Files and folders from the :code:`laser_geometry` package should be displayed. 

.. note:: Keep in mind that all ROS tools will only find ROS packages that are within the directories listed in your ROS_PACKAGE_PATH. To see what is in your ROS_PACKAGE_PATH, type: :code:`echo $ROS_PACKAGE_PATH`. A colon separated list of paths appears.

.. seealso:: More information on navigating the ROS filesystem can be found from: `ROS Wiki -- Navigating the ROS Filesystem <http://wiki.ros.org/ROS/Tutorials/NavigatingTheFilesystem>`_.


Starting roscore
----------------
#. :code:`roscore` is a collection of programs that are pre-requisites of a ROS-based system. You must have a roscore running in order for ROS nodes to communicate. It is launched using:

   .. code-block:: bash

      roscore

There are several components that are started with :code:`roscore`:

  * a ROS Master
  * a ROS Parameter Server
  * a rosout logging node

   You will see ending with `started core service [/rosout]`. If you see `roscore: command not found` then you have not sourced your environment, please refer to the previous section to resource the environment.

#. Verify that the :code:`roscore` is running. Open a new terminal window and enter:

   .. code-block:: bash

      rosnode list
 
You should see the logging node named :code:`/rosout`

#. Press :kbd:`Ctrl+C` in the first terminal window to stop :code:`roscore`.

#. Try to obtain the node list again in the second terminal. Was the command sucessful this time?
   
   .. tip:: :kbd:`Ctrl-C` is the typical method used to stop most ROS commands.


Running your first ROS program
==============================


