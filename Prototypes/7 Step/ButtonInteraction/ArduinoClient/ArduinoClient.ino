#include "Motor.h"
#include "LightBarrier.h"
#include "BusSlave.h"
#include <SoftwareSerial.h>


/*
 * ARDUINONUMBER, MOTOR1, and MOTOR2 has to be changed every time
 */

#define ArduinoID 1
#define MOTOR1 1
#define MOTOR2 2


#define DIAMETER 1.2
#define NOTIFICATIONPERTURN 8
#define THREADLENGTH  200
#define PROCENT 100
#define RPM 60
#define AMOUNTMOTORS 2
#define AMOUNTM 16
#define MOTOR1PINA 15
#define MOTOR1PINB 14
#define MOTOR2PINA 19
#define MOTOR2PINB 18

#define LIGHTBARRIERPINA 3
#define LIGHTBARRIERPINB 4


//motor 1 specific variables
Motor motor1(MOTOR1PINA,MOTOR1PINB); 
LightBarrier lightBarrier1(LIGHTBARRIERPINA, NOTIFICATIONPERTURN);
int oldValue1;
boolean motorSetup1;
int motorPos1;
int oldCounter1;
byte setupMotorPos1;
int newLength1;
int oldLength1;
int amountTurns1;
int amountOfPossibleTurns1;

//motor 2 specific variables
Motor motor2(MOTOR2PINA,MOTOR2PINB);
LightBarrier lightBarrier2(LIGHTBARRIERPINB, NOTIFICATIONPERTURN);
int oldValue2;
boolean motorSetup2;
int motorPos2;
int oldCounter2;
byte setupMotorPos2;
int newLength2;
int oldLength2;
int amountTurns2;
int amountOfPossibleTurns2;

//general values
int overAllPossibleTurns;
int oldYear;
String _oldString;
int motorSetup;
int animalExtinctionArraySize;
int setupMotorPos;
boolean newTimePeriod;
const int pin = 10;
BusSlave bus(pin, ArduinoID, MOTOR1, MOTOR2);

