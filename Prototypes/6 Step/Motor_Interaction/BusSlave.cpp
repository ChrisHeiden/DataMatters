#include "BusSlave.h"

BusSlave::BusSlave(int pin, char arduinoNumber, char motor1, char motor2)
{
  _BusSlavePin = pin;
  _arduinoNumber = arduinoNumber;
  _motor1 = motor1;
  _motor2 = motor2;
  pinMode(_BusSlavePin, INPUT);
  digitalWrite(_BusSlavePin, LOW);    
  _index = 0;  
  _haveDataset = false;
  _highestNumber = -1;
  messages = -1;
  _oldYear = "";

  _haveMotorData1 = false;
  _haveMotorData2 = false;
}

void BusSlave::readBusPayload()
{
   while(Serial.available())
   {
      //Serial.println(Serial.readString());
      checkMotorNumber();
      if(_haveMotorData1 == true)
      {
        //Serial.println(Serial.readString());
        stringToArray1(Serial.readString());
        ++messages;
      }
      else if(_haveMotorData2 == true)
      {
        //Serial.println(Serial.readString());
        stringToArray2(Serial.readString());
        ++messages;
      }
      else{
        printArray(_animalExtinction1, 36);
        printArray(_animalExtinction2, 36);
      }
  }
}

String BusSlave::changeYear()
{
   while(Serial.available())                  
   {
      String number = Serial.readString();  
      if(_oldYear != number)
      {
        _oldYear = number;
        return number;
      }
   }
}


void BusSlave::checkMotorNumber()
{
     //if(Serial.available())                  
   while(Serial.available())                  
   {
      String number = Serial.readString();
      //Serial.print("number: ");
      //Serial.println(number);
      
      //Serial.print("_motor1: ");
      //Serial.println(_motor1);
      
      //Serial.print("_motor2: ");
      //Serial.println(_motor2);

      if(_motor1 == number.charAt(0))
      {    
        _haveMotorData1 = true;
        _haveMotorData2 = false;
      }
      else if(_motor2 == number.charAt(0))
      {
        _haveMotorData2 = true;
        _haveMotorData1 = false;
      }
      else{
        _haveMotorData2 = false;
        _haveMotorData1 = false;
      }
   }
}

void BusSlave::setIndex(String index){
  _index = index.toInt();
}

int BusSlave::getBusMessage()
{
  return _message.toInt();
}

boolean BusSlave::checkAddress(String busMessage)
{
  if(_arduinoNumber == busMessage.charAt(0))
  {
    return true;
  }
  return false;
}

void BusSlave::stringToArray1(String payload)
{
  String trimString = payload.substring(payload.indexOf(':') + 1, payload.length());
  int animalExtinctionArray = (sizeof(_animalExtinction1) / sizeof(_animalExtinction1[0]));
  for(byte i = 0; i < animalExtinctionArray; ++i)
  {
      int index = trimString.indexOf(',') + 1;
      String number = trimString.substring(0, index - 1);
      trimString = trimString.substring(index, trimString.length());
      _animalExtinction1[i] = number.toInt(); 
  }
}

void BusSlave::stringToArray2(String payload)
{
  String trimString = payload.substring(payload.indexOf(':') + 1, payload.length());
  int animalExtinctionArray = (sizeof(_animalExtinction2) / sizeof(_animalExtinction2[0]));
  for(byte i = 0; i < animalExtinctionArray; ++i)
  {
      int index = trimString.indexOf(',') + 1;
      String number = trimString.substring(0, index - 1);
      trimString = trimString.substring(index, trimString.length());
      _animalExtinction2[i] = number.toInt(); 
  }
}

void BusSlave::printArray(int animalExtinction[], int sizeArray)
{
  for(byte i = 0; i < sizeArray; ++i)
  {
      Serial.print(animalExtinction[i]);
      Serial.print(", ");
  }
}


int BusSlave::getHighestNumber(long animalExtinction[], int sizeArray)
{
  int highestNumber = -1;
  for(byte i = 0; i < sizeArray; ++i)
  {
    if(animalExtinction[i] > highestNumber)
    {
      highestNumber = animalExtinction[i];
    }
  } 
  return highestNumber;
}

int* BusSlave::getArray1(){
  return _animalExtinction1;
}

int* BusSlave::getArray2(){
  return _animalExtinction2;
}

int BusSlave::getIndex(){
  return _index;
}

boolean BusSlave::getHaveMotorData2(){ 
  return _haveMotorData2;
}

boolean BusSlave::getHaveMotorData1(){
  return _haveMotorData1;
}

int BusSlave::getMessages(){
  return messages;
}


/*
void BusSlave::checkMotorNumber(String busMessage)
{
  Serial.print(_motor1);
  Serial.print(busMessage);
  Serial.print(busMessage);
  Serial.print("busMessage.charAt(0): ");
  Serial.println(busMessage.charAt(0));
  Serial.print("busMessage.charAt(0): ");
  Serial.print("busMessage.charAt(0): ");
  Serial.print("busMessage.charAt(0): " - '0'); // probiere
  Serial.print(busMessage.charAt(0)); // probiere
  Serial.print(atoi(busMessage.charAt(0)));
  int num = atoi("23");

  if(3 == busMessage.charAt(0))
  {
        Serial.println("Hallo1");

    _haveMotorData1 = true;
  }
  if(_motor2 == busMessage.charAt(0))
  {
    Serial.println("Hallo2");
     _haveMotorData2 = true;
  }
}*/
