#ifndef BusConnection_h
#define BusConnection_h
#include "Arduino.h"

class BusConnection
{
  public:
    BusConnection(int pin);
    void sendInteger(int message);
    void sendDataStrings(String message);
  
  private:
    int _pin;  
    boolean _buttonState;
};

#endif
