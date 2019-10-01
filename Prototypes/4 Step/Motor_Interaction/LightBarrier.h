#ifndef LightBarrier_h
#define LightBarrier_h

#include "Arduino.h"

class LightBarrier
{
  public:
    LightBarrier(int pin, int amountHoles);
    boolean notification();
    int getCounter();
    void setCounter(int newCounter);

  private:
    int _lightBarrierPin;
    int _counter;
    int _oldValue;
    int _notification;
};

#endif
