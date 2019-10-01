#include "LightBarrier.h"

LightBarrier::LightBarrier(int pin){
  _lightBarrierPin = pin;
  pinMode(_lightBarrierPin, INPUT);

  _index = 0;
  _sameValue = false;
}

boolean LightBarrier::notification(){
  int value = digitalRead(_lightBarrierPin);
  if(value == 0)
  {
    ++_counter;
  }
}

int LightBarrier::getCounter(){
  return _counter;
}

void LightBarrier::setupPos(){
  int value = digitalRead(_lightBarrierPin);
  
  if(_index < 10 && value == 0)
  {
    _counterValArray[_index] == _counter;
    ++_counter;
    ++_index;
  }
  if(_index <= 10)
  {
    _index = 0;
    for(int i = 0; i < 10 - 1; ++i)
    {
      int arrayValue = _counterValArray[_index];
      if(_counterValArray[_index + 1] == arrayValue)
      {
        _sameValue = true;
        break;
      }
      else
      {
        _sameValue = false;  
      }
    }
  }
}

boolean LightBarrier::getSameValue(){
  return _sameValue;
}
