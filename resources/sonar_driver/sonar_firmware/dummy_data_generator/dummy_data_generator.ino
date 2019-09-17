
// Variable where dummy data value is maintained
float x = 0;

void setup()
{ 
  Serial.begin(115200);
}

void loop()
{ 
  /*
   * Generate values linearli from 0 to 2*Pi
   */
  if (x >= 2*3.14)
  {
    x = 0;
  }
  else
  {
    x += 0.01;
  }
  
  /*
   * Data format: |roll;pitch;yaw;ax;ay;az;gx;gy;gz;range;|
   */
  
  /*
   * Orientation
   */ 

  // Roll
  Serial.print(x + 0.1);
  Serial.print(':');
  
  // Pitch
  Serial.print(x + 0.3);
  Serial.print(':');
  
  // Yaw
  Serial.print(x + 0.5);
  Serial.print(':');
  
  /*
   * Acceleration
   */

  // ax
  Serial.print(x + 0.1);
  Serial.print(':');
  
  // ay
  Serial.print(x + 0.3);
  Serial.print(':');
  
  // az
  Serial.print(x + 0.5);
  Serial.print(':');
  
  /*
   * Angular velocity
   */

  // gx
  Serial.print(x + 0.1);
  Serial.print(':');
  
  // gy
  Serial.print(x + 0.3);
  Serial.print(':');
  
  // gz
  Serial.print(x + 0.5);
  Serial.print(':');
  
  /*
   * Range
   */ 

  // Range
  Serial.print(x/3.14);
  Serial.print('\n');
  
  delay(10);
}
