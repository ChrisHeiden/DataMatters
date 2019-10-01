#include "Motor.h"

Motor::Motor(int pinA, int pinB){
  _motorPinA = pinA;
  _motorPinB = pinB;
  pinMode(_motorPinA,OUTPUT);
  pinMode(_motorPinB,OUTPUT);  
  _stoppedMotor = true;
}


void Motor::deactivateMotor(){
  digitalWrite(_motorPinA,LOW);
  digitalWrite(_motorPinB,LOW);  
  _stoppedMotor = false;
}

void Motor::clockwise(){
  digitalWrite(_motorPinA,HIGH);
  digitalWrite(_motorPinB,LOW); 
  _stoppedMotor = false;
}

void Motor::counterClockwise(){
  digitalWrite(_motorPinA,LOW);
  digitalWrite(_motorPinB,HIGH);  
   _stoppedMotor = false;
}

boolean Motor::getMotorStopped(){
  return _stoppedMotor;
}
