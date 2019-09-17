#include "sonar_driver/packet_parser.h"
#include <boost/algorithm/string.hpp>

namespace sonar_driver
{
Dataframe parsePacket(const std::string& raw_packet_string
  , unsigned int min_packet_length
  , unsigned int min_packet_size
  , const std::string& separator)
{
  // Check the lenght of the packet
  if(raw_packet_string.length() < min_packet_size)
  {
    throw std::runtime_error("The length of the packet shoud be " + std::to_string(min_packet_length) 
      + " but got " + std::to_string(raw_packet_string.length()));
  }

  // String vector that will contain the raw data. Read the serial port and pass the result to the splitting function
  std::vector<std::string> raw_packet_substrings;
  boost::split(raw_packet_substrings, raw_packet_string, boost::is_any_of(separator));

  // Check the size of the packet
  if (raw_packet_substrings.size() < min_packet_size)
  {
    throw std::runtime_error("The size of the packet shoud be " + std::to_string(min_packet_size) 
      + " but got " + std::to_string(raw_packet_substrings.size()));
  }

  // Convert the raw data strings to numerical values
  Dataframe dataframe;
  dataframe.imu_roll  = atof(raw_packet_substrings.at(0).c_str());
  dataframe.imu_pitch = atof(raw_packet_substrings.at(1).c_str());
  dataframe.imu_yaw   = atof(raw_packet_substrings.at(2).c_str());

  dataframe.imu_accel_x = atof(raw_packet_substrings.at(3).c_str());
  dataframe.imu_accel_y = atof(raw_packet_substrings.at(4).c_str());
  dataframe.imu_accel_z = atof(raw_packet_substrings.at(5).c_str());

  dataframe.imu_gyro_x = atof(raw_packet_substrings.at(6).c_str());
  dataframe.imu_gyro_y = atof(raw_packet_substrings.at(7).c_str());
  dataframe.imu_gyro_z = atof(raw_packet_substrings.at(8).c_str());

  dataframe.range     = atof(raw_packet_substrings.at(9).c_str());

  // Return the parsed data
  return dataframe;
}
} // sonar_driver namespace