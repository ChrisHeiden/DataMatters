#include <Time.h>
#include <TimeLib.h>

#include "Motor.h"
#include "LightBarrier.h"
#include "PIRSensor.h"

#define DIAMETER 1.2
#define NOTIFICATIONPERTURN 8
#define THREADLENGTH  150
#define PROCENT 100
#define RPM 60

Motor motor(3);
PIRSensor ripSensor(10);
LightBarrier lightBarrier(11);
PIRSensor pirSensor(5);

int animalExtinctionArray[18] = {142,90,83,78,56,45,35,15,10,8,5,3,2,1,1,1,1,0};

boolean setupMotorPos;
int amountOfPossibleTurns;
int countFirstPosTurns;
int size;
int startMillis; 
time_t t;

void setup() {
  Serial.begin(115200);
  amountOfPossibleTurns = 0;
  setupMotorPos = false;
  countFirstPosTurns = 0;
  size = sizeof(animalExtinctionArray) / sizeof(int);
  startMillis = millis();  //initial start time
  t = now();
}
int calulateVelocity(int rpm){
  int velocity = 2*PI*rpm;
  return velocity;
}
int calculateCircumference(int radius){
   int circumference = PI * pow(radius, 2);
   return circumference;
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
int rotationsPerSec(){
  const int sec = 60;
  int rotsPerSec = RPM / sec;
  return rotsPerSec;
}
void firstPos(){
  if(amountOfPossibleTurns == 0)
  {
    amountOfPossibleTurns = calcTurns(THREADLENGTH);
  }
  else
  {  
    int sec = second(t);
    int rotPerSec = rotationsPerSec();
    Serial.println(sec);
    if(rotPerSec * sec <= amountOfPossibleTurns)
    {
      motor.activateMotor();
    }
    else
    {
      motor.deactivateMotor();
      setupMotorPos = true;
    }
  }
}
void loop() {
  if(setupMotorPos == false)
  {
    firstPos(); 
  }
  else
  {
    Serial.println("Now I am here!");
    lightBarrier.notification();
    int resultLength = calcLength(animalExtinctionArray[0]);
    int amountTurns = calcTurns(resultLength);
    //int turns = amountOfPossibleTurns - amountTurns;
    int sec = millis() / 1000;
    int rotPerSec = rotationsPerSec();
    if(amountTurns <= rotPerSec * sec)
    {
      motor.deactivateMotor();
    }
    else
    {
      motor.activateMotor();
    }  
    /*
    if(pirSensor.getSensorValue() == true && lightBarrier.getCounter() == 100)
    {
      motor.deactivateMotor();
    }*/
  }
}


/*
  if(setupMotorPos == false)
  {
    lightBarrier.setupPos();
    if(lightBarrier.getSameValue() == true)
    {
      setupMotorPos = true;
    }
    else
    {
      motor.activateMotor();
    }
  }
  */

   /*lightBarrier.notification();
    if(lightBarrier.getCounter() <= (amountOfPossibleTurns * NOTIFICATIONPERTURN))
    {
      motor.activateMotor();
    }
    else
    {
      motor.deactivateMotor();
    }*/
