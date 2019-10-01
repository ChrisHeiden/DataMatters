#include "HallSensor.h"

HallSensor::HallSensor(int pin){
  _hallSensorPin = pin;
  _hallSensorState = false;
  pinMode(_hallSensorPin, INPUT);
}

void HallSensor::readHallSensor(){
  int state = digitalRead(_hallSensorPin);

  if(state != _hallSensorState)
  {
    _countTurns++;
    _hallSensorState = state;
  }
}

void HallSensor::setCountTurns(short counter){
  _countTurns = counter;
}


short HallSensor::getCountTurns(){
  return _countTurns;
}

void HallSensor::printCountTurns(){
  Serial.print("Count turns: ");
  Serial.println(_countTurns);
  Serial.print("HallSensorState: ");
  Serial.println(_hallSensorState);}
