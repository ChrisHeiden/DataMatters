#include "PIRSensor.h"

PIRSensor::PIRSensor(int pin){
  _pirSensorPin = pin;
  pinMode(_pirSensorPin, INPUT);     
}

void PIRSensor::readSensor(){

  _pirSensorValue = digitalRead(_pirSensorPin);   // read sensor value
  if (_pirSensorValue == HIGH) {           
    Serial.println("Motion detected!"); 
  } 
  else {
    Serial.println("Motion stopped!");
  }
  /*
  _pirSensorValue = digitalRead(_pirSensorPin);
  */
}

int PIRSensor::getSensorValue(){
  return _pirSensorValue;
}
