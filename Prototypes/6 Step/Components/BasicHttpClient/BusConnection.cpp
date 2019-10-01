#include "BusConnection.h"

BusConnection::BusConnection(int rx,int tx):serial(rx,tx)
{
   pinMode(rx, INPUT);
   pinMode(tx, OUTPUT);
   serial.begin(115200);
}

void BusConnection::sendsMessages()
{
  serial.write('h');
}
