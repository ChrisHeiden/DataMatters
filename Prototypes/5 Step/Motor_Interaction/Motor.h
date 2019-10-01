#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pinA, int pinB);
    void clockwise();
    void counterClockwise();
    void deactivateMotor();

  private:
    int _motorPin;
    int _motorPinA;
    int _motorPinB;   
};

#endif
