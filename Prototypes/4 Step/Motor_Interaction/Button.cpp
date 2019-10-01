#include "Button.h"

Button::Button(int pin){
  _buttonPin = pin;
  pinMode(_buttonPin, INPUT);
  _ceroPos = false;
}

void Button::noticeButton(){
  int buttonState = digitalRead(_buttonPin);
  if (buttonState == HIGH) {
    _ceroPos = true;
  } else {
    _ceroPos = false;
  }
}

boolean Button::getCeroPosition(){
  return _ceroPos;
}
