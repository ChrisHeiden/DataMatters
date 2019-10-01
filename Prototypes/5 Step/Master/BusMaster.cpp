#include "BusMaster.h"

BusMaster::BusMaster(int pin)
{
  _busPin = pin;
  digitalWrite(_busPin, HIGH);  
  pinMode(_busPin, OUTPUT);
}

void BusMaster::sendMessage(String message)
{
    Serial.println(message);
}

void BusMaster::sendMessage(int message)
{
    Serial.println(message);
}
