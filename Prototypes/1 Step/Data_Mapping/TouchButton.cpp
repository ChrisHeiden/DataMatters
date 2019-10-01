//Touch realist with capacity lib
#include "TouchButton.h"

TouchButton::TouchButton(){
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void TouchButton::readTouchButton(){
   long total1 = cs.capacitiveSensor(30);
   
   if(total1 > 100)
   {
      _buttonState = true;
   }
   else
   {
      _buttonState = false;  
   }
}

boolean TouchButton::getButtonState(){
  return _buttonState; 
}



//Touch realist with ESP32
/*
#include "TouchButton.h"

TouchButton::TouchButton(int touchPin){
  _touchPin = touchPin;
  _buttonState = false;

  pinMode(_touchPin, INPUT);
  _startButtonValue = analogRead(_touchPin);
}

void TouchButton::readTouchButton(){
  short actualButtonValue = analogRead(_touchPin);

  if(_startButtonValue + 100 < actualButtonValue)
  {
    _buttonState = true;
  }
  else
  {
    _buttonState = false;  
  }
}

boolean TouchButton::getButtonState(){
  return _buttonState; 
}
  */ 
  
