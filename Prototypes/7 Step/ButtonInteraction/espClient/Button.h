#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int pin);
    void noticeButtonClick();
    int getIndex();
    int setIndex(int number);
    boolean getState();


  private:
    int debounce(int sampleA);

    
  private:
    int _index;
    int _buttonPin;
    boolean _buttonState;
    int _oldIndex;

    boolean _state;

    int _sampleB;
    int _sampleC;
    int _lastDebounceResult;
};

#endif
