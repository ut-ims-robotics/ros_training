Creating Packages
=================

In this exercise, we will create our own ROS package which we continuously improve during this training. Eventually it will become a driver package for a sonar device.

We've verified ROS installation, created a workspace, and even built a few times. Now we want to create our own package and our own node some custom code.

#. Visit the ROS Wiki: `Create a Package <http://wiki.ros.org/ROS/Tutorials/CreatingPackage>`_ section and `catkin_tools <https://catkin-tools.readthedocs.io/en/latest/verbs/catkin_create.html>`_  documentation to find out how to create a catkin package.

#. Your goal is to create a catkin package that:

   * has a name: ``sonar_driver``
   * has the following dependencies:

       - roscpp
       - sensor_msgs
       - geometry_msgs

   .. note:: Remember that all packages should be created inside a workspace src directory.
  
#. If you succeeded there will be a folder named ``sonar_driver``. Change into that folder and open the ``package.xml`` file for editing.
   
#. Change the description, version, author, etc., as you like.

#. Finally, build the package with:

   .. code-block:: bash

      catkin build

   .. note:: Further reading on building packages is available here: `Building Packages <http://wiki.ros.org/ROS/Tutorials/BuildingPackages>`_.

#. Show your successes to the instructor.

.. hint:: If you forget to add a dependency when creating a package, you can add additional dependencies in the ``package.xml`` file.

