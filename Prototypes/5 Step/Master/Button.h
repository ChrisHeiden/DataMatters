#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int pin);
    void readButtonState();
    boolean getButtonState();
    void setCeroPosition(boolean pos);
  
  private:
    int _buttonPin;
    boolean _buttonState;
};

#endif
