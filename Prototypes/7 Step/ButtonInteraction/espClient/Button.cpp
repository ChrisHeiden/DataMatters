#include "Button.h"

Button::Button(int pin){
  _buttonPin = pin;
  pinMode(_buttonPin, INPUT);
  _buttonState = false;
  _index = 0; 
  _oldIndex = -1;

  _sampleB = 0;
  _sampleC = 0;
  _lastDebounceResult = 0;
  
  _state = false;
}

void Button::noticeButtonClick(){
  _buttonState = debounce(digitalRead(_buttonPin));
  if(_buttonState == HIGH)
  {   
    if(_index != _oldIndex)
    {
       ++_index; 
       _oldIndex = _index;
       _state = true;
    }
  }
  else {
    _oldIndex = -1;
    _state = false;
  }
}

int Button::getIndex(){
  return _index;
}

int Button::setIndex(int number){
  _index = number;
}

int Button::debounce(int sampleA){
   _lastDebounceResult = (_lastDebounceResult & (sampleA | _sampleB | _sampleC) | (sampleA & _sampleB & _sampleC));
   _sampleC = _sampleB;
   _sampleB = sampleA;
   return _lastDebounceResult;
}

boolean Button::getState(){
  return _state;
}
