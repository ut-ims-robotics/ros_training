Publisher & Subscriber
======================

In this exercise, we will explore the concept of ROS messages and topics. The first type of ROS communication that we will explore is a one-way communication called messages which are sent over channels called topics. Typically one node publishes messages on a topic and another node subscribes to messages on that same topic. 

In the following we first complete couple of ROS tutorials to get familiar with how subscribers and publishers are implemented in ROS. After practicing, we add a publisher to our ``fake_sonar_driver_node``.

#. First, create a new package into your ``catkin_ws``. Name it ``beginner_tutorials`` and make it depend on ``std_msgs``, ``rospy``, and ``roscpp`` packages. 

#. Complete the `Writing a Simple Publisher and Subscriber (C++) <http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29>`_ tutorial.

#. Now that you got the nodes communicating, it is time to add a publisher to our ``sonar_driver`` package. Check out the documentation of the `sensor_msgs/Range <http://docs.ros.org/melodic/api/sensor_msgs/html/msg/Range.html>`_ message. This message is being used for devices that measure distance to an object while having a specific field of view (for example, ultrasonic, infrared, etc sensors).

#. Navigate back to the ``fake_sonar_driver`` package and open the ``fake_sonar_driver_node.cpp`` for editing. 
   
#. Add the following functionality to our fake sonar node:

  * the node publishes messages on a topic ``/sonar_distance`` 
  * the type of messages is ``sensor_msgs/Range``
  * the ``range`` field in the messages is set to 1.5


#. Test the publisher with :code:`rostopic echo /sonar_distance` and show the result to the instructor.

#. Improve the ``fake_sonar_driver_node`` to make it outputing oscilating signal in range [0-2] meters. For that you can use a ``count`` variable as was in the ``beginners_tutorials``. Simply scale it down a bit and use it as an argument of a sine() function:

   .. code-block:: c++

      x = sine(count / 100.0f) + 1; 

  .. tip:: Don't forget the :code:`#include <math.h>` to bring in the trigonometry functions to your project.

#. Let's visualize the distance value on a graph. For that, ROS has a visualization toolkit called ``rqt``.  Enter this as a command in a new terminal window.

   * In the upper menu bar, click ``Plugins`` --> ``Visualization`` --> ``Plot``
   * Specify the topic as ``/sonar_distance.range`` and you should see the range field plotted.

   .. todo:: Check the topic/field syntax!
