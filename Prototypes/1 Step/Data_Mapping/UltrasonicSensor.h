#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h

#include "Arduino.h"


class UltrasonicSensor
{
  public:
    UltrasonicSensor(int trigPin, int echoPin);
    void activateUltrasonicSensor();
    void deactivateUltrasonicSensor();
   
  private:
   int _sensorpin = 0;                 // analog pin used to connect the sharp sensor
   int _val = 0; 
};

#endif
