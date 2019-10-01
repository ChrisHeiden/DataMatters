#ifndef LightBarrier_h
#define LightBarrier_h

#include "Arduino.h"

class LightBarrier
{
  public:
    LightBarrier(int pin);
    boolean notification();
    int getCounter();
    void setupPos();
    boolean getSameValue();

  private:
    int _lightBarrierPin;
    int _counter;
    
    int _counterValArray[10] = {};
    int _index;
    boolean _sameValue;
    
};

#endif
