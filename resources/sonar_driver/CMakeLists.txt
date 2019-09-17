cmake_minimum_required(VERSION 2.8.3)
project(sonar_driver)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  serial
  message_generation
)

# Add message files
add_message_files(FILES
  RangeImu.msg
)

# Generate services in the 'srv' folder
add_service_files(
  FILES
  SetSonarRange.srv
)


# Generate the messages
generate_messages(
  DEPENDENCIES
  sensor_msgs
)

# Declare a catkin package
catkin_package(
  CATKIN_DEPENDS roscpp sensor_msgs serial
)

# Where header files come from
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Compile the tests
if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  add_rostest_gtest(packet_parser_test_node test/test_packet_parser.test 
    src/test/packet_parser_test.cpp
    src/packet_parser.cpp)
  target_link_libraries(packet_parser_test_node ${catkin_LIBRARIES})
endif()

# Create a sonar hardware client node
add_executable(sonar_hardware_client_node
  src/sonar_hardware_client_node.cpp
  src/packet_parser.cpp
)

add_dependencies(sonar_hardware_client_node
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
)

target_link_libraries(sonar_hardware_client_node
  ${catkin_LIBRARIES}
)  
