Unit Testing
============

In this exercise we will write unit tests for our sonar_driver package.

Motivation
----------

The ``sonar_driver`` application is complete and documented.  Now we want to test the program to make sure it behaves as expected.

Information and Resources
-------------------------

`Google Test <https://github.com/google/googletest/blob/master/googletest/docs/primer.md>`__: C++ XUnit test framework

`rostest <http://wiki.ros.org/rostest>`__: ROS wrapper for XUnit test framework

`catkin testing <http://catkin-tools.readthedocs.io/en/latest/verbs/catkin_build.html?highlight=run_tests#building-and-running-tests>`__: Building and running tests with catkin

Problem Statement
-----------------

We have completed and and documented our ``sonar_hardware_client_node``.  We need to create a test framework so we can be sure our program runs as intended after it is built. In addition to ensuring the code runs as intended, unit tests allow you to easily check if new code changes functionality in unexpected ways.  Your goal is to create the unit test frame work and write a few tests. 

Guidance
--------

Create the unit test frame work
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
We will first create a simple test, so that you can see the workflow.

#. Create a `test` folder in the sonar_driver/src folder. If you already have one then skip to step 2. In the workspace directory:

   .. code-block:: bash

	       roscd sonar_driver
	       mkdir src/test

#. Create utest.cpp (just a random name) file in the `sonar_driver/src/test` folder:

   .. code-block:: bash

	       touch src/test/utest.cpp

#. Open utest.cpp in your code editor and include ros & gtest:

   .. code-block:: c++

	       #include <ros/ros.h>
	       #include <gtest/gtest.h>

#. Write a dummy test that will return true if executed. This will test our framework and we will replace it later with more useful tests:

   .. code-block:: c++

            TEST(TestSuite, sonar_driver_framework)
            {
              ASSERT_TRUE(true);
            }

#. Next include the general main function, which will execute the unit tests we write later:

   .. code-block:: c++

            int main(int argc, char **argv)
            {
              testing::InitGoogleTest(&argc, argv);
              return RUN_ALL_TESTS();
            }

#. Edit ``sonar_driver`` CMakeLists.txt to build the utest.cpp file. Find the comment which says "TODO: Add test targets" and replace that with:

   .. code-block:: cmake

            if(CATKIN_ENABLE_TESTING)
              find_package(rostest REQUIRED)
              add_rostest_gtest(utest_node test/utest_launch.test src/test/utest.cpp)
              target_link_libraries(utest_node ${catkin_LIBRARIES})
            endif()

#. Create a test folder under ``sonar_driver``. If you already have one, then go to the next step.

   .. code-block:: bash
            
            roscd sonar_driver
            mkdir test

#. Create a test launch file:

   .. code-block:: bash

	       touch test/utest_launch.test

#. Open the utest_launch.test file in your code editor and populate the file:

   .. code-block:: xml

            <?xml version="1.0"?>
            <launch>
                <test test-name="unit_test_node" pkg="sonar_driver" type="utest_node"/>
            </launch>

#. Build and test the framework in your package root folder

   .. code-block:: bash
        
            roscd sonar_driver
            catkin run_tests sonar_driver

   The console output should show (buried in the midst of many build messages):

   .. code-block:: bash

            [ROSTEST]-----------------------------------------------------------------------

            [sonar_driver.rosunit-unit_test_node/sonar_driver_framework][passed]

            SUMMARY
             * RESULT: SUCCESS
             * TESTS: 1
             * ERRORS: 0
             * FAILURES: 0

   This means our framework is functional and now we can add usefull unit tests.

   .. Note:: You can also run tests directly from the command line, using the launch file we made above: `rostest sonar_driver utest_launch.test`.  Note that test files are not built using the regular `catkin build` command, so use `catkin run_tests sonar_driver` instead.

Add stock publisher tests
^^^^^^^^^^^^^^^^^^^^^^^^^

#. The rostest package provides several tools for inspecting basic topic characteristics `hztest <http://wiki.ros.org/rostest/Nodes#hztest>`__, `paramtest <http://wiki.ros.org/rostest/Nodes#paramtest>`__, `publishtest <http://wiki.ros.org/rostest/Nodes#publishtest>`__.  We'll add some basic tests to verify that the ``sonar_hardware_client_node`` node is outputting the expected topics and that the messages are getting throug.

