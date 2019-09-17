Service Server & Service Client
===============================

The first type of ROS communication that we explored was a one-way interaction called messages which are sent over channels called topics. Now we are going to explore a different communication type, which is a two-way interaction via a request from one node to another and a response from that node to the first.

After completing this exercise, you will have the answers to the following questions:
  * How to create a custom messages/services?
  * Wow to use ``message_genetation``?
  * How to implement a simple service server?
   
    
#. First, read through the ROS tutorials section on `Creating a ROS msg and srv <http://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrvhow>`_.

#. Next, navigate to the root of your ``fake_sonar_driver`` package and create a subdirectory named ``srv`` for our custom service. Our service will enable changing the sonar's field of view (FOV), which is published as part of the ``Range`` message.

#. In the ``srv`` directory, create a service file named ``SetSonarFOV.srv`` with the following request and response parts:

   .. code-block:: python

      # Sets .
      float64 fov_to_set
      ---
      float64 set_fov

#. Make changes in your ``package.xml`` and ``CMakeLists.txt`` to include ``message_generation`` for this service.

#. Test it out:

   .. code-block:: bash

      rossrv show fake_sonar_driver SetSonarFOV
   

#. Good Job! It's now time to learn the steps needed to create a service server (waits for request and comes up with response) and client (makes request for info then waits for response).

#. Complete the `Writing a Simple Service and Client (C++) <http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29>`_ tutorial.

#. Now that you know how service server and client are implemented in nodes, let's add a service server to ``fake_sonar_driver_node``.

#. Add the following functionality to our fake sonar node:

   * the node advertises a service on topic ``/set_sonar_fov`` 
   * the service type is ``fake_sonar_driver/SetSonarFOV``
   * the server will check ``fov_to_set`` field and responds back with the same value in ``set_fov`` field.

#. Test the server with :code:`rossrv call /sonar_distance 1.4` and show the result to the instructor.

#. Improve the ``fake_sonar_driver_node`` such that the ``fov_to_set`` value would be updated into the ``/sonar_distance`` topic. The easies way to do this is by defining ``field_of_view`` as a global variable:

   .. code-block:: c++

     #include <...>

     double field_of_view;

     bool callback_function_for_server(...)
     {
       // set field_of_view here
     }

     int main(...)
     {
       // use field_of_view here
     }
     ...
      

#. Would it be awesome to visualize the sonar range and its field of view graphically? In ROS, this is peace of cake:

   * Open a new terminal and type: :code:`rviz` 
   * In RViz, click the ``add`` button on the Displays panel (the one on the left side).
   * Select the ``By topic`` tab and double-click on the ``/sonar_distance`` topic.

#. Open another terminal and change the field of view with the :code:`rossrv call` command. See if you notice any changes in RViz.

#. Present your solution to the instructor. Congratulations, you are now ready to face the challenges in day 3!

Bonus task
----------

Currently our fake sonar node has publishers and subscribers laying next to main(). However, to make our code modular, we should restructure it and place the publisher, service server, and callback functions into a separate ``FakeSonarDriver`` class.

#. Create the ``src/fake_sonar_driver.cpp`` and ``include/fake_sonar_driver/fake_sonar_driver.h`` files.  
#. Replace the existing while loop with a `timer <http://wiki.ros.org/roscpp/Overview/Timers>`_ that would update the sine() value in the class.
#. The :code:`main()` function should now simply create the ``FakeSonarDriver`` object and spin forever using ``ros::spin()``.
