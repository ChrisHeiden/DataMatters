#ifndef BusSlave_h
#define BusSlave_h

#include "Arduino.h"
#include <stdlib.h>

class BusSlave
{
  public:
    BusSlave(int pin, char arduinoNumber, char motor1, char motor2);
    boolean checkAddress(String busMessage);
    void checkMotorNumber(String busMessage);
    void readBusPayload();
    void checkMotorNumber();
    boolean getHaveMotorData2();
    boolean getHaveMotorData1();
    int getBusMessage();
    void stringToArray(String payload);
    int getHighestNumber(long animalExtinction[], int sizeArray);
    void printArray(int animalExtinction[], int sizeArray);
    int* getArray1();
    int* getArray2();
    int getHighestNumber();
    int getIndex();
    void setIndex(String index);
    int getMessages();
    String changeYear();

    void stringToArray1(String payload);
    void stringToArray2(String payload);

  
  private:
    int _BusSlavePin;
    String _message;
    char _arduinoNumber;
    int _highestNumber;
    int _animalExtinction1[36];
    int _animalExtinction2[36];
    int _index;
    boolean _haveDataset;
    char _motor1;
    char _motor2;
    boolean _haveMotorData1;
    boolean _haveMotorData2;
    int messages;
    String _oldYear;

};

#endif
