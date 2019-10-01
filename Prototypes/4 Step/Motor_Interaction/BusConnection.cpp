#include "BusConnection.h"

BusConnection::BusConnection(int rx,int tx):serial(rx,tx)
{
  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);
  serial.begin(115200);
}

void BusConnection::readMessages()
{
  char c = serial.read();
  Serial.println(c); 
}
