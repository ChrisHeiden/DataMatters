#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int pin);
    boolean getCeroPosition();
    void noticeButton();

  private:
    int _buttonPin;
    boolean _ceroPos;
};

#endif
