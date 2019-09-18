Custom Hardware Driver
======================

In this exercise, we are going to replace our ``fake_sonar_driver`` package with the real hardware. To get started, you are provided with a ``sonar_driver`` template that implements core communication between the driver node and the hardware. Your task is to complete the given base code with the missing pieces and integrate the driver with ROS.

Motivation
----------

The majority of the work will be done in ``sonar_hardware_client_node.cpp`` file, where driver communication takes place. The structure of this node is a bit unconventional: instead of everyting defined in ``main`` we create a custom Class that implemets the hardware communication functionalities. This "Class based" approach is actually very common in industrial applications where many different libraries are integrated to a single application.

Hardware
--------

Our device consists of:

  + Arduino Nano v3
  + Pololu AltIMU-10v4
  + Ultrasound sensor HC-SR04

Get the base package for the sonar_driver
-----------------------------------------

#. Update the ``ros_training`` repository located in your home folder:

   .. code-block:: bash

      cd ~/ros_training
      git pull

#. Copy the ``sonar_driver`` package to your ``catkin_ws`` workspace:

   .. code-block:: bash

      cp -r ~/ros_training/resources/sonar_driver ~/catkin_ws/src/

#. Find and fix the bug deliberately left in the package.

Complete our broken driver code by filling in the missing parts
---------------------------------------------------------------
This work will be combining the knowledge you learned from the past 2 days. Our motivation is to encourage you to work through the familiar problems in a new perspective. For that there will be no detailed step-by-step guide in this assignment.

Once you got the package compiling, open the ``sonar_hardware_client_node.cpp``. Follow the :code:`TODO:` labels in the code to complete the following tasks:

1. TODO: Get the following parameters from ROS parameter server:
   
   +-----------------+---------------+
   | Parameter       | Default value |
   +=================+===============+
   | serial/port     | dev/ttyUSB0   |
   +-----------------+---------------+
   | serial/baudrate | 115200        |
   +-----------------+---------------+
   | imu/frame_id    | map           |
   +-----------------+---------------+

2. TODO: Set up the following publishers and services:

   +---------------------+------------------------+--------------------+
   | Publisher name      | Datatype               | topic              |
   +=====================+========================+====================+
   | imu_publisher       | sensor_msgs::Imu       | imu                |
   +---------------------+------------------------+--------------------+
   | sonar_publisher     | sensor_msgs::Range     | sonar_distance     |
   +---------------------+------------------------+--------------------+
   | range_imu_publisher | sonar_driver::RangeImu | range_imu_combined |
   +---------------------+------------------------+--------------------+

   +------------------------+-----------------------------+-----------------+
   | Service name           | Datatype                    | topic           |
   +========================+=============================+=================+
   | set_sonar_range_server | sonar_driver::SetSonarRange | set_sonar_range |
   +------------------------+-----------------------------+-----------------+

   * Create a custom message for ``range_imu_publisher`` that combines ``sensor_msgs/Range`` and ``sensor_msgs/Imu``.

3. TODO: Create a timer to periodically read data from the serial buffer:

   * set the period to 0.05 s (20 Hz)  
   * set the callback function to :code:`SonarHardwareClient::read`

4. TODO: Clamp the sonar range value between 0 and 2.

5. TODO: Implement the function for processing the sonar data:

   * Create and publish IMU data as ``sensor_msgs::Imu`` message 
   * Create and publish sonar data as ``sensor_msgs::Range`` message 
   * Create and publish our custom ``sonar_driver::RangeImu`` message


