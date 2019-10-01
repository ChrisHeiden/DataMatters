#ifndef LightBarrier_h
#define LightBarrier_h

#include "Arduino.h"

class LightBarrier
{
  public:
    LightBarrier(int pin);
    boolean notification();
   
  private:
    int _lightBarrierPin;
};

#endif
