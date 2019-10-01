#ifndef BusConnection_h
#define BusConnection_h
// source: https://arduino.stackexchange.com/questions/22211/how-to-define-a-softwareserial-object-inside-a-class
#include "Arduino.h"
#include <SoftwareSerial.h>

class BusConnection
{
  public:
    BusConnection(int rx,int tx);
    void readMessages();
 
  private:
      SoftwareSerial serial;
};// if -> error: new types may not be defined in a return type
#endif
