#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pin);
    void activateMotor();
    void deactivateMotor();
   
  private:
    int _motorPin;
   
};

#endif
