#ifndef PIRSensor_h
#define PIRSensor_h

#include "Arduino.h"

class PIRSensor
{
  public:
    PIRSensor(int pin);
    void readSensor();
    int getSensorValue();
   
  private:
    int _pirSensorPin;
    int _pirSensorValue;
};

#endif
