Service Server & Service Client
===============================

The first type of ROS communication that we explored was a one-way interaction called messages which are sent over channels called topics. Now we are going to explore a different communication type, which is a two-way interaction via a request from one node to another and a response from that node to the first.

In this module we first go through the ROS tutorials on how to create a service server (waits for request and comes up with response) and client (makes request for info then waits for response). Then we add a service server to our ``fake_sonar_driver_node``.

#. Complete the `Writing a Simple Service and Client (C++) <http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29>`_ tutorial.

#. Now that you are experienced in writing a service, let's

   1) create our own service and
   2) add a service server for our ``fake_sonar_driver_node``.

#. Once again navigate to your open the ``fake_sonar_driver_node.cpp`` for editing. 
   
#. Add the following functionality to our fake sonar node:

  * the node advertises a service on topic ``/set_sonar_range`` 
  * the type of messages is ``sensor_msgs/Range``
  * the ``range`` field in the messages is set to ``1.5``

#. Test the publisher with :code:`rostopic echo /sonar_distance` and show the result to the instructor.

#. Improve the ``fake_sonar_driver_node`` to make it outputing oscilating signal in range [0-2] meters. For that you can use a ``count`` variable as was in the ``beginners_tutorials``. Simply scale it down a bit and use it as an argument of a sine() function:

   .. code-block:: c++

      x = sine(count / 100.0f) + 1; 

  .. tip:: Don't forget the :code:`#include <math.h>` to bring in the trigonometry functions to your project.

