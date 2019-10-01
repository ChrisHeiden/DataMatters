#ifndef BusSlave_h
#define BusSlave_h

#include "Arduino.h"
#include <stdlib.h>

class BusSlave
{
  public:
    BusSlave(int pin, int arduinoNumber, int motor1, int motor2);
    //boolean checkAddress(String busMessage);
    //void checkMotorNumber(String busMessage);
    void readBusPayload();
    void checkMotorNumber();
    boolean getMotorData2();
    boolean getMotorData1();
    int getBusMessage();
    void stringToArray(String payload, int arrayNumber);
    int getHighestNumber(long animalExtinction[], int sizeArray);
    void printArray(int animalExtinction[], int sizeArray);
    int* getArray(int arrayNumber);
    int getIndex();
    void setIndex(String index);
    int getMessages();
    String changeYear();


  
  private:
    int _busSlavePin;
    String _message;
    int _arduinoNumber;
    int _highestNumber;
    int _animalExtinction1[36];
    int _animalExtinction2[36];
    int _index;
    boolean _haveDataset;
    int _motor1;
    int _motor2;
    boolean _haveMotorData1;
    boolean _haveMotorData2;
    int _messages;
    String _oldYear;

};

#endif
