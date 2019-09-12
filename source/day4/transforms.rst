Transforms
------------

In the last workshop, you wrote a driver for an IMU and ultrasonic sensor
and displayed it in RViz.

In this workshop, you will define a transform between your sensors.
The goal is to see your ultrasonic sensor moving in RViz when you move your IMU.

Currently, there are no transforms in your system when you launch your driver.
That means you can not visualize your data properly.
Transforms are necessary to tell the system
from which location the data is coming from.

Currently when you visualize your sensor, it is by default tied to the **map**
frame which is not right because sensor and map are not the same thing.

Static transform
^^^^^^^^^^^^^^^^^

First, let's try adding a static transform.

Static transform is broadcasted and latched to */tf_static* topic and will not
change unless ordered.

For this case,
we need to create a transform between **map** frame (parent)
and **imu_link** frame (child).
This is necessary because the system wants to know where in the world
your sensor is located. **map** frame serves as the world
and is set as a fixed frame so that everything else is
taken relative to **map** origin.
**imu_link** serves as the frame for your sensor.

1.  Run **roscore**.

2.  Using *static_transform_publisher*, create a transform between
    **map** and **imu_link**. Use http://wiki.ros.org/tf2_ros#static_transform_publisher
    as a reference as well as the presentation slides.
    You can keep the rotation zero for now but change the translation
    so that **imu_link** would be 1 meter higher than the **map** frame.

3.  Launch **rqt** from terminal.
    On the top bar, go to
    Plugins -> Visualization -> TF Tree.
    This will show you the current transforms in the system.
    And should look like this:

    .. figure:: ../_static/pics/tftreestatic.png
        :scale: 70%

4.  If you see this result, continue to step 5, if not, go back to 2.

5.  Now launch *sonar_driver_visualize.launch*
    with argument **imu_frame:=imu_link**.

6.  In the RViz windows,
    you should see the origin of IMU pose and range be set to
    1 meter above ground.

7. If everything works, shut down all ROS programs and continue to next task.

Dynamic transform
^^^^^^^^^^^^^^^^^

As our goal was to see the ultrasonic range be rotated as we rotate the IMU,
we need a transform that moves according to IMU readings.

This is where transform programming comes in play.

1.  First, add *tf2_ros* in your CMakeLists.txt under *find_package*.

2.  Use this `this <http://wiki.ros.org/tf2/Tutorials/Writing%20a%20tf2%20broadcaster%20%28C%2B%2B%29>`_
    tutorial to publish **map** to **imu_link** transform
    according to IMU data.
    You can write your code under *processSonarDataframe()* function.
    Keep the translation the same as in the previous task but now change
    rotation to IMU data.

    Don't forget to include necessary headers.

3.  To test your code, build, source and launch *sonar_driver_visualize.launch*
    like in the previous task.

4.  Now you should see your *Range* moving.
    If not, first check if your *Fixed Frame* is set to **map**.
    If it is and *Range* is not moving,
    go back and recheck the code and launch options.

5.  If it is moving, then we can disable the IMU arrow from the left side menu
    as it is not relevant anymore.

6.  Now try turning the sensor and see if relates properly
    to real world movements.
    If yes, congratulations, you have completed the task.
    If not, go double check the transforms.

.. add tf2_ros to cmakelists

.. add includes

.. add source 
