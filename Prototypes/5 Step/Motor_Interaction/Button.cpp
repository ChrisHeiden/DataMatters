#include "Button.h"

Button::Button(int pin){
  _buttonPin = pin;
  _buttonState = false;
  pinMode(_buttonPin, INPUT);
}

void Button::readButtonState(){
  int buttonState = digitalRead(_buttonPin);
  
  if (buttonState == HIGH) {
    Serial.println("Zero");
    _buttonState = true;
  }
}

boolean Button::getButtonState(){
  return _buttonState;
}

void Button::setCeroPosition(boolean pos){
  _buttonState = pos;
}
