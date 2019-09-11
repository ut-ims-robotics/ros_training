##############
System Setup
##############

This section gives brief instructions on how to set up laptops for this training.
The training is tested on `ROS Kinetic Kame <http://wiki.ros.org/kinetic/Installation>`_ distribution for Ubuntu 16.04. 

Install ROS with dependencies
-----------------------------

#. Set up ROS keys.

   .. code-block:: bash
   
      sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
      sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
      sudo apt update
       
#. Get the dependency list from github and install.

   .. code-block:: bash

      PKG_LIST=$(wget -O- -q https://github.com/ut-ims-robotics/ros_training/raw/master/config/dependencies_apt.txt)
      echo "$PKG_LIST" | egrep '^[^#;]' | xargs -r apt -q install
      sudo rosdep init
      rosdep update

#. Prepare coffee...
   
#. Enjoy coffee...
   
#. Prepare more coffee, because it is still installing...

Install librealsense 
--------------------
  .. code-block:: bash

     TMP_DIR=$(mktemp -d)
     cd $TMP_DIR
     git clone https://github.com/IntelRealSense/librealsense.git
     cd librealsense
     cmake .
     make -j4
     sudo make install
     sudo cp config/99-realsense-libusb.rules /etc/udev/rules.d/
     sudo udevadm control --reload-rules && udevadm trigger
     cd ~ && rm -fr $TMP_DIR
..

Install proto3 for cartographer
-------------------------------
  .. code-block:: bash

     TMP_DIR=$(mktemp -d)
     cd $TMP_DIR
     git clone https://github.com/google/protobuf.git
     cd protobuf
     git checkout tags/v3.4.1
     mkdir build
     cd build
     cmake -G Ninja \
       -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
       -DCMAKE_BUILD_TYPE=Release \
       -Dprotobuf_BUILD_TESTS=OFF \
       ../cmake
     ninja
     sudo ninja install
     cd ~ && rm -fr $TMP_DIR


Setup :code:`clearbot_ros_ws` workspace
---------------------------------------
  .. code-block:: bash

     source /opt/ros/kinetic/setup.bash
     mkdir -p ~/clearbot_ros_ws/src
     cd ~/clearbot_ros_ws
     wstool init src https://github.com/ut-ims-robotics/ros_training/raw/master/config/.rosinstall
     catkin init
     catkin build
   
   
Automatic sourcing
------------------
  .. code-block:: bash

     echo "source ~/clearbot_ros_ws/devel/setup.bash" >> ~/.bashrc
     source ~/.bashrc

