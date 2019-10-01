#include "Motor.h"

Motor::Motor(int pinA, int pinB){
  _motorPinA = pinA;
  _motorPinB = pinB;
  pinMode(_motorPinA,OUTPUT);
  pinMode(_motorPinB,OUTPUT);  
}

void Motor::deactivateMotor(){
  digitalWrite(_motorPinA,LOW);
  digitalWrite(_motorPinB,LOW);    
}

void Motor::clockwise(){
  digitalWrite(_motorPinA,HIGH);
  digitalWrite(_motorPinB,LOW); 
}

void Motor::counterClockwise(){
  digitalWrite(_motorPinA,LOW);
  digitalWrite(_motorPinB,HIGH);  
}
