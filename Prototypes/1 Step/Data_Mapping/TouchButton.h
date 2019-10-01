//Touch realist with capacity lib

#ifndef TouchButton_h
#define TouchButton_h
#include <CapacitiveSensor.h>

#include "Arduino.h"

class TouchButton
{
  public:
    TouchButton();
    void readTouchButton();
    boolean getButtonState();
   
  private:
    CapacitiveSensor cs = CapacitiveSensor(6,5); 
    int _touchPin;
    boolean _buttonState;
    short _startButtonValue;
};
#endif

//Touch realist with ESP32

/*

#ifndef TouchButton_h
#define TouchButton_h

#include "Arduino.h"

class TouchButton
{
  public:
    TouchButton(int touchPin);
    void readTouchButton();
    boolean getButtonState();
   
  private:
    int _touchPin;
    boolean _buttonState;
    short _startButtonValue;
};
#endif

*/
