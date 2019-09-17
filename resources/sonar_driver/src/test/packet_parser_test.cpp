#include <ros/ros.h>
#include <gtest/gtest.h>
#include "sonar_driver/packet_parser.h"
#include <map>

/*
 * Tests if the packet parser parses the data correctly.
 */
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
    {"4.30:4.50:1.27\n", sonar_driver::Dataframe(4.1, 4.3, 4.5, 4.1, 4.3, 4.5, 4.1, 4.3, 4.5, 1.27)},
    {"1.64;1.84 2.04;0.49\n", sonar_driver::Dataframe(1.64, 1.84, 2.04, 4.1, 4.3, 4.5, 4.1, 4.3, 4.5, 0.49)},
    {"1.64:1.84 2.04:0.49", sonar_driver::Dataframe(1.64, 1.84, 4.1, 4.3, 4.5, 4.1, 4.3, 4.5, 2.04, 0.49)},
    {"", sonar_driver::Dataframe(5, 5, 5, 5, 5, 5, 5, 5, 5, 5)}
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
  for (const auto& frame_pair_false : test_frame_map_false)
  {
    const sonar_driver::Dataframe& expected_result = frame_pair_false.second;
    sonar_driver::Dataframe result;
    try
    {
      result = sonar_driver::parsePacket(frame_pair_false.first);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }

    ASSERT_NE(result, expected_result) << "Incorrectly parsed false frame : " << frame_pair_false.first;
  }
} 

/*
 * Main
 */
int main(int argc, char **argv)
{
  // Initialize the gtes
  testing::InitGoogleTest(&argc, argv);

  // Set up the test node 
  ros::init(argc, argv, "SonarDriverTestSuite");

  // Run the tests
  return RUN_ALL_TESTS();
}