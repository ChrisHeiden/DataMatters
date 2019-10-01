#include "Motor.h"

Motor::Motor(int pin){
  _motorPin = pin;
  pinMode(_motorPin, OUTPUT);
}

void Motor::activateMotor(){
  digitalWrite(_motorPin, HIGH);
}

void Motor::deactivateMotor(){
  digitalWrite(_motorPin, LOW);
}
