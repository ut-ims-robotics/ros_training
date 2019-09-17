Custom Hardware Driver
======================

In this exercise, we are going to replace our ``fake_sonar_driver`` package with the real hardware. To get started, you are provided with a ``sonar_driver`` template that implements core communication between the driver node and the hardware. Your task is to complete the given base code with the missing pieces and integrate the driver with ROS.

Hardware
--------

Our device consists of:

  + Arduino Nano v3
  + Pololu AltIMU-10v4
  + Ultrasound sensor HC-SR04

Preparing the sonar_driver
--------------------------

#. Update the ``ros_training`` repository located in your home folder:

   .. code-block:: bash

      cd ~/ros_training
      git pull

#. Copy the ``sonar_driver`` package to your ``catkin_ws`` workspace:

   .. code-block:: bash

      cp -r ~/ros_training/resources/sonar_driver ~/catkin_ws/src/

#. Find and fix the bug deliberately left in the package.

Implement the driver
--------------------

Once you got the package compiling, open the ``sonar_hardware_client_node.cpp``. Follow the :code:`TODO:` labels in the code to complete the following tasks:

1. Get the following parameters from ROS parameter server:
   
   +-----------------+---------------+
   | Parameter       | Default value |
   +=================+===============+
   | serial/port     | dev/ttyUSB0   |
   +-----------------+---------------+
   | serial/baudrate | 115200        |
   +-----------------+---------------+
   | imu/frame_id    | map           |
   +-----------------+---------------+

2. Set up the following publishers and services:

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

3. Create a timer to periodically read data from the serial buffer:

   * set the period to 0.05 s (20 Hz)  
   * set the callback function to :code:`SonarHardwareClient::read`

4. Clamp the sonar range value between 0 and 2.

5. Implement the function for processing the sonar data:

   * Create and publish IMU data as ``sensor_msgs::Imu`` message 
   * Create and publish sonar data as ``sensor_msgs::Range`` message 
   * Create and publish our custom ``sonar_driver::RangeImu`` message


