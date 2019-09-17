#include "ros/ros.h"
#include <serial/serial.h>
#include "sensor_msgs/Range.h"
#include "sensor_msgs/Imu.h"
#include "geometry_msgs/PoseStamped.h"
#include <tf2/LinearMath/Quaternion.h>

#include "sonar_driver/RangeImu.h"
#include "sonar_driver/SetSonarRange.h"
#include "sonar_driver/sonar_driver_dataframe.h"
#include "sonar_driver/packet_parser.h"

/**
 * @brief Object that handles communication with an IMU + sonar hardware via serial port.
 * Publishes the processed IMU data as geometry_msgs::Pose and sonar data as sensor_msgs::Range.
 * 
 */
class SonarHardwareClient
{
public:
  /**
   * @brief Construct a new Sonar Hardware Client object
   */
  SonarHardwareClient()
  {
    ROS_INFO("Sonar Hardware Client is starting...");
    
    /*
     *
     * TASK 1. 
     *
     */

    /*
     * TODO: Get parameters from ROS parameter server
     */

     /*
      *
      * 
      *
      *
      */


    std::string serial_port;
    int baudrate;

    /*
     * GET serial_port, baudrate, imu_frame_id values from parameter server
     */

    ROS_INFO_STREAM("Serial port: '" << serial_port << "'");
    ROS_INFO_STREAM("Baudrate: '" << baudrate << "'");
    ROS_INFO_STREAM("IMU frame ID: '" << imu_frame_id_ << "'");    

    /*
     * configure serial
     */ 
    serial_.setPort(serial_port);
    serial_.setBaudrate(baudrate);
    serial::Timeout timeout = serial::Timeout::simpleTimeout(1000);
    serial_.setTimeout(timeout);

    /*
     * Open the serial port
     */
    connect();

    /*
     *
     * TASK 2.
     *
     */

    /*
     * TODO: Set up the publishers and sonar range setting service
     */

    /*
     * imu_publisher_ = ...;
     * sonar_publisher_ = ...;
     * range_imu_publisher_ = ...;
     * set_sonar_range_server_ = ...;
     */


    /*
     *
     * TASK 3.
     *
     */

    /*
     * TODO: Create a timer to periodically reads data from the serial buffer
     */

    /*
     * timer_ = ...;
     */



    ROS_INFO("Sonar Hardware Client is ready.");
  }

  /**
   * @brief Service for the set sonar range server. Allowed range is from 0.1 m to 2 m.
   * Values bigger or smaller than that are clipped to closest max/min
   * 
   * @param req 
   * @param res 
   * @return true 
   * @return false 
   */

  bool setSonarRangeService(sonar_driver::SetSonarRange::Request &req, sonar_driver::SetSonarRange::Response &res)
  {
    
    /*
     *
     * TASK 4.
     *
     */

     /*
      * TODO:  Clamp the value between 0 and 2
      */


    return true;
  }

  /**
   * @brief Establishes connection with serial port with preconfigured parameters.
   * 
   */
  void connect()
  {
    ROS_DEBUG("Opening the serial port ...");
    if (serial_.isOpen())
    {
      // Connection already open, close it before reconnecting
      serial_.close();
    }

    do
    {
      // Try to open the serial port
      try
      {
        serial_.open();
      }
      catch (serial::IOException e)
      {
        ROS_ERROR_STREAM("Unable to open port '" << serial_.getPort() << "': " << e.what());
      }
      catch (serial::SerialException e)
      {
        ROS_ERROR_STREAM("Unable to open port '" << serial_.getPort() << "': " << e.what());
      }

      if (serial_.isOpen())
      {
        ROS_DEBUG_STREAM("Connected to serial port '" << serial_.getPort() << "'");
      }
      else
      {
        ROS_WARN("Failed to open Serial port, retrying after 1 sec...");
      }
      ros::Duration(1).sleep();
    } 
    while (!serial_.isOpen() && ros::ok());

    ROS_INFO("Serial port opened.");
  }

  /**
   * @brief Timer callback that periodically reads the serial port and processes the data.
   * The dataframe is expected to end with either '\n' or '\r' character
   * 
   * @param event 
   */
  void read(const ros::TimerEvent& event)
  {
    std::string buffer;
    try
    {
      size_t bytes_available = serial_.available();
      if (!bytes_available)
      {
        // No data to read
        return;
      }
      serial_.read(buffer, bytes_available);
    }
    catch(serial::IOException e)
    {
      ROS_WARN_STREAM(e.what() << ". Trying to reconnect");
      connect();
    }
    catch(serial::SerialException e)
    {
      ROS_WARN_STREAM(e.what() << ". Trying to reconnect");
      connect();
    }

    std::string raw_packet_string;
    while(buffer.size())
    {
      if(buffer[0] == '\r' || buffer[0] == '\n')
      {
        try
        {
          sonar_dataframe_ = sonar_driver::parsePacket(raw_packet_string);
          processSonarDataframe();
        }
        catch(const std::exception& e)
        {
          // ROS_WARN_STREAM(e.what());
        }
        raw_packet_string = "";
      }
      else
      {
        raw_packet_string.push_back(buffer[0]);
      }

      // Remove the first element of the buffer
      buffer.erase(buffer.begin());
    }
  }

  /**
   * @brief Converts the contents of Dataframe to PoseStamped, Range and RangeImu messages
   * 
   */
  void processSonarDataframe()
  {

    // Prepare quaternion from rpy. (required by the sensor_msgs::Imu::Orientation)
    tf2::Quaternion quaternion;
    quaternion.setRPY(sonar_dataframe_.imu_roll, sonar_dataframe_.imu_pitch, sonar_dataframe_.imu_yaw);
    quaternion.normalize();


    /*
     *
     *
     * TASK 5.
     *
     *
     *
     */ 
    

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * TODO: Create and publish IMU data as sensor_msgs::Imu message 
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    /*
     * sensor_msgs::Imu imu_msg;
     *      .          . 
     *      .          . 
     *      .          . 
     *
     * imu_publisher_.publish(imu_msg);
     */



    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * TODO: Create and publish sonar data as sensor_msgs::Range message
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    /*
     * sensor_msgs::Range range_msg;
     *  .          . 
     *  .          . 
     *  .          . 
     * sonar_publisher_.publish(range_msg);
     */



    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * TODO: Create and publish our custom sonar_driver::RangeImu message
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    /* sonar_driver::RangeImu range_imu_msg;
     *      .          . 
     *      .          . 
     *      .          . 
     * range_imu_publisher_.publish(range_imu_msg);
    */
  }

private:

  ros::NodeHandle nh_;                        ///< Handles ROS communication
  ros::Publisher imu_publisher_;              ///< Publisher for IMU data
  // TODO: Publisher for sonar data
  // TODO: Publisher for combined range + pose message 
  ros::ServiceServer set_sonar_range_server_; ///< Handles requests for setting the sonar range

  serial::Serial serial_;                     ///< Object that handles low level serial communication
  sonar_driver::Dataframe sonar_dataframe_;   ///< Variable where sonar data is stored
  double sonar_range_ = 1.8;                  ///< Current range of the sonar
  const double sonar_min_range_ = 0.1;        ///< Minimum sonar range
  const double sonar_max_range_ = 2;          ///< Maximum sonar range
  std::string imu_frame_id_;                  ///< IMU frame id
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Main
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int main(int argc, char** argv)
{
  // Initialize ROS node
  ros::init(argc, argv, "sonar_hardware_client_node");

  // Create sonar hardware client that handles communication and data processing
  SonarHardwareClient sonar_hardware_client;

  // Start spinning the callback queues
  ros::spin();
}
