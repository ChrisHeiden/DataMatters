#include "BusConnection.h"

BusConnection::BusConnection(int pin){
  _pin = pin;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW); 
}

void BusConnection::sendInteger(int message){
  digitalWrite(_pin, HIGH);  
  Serial.print(message);
  digitalWrite(_pin, LOW);  
}

void BusConnection::sendDataStrings(String message){
  digitalWrite(_pin, HIGH);  
  Serial.print(message);
  digitalWrite(_pin, LOW);  
}

