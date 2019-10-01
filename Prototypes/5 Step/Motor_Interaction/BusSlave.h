#ifndef BusSlave_h
#define BusSlave_h

#include "Arduino.h"

class BusSlave
{
  public:
    BusSlave(int pin);
    void readBusMessage();
    String getBusMessage();

  
  private:
    int _BusSlavePin;
    String _message;
};

#endif
