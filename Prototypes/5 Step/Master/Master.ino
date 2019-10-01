#include "ClientConnection.h"
#include "BusMaster.h"
#include "Button.h"

ClientConnection clientC;
BusMaster bus(7);
Button button(8);
boolean haveAnimalExtinction;
boolean haveYearIndex;
byte oldYear;

void setup() 
{
   Serial.begin(11520);
   haveAnimalExtinction = false;
   haveYearIndex = false;
   oldYear = -1;
}

void loop() 
{
  clientC.readServer();
  String payload =clientC.getPayload();
  Serial.println(payload);
  
  //forward Animal Extinction table
  if(haveAnimalExtinction == false)
  {
    bus.sendMessage(payload);
    haveAnimalExtinction = true;
  }
  //forward year index
  else 
  {
    byte year;
    if(oldYear != year)
    {
      year = payload.toInt();
      bus.sendMessage(payload);
      oldYear = year;
    }
  }
  
  //forward button state
  button.readButtonState();
  if(button.getButtonState() == true)
  {
    bus.sendMessage(1); 
  }
}
