#ifndef HallSensor_h
#define HallSensor_h

#include "Arduino.h"

class HallSensor
{
  public:
    HallSensor(int pin);
    void readHallSensor();
    void setCountTurns(short counter);
    short getCountTurns();
    void printCountTurns();
   
  private:
    int _hallSensorPin;
    boolean _hallSensorState;
    short _countTurns;
};

#endif
