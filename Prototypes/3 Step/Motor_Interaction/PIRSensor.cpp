#include "PIRSensor.h"

PIRSensor::PIRSensor(int pin){
  _pirSensorPin = pin;
  pinMode(_pirSensorPin, INPUT);     
}

void PIRSensor::readSensor(){

  _pirSensorValue = digitalRead(_pirSensorPin);   // read sensor value
  if (_pirSensorValue == HIGH) {    
    Serial.println("find");       
    //_pirSensorValue = true;
  } 
  else {
    Serial.println("not find");       
    //_pirSensorValue = false;
  }
}

int PIRSensor::getSensorValue(){
  return _pirSensorValue;
}
