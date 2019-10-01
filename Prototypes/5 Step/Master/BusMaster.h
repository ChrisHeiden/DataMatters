#include <Arduino.h>

#ifndef BusMaster_h
#define BusMaster_h

class BusMaster
{
  public:
    BusMaster(int pin);
    void sendMessage(String message);
    void sendMessage(int message);
 
  private:
    int _busPin;
};
#endif

// if -> error: new types may not be defined in a return type
// source: https://arduino.stackexchange.com/questions/22211/how-to-define-a-softwareserial-object-inside-a-class
