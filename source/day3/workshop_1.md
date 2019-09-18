# Documentation Generation

## Motivation
Now after you have successfully created a driver for our custom sonar+IMU device, the application part is completed. But it is equally important to test and document your code.
* **Document your code** because otherwise others and even at some point YOU yourself do not understand the structure of the code.
* **Test your code** because there could be many run-time specific bugs left in your code that only appear under certain conditions.

We will first start with documentation.

## Information and Resources
There are different source code documentation tools out there but Doxygen is very well known and widely used C++ documentation tool. The concept is that all you need to do is write **code comments** in a Doxygen specific syntax, and Doxygen is able to generate HTML pages from your code, which are simple to read.
* [`doxygen` generates documentation from annotated source code](http://www.doxygen.org/)

ROS provides a convenience package called `rosdoc_lite` which helps you to manage documentation tools, such as Doxygen and Sphinx.
* [`rosdoc_lite` is a ROS wrapper for doxygen](http://wiki.ros.org/rosdoc_lite)

## Problem Statement
We have completed and tested our sonar_driver program from previous workshop and we need to release the code to the public.  Your goal is to make documentation viewable in a browser.  You may accomplish this by documenting the `sonar_hardware_client_node.cpp` with `doxygen` syntax and generating documentation with `rosdoc_lite`.

## Guidance
### Annotate the Source Code

1. Open the sonar_hardware_client_node.cpp file from the previous workshop.

    1. Annotate above the `SonarHardwareClient` class:

        ``` c++
        /**
         * @brief Object that handles communication with an IMU + sonar hardware via serial port.
         * Publishes the processed IMU data as sensor_msgs::Imu and sonar data as sensor_msgs::Range.
         * 
         */
        class SonarHardwareClient
        ```

    1. Annotate above the `processSonarDataframe()` method similarly
        

    1. Annotate any class member variables that you have added. For variables we can use a simpler documentation notation `///` or `///<`:

        ``` c++
        /// my_example_variable_ documentation
        int my_example_variable_;
        ```
        or
        ``` c++
        int my_example_variable_;   ///< my_example_variable_ documentation
        ```

    1. Additional annotations may be  placed above private variables or other important code elements.

### Generate documentation

1. Install `rosdoc_lite`:

    ```
    sudo apt install ros-kinetic-rosdoc-lite
    ```

1. Build the workspace so we can produce documentation for its packages later:

     ```
     catkin build
     ```

1. Source the workspace

     ```
     source ./devel/setup.bash
     ```

1. Run `rosdoc_lite` to generate the documentation

    ```
    roscd sonar_driver
    rosdoc_lite .
    ```

### View the Documentation

1.  Open the documentation in a browser, for example in firefox:

    ```
    firefox doc/html/index.html
    ```

1. Navigate to Classes -> SonarHardwareClient and view the documentation.