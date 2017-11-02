#include "Gyro_h"

GyroSensor :: GyroSensor(void)
{
 bno = Adafruit_BNO055(55);
 if(!bno.begin())
 {
   // Blink led?
   while(1);
 }
 
 bno.setExtCrystalUse(true);
}

void GyroSensor :: getUpdate(void)
{
  sensors_event_t event;
  bno.getEvent(&event);
  
  yaw   = event.orientation.x;
  roll  = event.orientation.y;
  pitch = event.orientation.z;
  
  sys = gyro = accel = mag = 0;
  bno.getCalibration(&sys, &gyro, &accel, &mag);
}
  
  
  
  
  
  
}
