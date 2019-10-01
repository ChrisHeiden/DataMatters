#include "LightBarrier.h"

LightBarrier::LightBarrier(int pin, int amountHoles){
  _lightBarrierPin = pin;
  pinMode(_lightBarrierPin, INPUT);
  
  _oldValue = digitalRead(_lightBarrierPin);
  _counter = 0;
  _notification = amountHoles * 2;
}

boolean LightBarrier::notification(){
  int value = digitalRead(_lightBarrierPin);
  if(value != _oldValue)
  { 
      _counter = _counter + 1;
      _oldValue = value; 
  }
}

void LightBarrier::setCounter(int newCounter){
  _counter = newCounter;
}

int LightBarrier::getCounter(){
  return _counter/_notification;
}