#. Add the test description to the `utest_launch.test` file:

   .. code-block:: xml

            <!-- Start the Sonar -->
            <arg name="serial_port" default="/dev/ttyUSB0"/>
            <arg name="baudrate" default="115200"/>

            <include file="$(find sonar_driver)/launch/sonar_driver.launch">
              <arg name="serial_port" value="$(arg serial_port)" />
              <arg name="baudrate" value="$(arg baudrate)" />
              <arg name="frame_id" value="map" />
            </include>

            <!-- Start the publish test -->
            <test name="publishtest" test-name="publishtest" pkg="rostest" type="publishtest">
                <rosparam>
                  topics:
                    - name: "/imu"
                      timeout: 10
                      negative: False
                    - name: "/sonar_distance"
                      timeout: 10
                      negative: False
                </rosparam>
            </test>

#. Run the test. NOTE: Your device should be connected:

   .. code-block:: bash

            catkin run_tests sonar_driver

   You should see:

	      Summary: 2 tests, 0 errors, 0 failures

#. Add a `hztest <http://wiki.ros.org/rostest/Nodes#hztest>`__ to your `utest_launch.test` file and  make it look for 50 Hz signal with 10 Hz error margin:

   .. code-block:: xml

            See http://wiki.ros.org/rostest/Nodes#hztest for an example.

Write specific unit tests
^^^^^^^^^^^^^^^^^^^^^^^^^

#. Lets now test more specific functions in our code. As an example lets test a function that is responsible for parsing raw serial strings to ``Dataframe`` structures (see /include/sonar_driver/sonar_driver_dataframe.h). In `utest.cpp`:

   .. code-block:: c++

	       #include "sonar_driver/packet_parser.h"

#. Then define a new test. Use the following code as a base structure:

   .. code-block:: c++

	 TEST(SonarDriverTestSuite, packet_parser_test)
         {
           // Define the raw messages and expected dataframes that are true
           std::map<std::string, sonar_driver::Dataframe> test_frame_map_true =
           {
             {"6.12:6.32:6.52:6.12:6.32:6.52:6.12:6.32:6.52:1.92\n", sonar_driver::Dataframe(6.12, 6.32, 6.52, 6.12, 6.32, 6.52, 6.12, 6.32, 6.52, 1.92)},
             {"1.11:2.22:3.33:4.44:5.55:6.66:7.77:8.88:9.99:1.23\n", sonar_driver::Dataframe(1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99, 1.23)}
           };
 
           // Define the raw messages and expected dataframes that fail
           std::map<std::string, sonar_driver::Dataframe> test_frame_map_false =
           {
             //
             //
             // TODO: Just like with "true" cases, define 2 or 3 "false" cases
             //
             //
           };
 
           /*
            * Run the tests on true frames
            */
           for (const auto& frame_pair_true : test_frame_map_true)
           {
             const sonar_driver::Dataframe& expected_result = frame_pair_true.second;
             sonar_driver::Dataframe result;
             try
             {
               result = sonar_driver::parsePacket(frame_pair_true.first);
             }
             catch(const std::exception& e)
             {
               std::cerr << e.what() << '\n';
             }
             
             result.print();
             ASSERT_EQ(result, expected_result) << "Incorrectly parsed true frame : " << frame_pair_true.first << ". Result is \n" << result.print();
           }
 
           /*
            * Run the tests on false frames
            */
           //
           //
           // TODO: Add the code for testing the false cases. NOTE: Pay attention to what is
           // the difference between "ASSERT_EQ" and "ASSERT_NE".
           // For more information see: https://github.com/google/googletest/blob/master/googletest/docs/primer.md
           //
           //
         } 

#. Fill the ``TODOs`` in the previous code block and run the tests

   .. code-block:: bash

            catkin run_tests sonar_driver


#. view the results of the test:

   .. code-block:: bash

	       catkin_test_results build/sonar_driver

You should see:

	Summary: 3 tests, 0 errors, 0 failures


Apply what you learned to create your own custom test
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Few ideas:

#. Test the the ``set_sonar_range`` service that you created for the sonar_driver. See if it will clamp the values correctly (should not go over 2 m or under 0.1 m).

#. Check if ``serial_port`` or ``baud_rate`` parameters are set in the parameter server: http://wiki.ros.org/rostest/Nodes#paramtest
