#include "LightBarrier.h"

LightBarrier::LightBarrier(int pin){
  _lightBarrierPin = pin;
  pinMode(_lightBarrierPin, INPUT);
}

boolean LightBarrier::notification(){
  int value = digitalRead(_lightBarrierPin);
  if(value == 1)
  {
    Serial.println("unterbrochen");
  }
  else
  {
    Serial.println("nicht unterbrochen");
  }
}
