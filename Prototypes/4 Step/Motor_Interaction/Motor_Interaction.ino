#include "Motor.h"
#include "LightBarrier.h"
#include "Button.h"
#include "BusConnection.h"
#include <SoftwareSerial.h>

#define DIAMETER 1.2
#define NOTIFICATIONPERTURN 8
#define THREADLENGTH  150
#define PROCENT 100
#define RPM 60

BusConnection bus(7,6);

Motor motor(3);
LightBarrier lightBarrier(11, NOTIFICATIONPERTURN);
Button button(4);

int animalExtinctionArray[18] = {142,90,83,78,56,45,35,15,10,8,5,3,2,1,1,1,1,0};

byte setupMotorPos;
int amountOfPossibleTurns;
int countFirstPosTurns;
int size;
int countTurns;


int newLength;
int amountTurns;
boolean newTimePeriod;
void setup() {
  Serial.begin(115200);
 
  amountOfPossibleTurns = 0;
  setupMotorPos = 0;
  countFirstPosTurns = 0;
  size = sizeof(animalExtinctionArray) / sizeof(int);
  countTurns = 0;

  newLength = 0;
  amountTurns = 0;
  amountOfPossibleTurns = calcTurns(THREADLENGTH);
  newTimePeriod = true;
}

int calcLength(int newProcent){
  float percent = (animalExtinctionArray[1] * PROCENT) / animalExtinctionArray[0];
  int resultLength = (percent * THREADLENGTH) / PROCENT;
  return resultLength;
}

int calcTurns(int threadLength){
  int possibleTurns = threadLength/(PI  * DIAMETER);
  return possibleTurns;
}

void ceroPosition(){
  button.noticeButton();
  motor.activateMotor();
  if(button.getCeroPosition() == true)
  {
    Serial.println("Cero Pos");
    motor.deactivateMotor();
    setupMotorPos = 1;
  }
}

void loop() {
  if(setupMotorPos == 0)
  {
    ceroPosition(); 
  }
  else if(setupMotorPos == 1)
  {
    lightBarrier.notification();
    if(amountOfPossibleTurns >= lightBarrier.getCounter())
    {
      motor.activateMotor();
    }
    else
    {
      motor.deactivateMotor();
      lightBarrier.setCounter(0);
      setupMotorPos = 2;
    }
  }
  else if(setupMotorPos == 2)
  {
    bus.readMessages();
    Serial.println("doing animal extinction");
    if(newTimePeriod == true)
    {
         Serial.println("new time period");
         newLength = calcLength(animalExtinctionArray[1]);
         amountTurns = calcTurns(newLength);
         amountTurns = amountOfPossibleTurns - amountTurns;
    }
    
    lightBarrier.notification();
    Serial.print("amountOfPossibleTurns: ");
    Serial.println(amountOfPossibleTurns);
    Serial.print("lightBarrier.getCounter(): ");
    Serial.println(lightBarrier.getCounter());
    Serial.print("amountTurns: ");
    Serial.println(amountTurns);

    if(amountOfPossibleTurns >= lightBarrier.getCounter() && 
       amountTurns >= 0 && amountTurns >= lightBarrier.getCounter())
    {
      motor.activateMotor();
      newTimePeriod = false;
    }
    else
    {
      motor.deactivateMotor();
      //lightBarrier.setCounter(0);
    }
  }
}

void getNewTimePerid(){
  newTimePeriod = true;
}
