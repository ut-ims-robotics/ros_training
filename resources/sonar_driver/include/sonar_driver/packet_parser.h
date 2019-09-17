#ifndef SONAR_DRIVER__PACKET_PARSER_H
#define SONAR_DRIVER__PACKET_PARSER_H

#include <string>
#include "sonar_driver/sonar_driver_dataframe.h"
#include <exception>

namespace sonar_driver
{
/**
 * @brief Process the packet. The correctly formatted data packet is expected to have the following structure: 
 *      imu_x:imu_y:imu_z:a_x:a_y:a_z:g_x:g_y:g_z:sonar_dist\n, e.g., 
 *      1.11:2.22:3.33:4.44:5.55:6.66:7.77:8.88:9.99:1.23\n 
 * where each value is a float.
 * 
 * @param raw_packet_string 
 * @param min_packet_length minimum expected lenth of dataframe
 * @param min_packet_size expected amount of data
 * @param separator expected data separator symbol
 * @return const Dataframe& contains roll, pitch, yaw, range 
 */
Dataframe parsePacket( const std::string& raw_packet_string
  , unsigned int min_packet_length = 49
  , unsigned int min_packet_size = 10
  , const std::string& separator = ":");

}// sonar_driver namespace

#endif