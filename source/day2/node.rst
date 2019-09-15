Creating Nodes
==============

In this exercise, you will create a simple ROS node into your new ``sonar_driver`` package.

#. In the ``sonar_driver`` package folder, edit the ``CMakeLists.txt`` file using ``gedit``. Browse through the example rules, and add an executable(``add_executable``), node named ``sonar_driver_node``, source file named ``sonar_driver.cpp``. Also within the ``CMakeLists.txt``, make sure your new sonar_driver_node gets linked ('target_link_libraries') to the catkin libraries.


   For reference, take a look at `Understanding Nodes <http://wiki.ros.org/ROS/Tutorials/UnderstandingNodes>`_.

   .. code-block:: cmake

      add_compile_options(-std=c++11)
      add_executable(sonar_driver_node src/sonar_driver_node.cpp)
      target_link_libraries(sonar_driver_node ${catkin_LIBRARIES})
    

   These lines can be placed anywhere in `CMakeLists.txt`, but a good approach is:

   * Uncomment existing template examples for `add_compile_options` near the top (just below `project()`)
   * Uncomment and edit existing template examples for `add_executable` and `target_link_libraries` near the bottom
   * This helps make sure these rules are defined in the correct order, and makes it easy to remember the proper syntax.

   .. note:: You're also allowed to spread most of the CMakeLists rules across multiple lines, as shown in the ``target_link_libraries`` template code.

#. In the package folder, create the file ``src/sonar_driver_node.cpp`` and open it in a text editor.

#. Add the ros header (include ros.h).

   .. code-block:: c++

      /**
      **  Simple ROS Node
      **/
      #include <ros/ros.h>
      

#. Add a main function (typical in c++ programs).

   .. code-block:: c++

      /**
      **  Simple ROS Node
      **/
      #include <ros/ros.h>

      int main(int argc, char* argv[])
      {

      }

#. Initialize your ROS node (within the main).

   .. code-block:: c++

      /**
      **  Simple ROS Node
      **/
      #include <ros/ros.h>

      int main(int argc, char* argv[])
      {
        // This must be called before anything else ROS-related
        ros::init(argc, argv, "sonar_driver_node");
      }

#. Create a ROS node handle.

   .. code-block:: c++

      

      /**
      **  Simple ROS Node
      **/
      #include <ros/ros.h>
 
      int main(int argc, char* argv[])
      {
        // This must be called before anything else ROS-related
        ros::init(argc, argv, "sonar_driver_node");
 
        // Create a ROS node handle
        ros::NodeHandle nh;
      }

#. Print a "Hello World" message using ROS print tools.

   .. code-block:: c++

      /**
      **  Simple ROS Node
      **/
      #include <ros/ros.h>

      int main(int argc, char* argv[])
      {
        // This must be called before anything else ROS-related
        ros::init(argc, argv, "sonar_driver_node");

        // Create a ROS node handle
        ros::NodeHandle nh;

        ROS_INFO("Hello, World!");
      }

#. Do not exit the program automatically - keep the node alive.

   .. code-block:: c++

      /**
      **  Simple ROS Node
      **/
      #include <ros/ros.h>

      int main(int argc, char* argv[])
      {
        // This must be called before anything else ROS-related
        ros::init(argc, argv, "sonar_driver_node");

        // Create a ROS node handle
        ros::NodeHandle nh;

        ROS_INFO("Hello, World!");

        // Don't exit the program.
        ros::spin();
      }

   ``ROS_INFO`` is one of the many `logging methods <http://wiki.ros.org/roscpp/Overview/Logging>`_.

   * It will print the message to the terminal output, and send it to the ``/rosout`` topic for other nodes to monitor.
   * There are 5 levels of logging: ``DEBUG, INFO, WARNING, ERROR, & FATAL``.
   * To use a different logging level, replace INFO in ``ROS_INFO`` or ``ROS_INFO_STREAM`` with the appropriate level.
   * Use ``ROS_INFO`` for printf-style logging, and ``ROS_INFO_STREAM`` for cout-style logging.

#. Build your program (node), by running ``catkin build`` in a terminal window

   * Remember that you must run `catkin build` from within your `catkin_ws` (or any subdirectory)
   * This will build all of the programs, libraries, etc. in ``sonar_driver`` package.
   * In this case, it's just a single ROS node ``sonar_driver_node``

Run a Node
----------

#. Open a terminal and start the ROS master.

   .. code-block:: bash

      roscore
   .. note:: The ROS Master must be running before any ROS nodes can function.

#. Open a second terminal to run your node.

   * In a previous exercise, we added a line to our `.bashrc` to automatically source `devel/setup.bash` in new terminal windows
   * This will automatically export the results of the build into your new terminal session.
   * If you're reusing an existing terminal, you'll need to manually source the setup files (since we added a new node):

     .. code-block:: bash

        source ~/catkin_ws/devel/setup.bash

#. Run your node.

   .. code-block:: bash

      rosrun sonar_driver sonar_driver_node

   .. tip:: This runs the program we just created. Remember to use TAB to help speed-up typing and reduce errors.

#. In a third terminal, check what nodes are running.

   .. code-block:: bash

      rosnode list
      
   In addition to the /rosout node, you should now see a new /sonar_driver_node listed.

#. Enter :code:`rosnode kill /sonar_driver_node`. This will stop the node.

   .. note:: It is more common to use :kbd:`Ctrl+C` to stop a running node in the current terminal window.


Challenge
---------

#. Modify the node so that it prints your name. This will require you to run through the build process again.

#. Demonstrate the working node to the instructor.