long exitinctionRate1[]={90,90,90,90,90,90,90,90,90,90,93,118,56,95,35,15,5,10,5,7,10,7,35,30,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long exitinctionRate2[]={367,367,367,367,367,367,367,367,367,367,367,367,382,397,412,420,428,379,379,380,380,381,395,410,440,470,500,625,750,725,700,350,350,350,350,350,350,350,350,350,350,350,350,350,350};


void setup() {
  Serial.begin(57600);

  //motor 1 specific variables
  oldValue1 = -1;
  motorSetup1 = false;
  motorPos1 = 0;
  oldCounter1 = 0;
  setupMotorPos1 = 0;
  amountOfPossibleTurns1 = calcTurns(THREADLENGTH);
  newLength1 = 0;
  amountTurns1 = 0;
  oldLength1 = THREADLENGTH; 

  //motor 2 specific variables
  oldValue2 = -1;
  motorSetup2 = false;
  motorPos2 = 0;
  oldCounter2 = 0;
  setupMotorPos2 = 0;
  amountOfPossibleTurns2 = calcTurns(THREADLENGTH);
  newLength2 = 0;
  oldLength1 = THREADLENGTH; 

  //general values
  overAllPossibleTurns = calcTurns(THREADLENGTH);
  motorSetup = 0;
  setupMotorPos = 0;
  animalExtinctionArraySize = (sizeof(exitinctionRate1) / sizeof(exitinctionRate1[0]));
  amountTurns2 = 0;
  oldYear = 0;
}

int calcLength1(int newProcent){
  float percent = (exitinctionRate1[bus.changeYear().toInt()] * PROCENT) / findHightestNumber(exitinctionRate1, 45);
  int resultLength = (percent * THREADLENGTH) / PROCENT;
  return resultLength;
}

int calcLength2(int newProcent ){
  float percent = (exitinctionRate2[bus.changeYear().toInt()] * PROCENT) / findHightestNumber(exitinctionRate2, 45);
  int resultLength = (percent * THREADLENGTH) / PROCENT;
  return resultLength;
}

int findHightestNumber(long animalExtinction[], int animalExtinctionArraySizeArray){
  int highestNumber = -1;
  for(byte i = 0; i < animalExtinctionArraySizeArray; ++i)
  {
    if(animalExtinction[i] > highestNumber)
    {
      highestNumber = animalExtinction[i];
    }
  } 
  return highestNumber;
}

int calcTurns(int threadLength){
  int turns = threadLength/(PI  * DIAMETER);
  return turns;
}

void ceroPosition(){
 
}

void loop() {
  /***** Zero Position *****/
  if(setupMotorPos == 0){
    bus.checkMotorNumber();
    if(bus.getMotorData1() == true)
    {
      motor1.clockwise();
      motor2.deactivateMotor();
      motorPos1 = 1;
    }
    else if(bus.getMotorData2() == true)
    {
      motor2.clockwise();
      motor1.deactivateMotor();
      motorPos2 = 1;
    }
    else if (bus.getMotorData1() == false && bus.getMotorData2() == false && motorPos2 == 1 && motorPos1 == 1)
    {
      motor1.deactivateMotor();
      motor2.deactivateMotor();
      motorPos1 = 0;
      motorPos2 = 0;
      setupMotorPos = 1;  
    }
  }
  /****** High Position ********/
  else if(setupMotorPos == 1){ 
    Serial.println("setupMotorPos = 1");
    lightBarrier1.notification();
    if(1 >= lightBarrier1.getCounter()) //change 3 -> overAllPossibleTurns in final version
    {
      motor1.counterClockwise();
    }
    else{ 
      motor1.deactivateMotor();
      lightBarrier1.setCounter(0);
      motorSetup1 = true;
    }
    
    lightBarrier2.notification();
    if(1 >= lightBarrier2.getCounter()) //change 1 -> overAllPossibleTurns in final version
    {
      motor2.counterClockwise();
    }
    else
    {
      motor2.deactivateMotor();
      lightBarrier2.setCounter(0);
      motorSetup2 = true;
    }

    if(motorSetup1 == true && motorSetup2 == true)
    {
      motor1.deactivateMotor();
      motor2.deactivateMotor();
      setupMotorPos = 2;
    }
  }
  // Normal Action 
  else if(setupMotorPos == 2)
  {
    Serial.println("act normal");
    
    int yearNumber = bus.changeYear().toInt();
    boolean longerThread1 = false;
    boolean longerThread2 = false;

    if(oldYear != yearNumber){
      lightBarrier1.notification();
      lightBarrier2.notification();
 
      newLength1 = calcLength1(exitinctionRate1[yearNumber]);
      newLength2 = calcLength2(exitinctionRate2[yearNumber]);

      if(newLength1 < oldLength1){ longerThread1 = false;}
      else{longerThread1 = true;}

      if(newLength2 < oldLength2){ longerThread2 = false;}
      else{longerThread2 = true;}
      
      amountTurns1 = calcTurns(newLength1);
      amountTurns2 = calcTurns(newLength2);

      amountTurns1 = amountOfPossibleTurns1 - amountTurns1;
      amountTurns2 = amountOfPossibleTurns2 - amountTurns2;


      if(amountOfPossibleTurns1 >= lightBarrier1.getCounter() && 
       amountTurns1 >= 0 && amountTurns1 >= lightBarrier1.getCounter())
      {
        if(longerThread1 == true){ motor1.counterClockwise(); }
        else if(longerThread1 == false){ motor1.clockwise(); }
      }
      else
      {
        motor1.deactivateMotor();
        lightBarrier1.setCounter(0);
      }

      if(amountOfPossibleTurns2 >= lightBarrier2.getCounter() && 
         amountTurns2 >= 0 && amountTurns2 >= lightBarrier2.getCounter())
      {
        if(longerThread2 == true){ motor2.counterClockwise(); }
        else if(longerThread2 == false){ motor2.clockwise(); }
      }
      else
      {
        motor2.deactivateMotor();
        lightBarrier2.setCounter(0);
      }
      
      oldLength1 = newLength1;
      oldLength2 = newLength2;
      oldYear = yearNumber;
    }
  }
}

/*******************
 * Testfunctions
 ******************/
/*
void forBack()
{
  for(int y = 0; y< 3; ++y)
  {
    for(byte i = 0; i < 3; ++i)
    {
      motor1.clockwise();
      motor2.clockwise();
      delay(300);
    }
  
    for(byte i = 0; i < 3; ++i)
    {
      motor1.counterClockwise();
      motor2.counterClockwise();
      delay(300);
    }
  }
}

void tenSteps(){
  motor1.clockwise();
  motor2.clockwise();
  lightBarrier1.notification();
  lightBarrier2.notification();
  Serial.print("lightBarrier1: ");
  Serial.println(lightBarrier1.getCounter());
  Serial.print("lightBarrier2: ");
  Serial.println(lightBarrier2.getCounter());
  
  if(lightBarrier1.getCounter() >= 1)
  {
    motor1.deactivateMotor();
    setupMotorPos1 = 1;
  }
  if(lightBarrier2.getCounter() >= 1)
  {
    motor2.deactivateMotor();
    setupMotorPos2 = 1;
  }
}

void ceroPosition(){
  motor1.counterClockwise();
  motor2.counterClockwise();
  lightBarrier1.notification();
  lightBarrier2.notification();

  if(lightBarrier1.getCounter() >= amountOfPossibleTurns)
  {
    motor1.deactivateMotor();
    setupMotorPos1 = 1;
  }
  if(lightBarrier2.getCounter() >= amountOfPossibleTurns)
  {
    motor2.deactivateMotor();
    setupMotorPos2 = 1;
  }
}*/

/*
  if(setupMotorPos == -1)
  {
    if(bus.getMessages() < AMOUNTMOTORS)
    {
      bus.readBusPayload();
    }
    else{
      setupMotorPos = 0;
    }
    delay(500);
  }*/
