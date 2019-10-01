#include "Motor.h"
#include "LightBarrier.h"
#include "Button.h"
//#include "BusSlave.h"
#include <SoftwareSerial.h>

#define DIAMETER 1.2
#define NOTIFICATIONPERTURN 8
#define THREADLENGTH  150
#define PROCENT 100
#define RPM 60


Button button(4);

Motor motor(9,8);
//BusSlave bus(7,6);
LightBarrier lightBarrier(11, NOTIFICATIONPERTURN);


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

  setupMotorPos = 0;
  amountOfPossibleTurns = 0;
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
  motor.counterClockwise();
  button.readButtonState();

  if(button.getButtonState() == true)
  {
    motor.deactivateMotor();
    setupMotorPos = 1;
  }
}

void loop() {

  /***** Zero Position *****/
  if(setupMotorPos == 0)
  {
    ceroPosition(); 
  }
  /****** High Position ********/
  
  else if(setupMotorPos == 1)
  {
    lightBarrier.notification();
    if(amountOfPossibleTurns >= lightBarrier.getCounter())
    {
      motor.clockwise();
    }
    else
    {
      motor.deactivateMotor();
      lightBarrier.setCounter(0);
      setupMotorPos = 2;
    }
  }
  /******* Normal Action *******/
  else if(setupMotorPos == 2)
  {
    Serial.println("act normal");
    //bus.readMessages();
    Serial.println("doing animal extinction");
    if(newTimePeriod == true)
    {
         Serial.println("new time period");
         newLength = calcLength(animalExtinctionArray[1]);
         amountTurns = calcTurns(newLength);
         amountTurns = amountOfPossibleTurns - amountTurns;
    }
    
    lightBarrier.notification();
    if(amountOfPossibleTurns >= lightBarrier.getCounter() && 
       amountTurns >= 0 && amountTurns >= lightBarrier.getCounter())
    {
      motor.counterClockwise();
      newTimePeriod = false;
    }
    else
    {
      motor.deactivateMotor();
      lightBarrier.setCounter(0);
    }
  }
}

void getNewTimePerid(){
  newTimePeriod = true;
}
