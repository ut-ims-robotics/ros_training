Using parameters in your node
=============================

Next, we're going to implement parameters into the fake sonar driver. Parameters are stored at ROS Master and can be accessed through node handles. Please see `Parameters tutorial <http://wiki.ros.org/roscpp_tutorials/Tutorials/Parameters>`_ for reference. 

#. Use the default value version of the ``param()`` function to gain the following features to the fake sonar driver:

   * if the parameter ``frequency`` exists on the parameter server, use its value in the sine function.
   * if the parameter is not specified, fallback to a default value.
