Launch file
===========

Launch files are useful for running multiple nodes simultaneously with a single ``roslaunch`` command. It can also be used to read parameters into the parameter server.

.. note:: The roslaunch automatically starts rosmaster if it isn't already running.

#. Go through the `roslaunch wiki <http://wiki.ros.org/roslaunch/XML/param>`_ and get familiar with its syntax.

#. From the wiki, find the information on:

  * how to pass and use command line arguments in the launch file;
  * how to use the ``<param />`` tag and read parameters to the server;
  * how to use the ``<node />`` tag to run nodes within roslaunch file.

#. Your task is to create a launch file into the ``fake sonar driver`` package. Implement the following functionality in the launch file:

  #. Read the the frequency argument from the command line and pass it to the parameter server.
  #. Start the fake sonar driver node.

Bonus task
----------

Add two more fake sonar driver nodes to the launch file:

  * For the first node, assign an anonymous name
  * Define the second node to be executed in a ``fake_ns`` namespace.
