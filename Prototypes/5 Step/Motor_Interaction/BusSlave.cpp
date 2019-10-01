#include "BusSlave.h"

BusSlave::BusSlave(int pin)
{
  _BusSlavePin = pin;
  pinMode(_BusSlavePin, OUTPUT);
  digitalWrite(_BusSlavePin, LOW);      
}

void BusSlave::readBusMessage()
{
   while (Serial.available())                  
   {
        _message = Serial.readString();         
   }
}

String BusSlave::getBusMessage()
{
  return _message;
}
