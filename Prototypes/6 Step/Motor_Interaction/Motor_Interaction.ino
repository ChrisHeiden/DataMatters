#include "Motor.h"
#include "LightBarrier.h"
#include "Button.h"
#include "BusSlave.h"
#include <SoftwareSerial.h>
#define ARDUINONUMBER '1'
#define MOTOR1 '1'
#define MOTOR2 '2'

#if ARDUINONUMBER=='1'
long exitinctionRate1[]={90,90,90,90,90,90,90,90,90,90,93,118,56,95,35,15,5,10,5,7,10,7,35,30,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long exitinctionRate2[]={367,367,367,367,367,367,367,367,367,367,367,367,382,397,412,420,428,379,379,380,380,381,395,410,440,470,500,625,750,725,700,350,350,350,350,350,350,350,350,350,350,350,350,350,350};

#elif ARDUINONUMBER=='2'
long exitinctionRate1[]={10219,10219,10219,10219,10219,10219,10219,10219,10219,10219,10219,9902,9585,512,9268,8951,601,750,900,1610,2320,1645,970,2751,653,1741,594,1670,1518,367,3675,3315,1623,357,7747,278,302,375,3048,1948,849,849,849,849,849};
long exitinctionRate2[]={100,100,100,100,100,100,100,100,100,100,100,94,61,60,46,52,63,52,52,33,32,29,48,43,28,31,63,51,59,48,30,41,33,62,48,27,43,53,23,30,30,26,26,31,24};

#elif ARDUINONUMBER=='3'
long exitinctionRate1[]={150,150,150,150,150,150,150,150,150,150,140,115,125,170,195,180,190,145,140,130,95,90,80,65,70,55,60,45,40,35,25,30,25,25,25,25,25,25,25,25,25,25,25,25,25};
long exitinctionRate2[]={5200,5200,5200,5200,5200,5200,5200,5200,5200,5200,4500,5600,4600,5000,4700,4600,4400,4000,4200,3400,3300,3200,3000,2700,2250,2600,2650,2400,2500,2200,2600,3400,3600,3400,3400,3400,3400,3400,3400,3400,3400,3400,3400,3400,3400};

#elif ARDUINONUMBER=='4'
long exitinctionRate1[]={2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,2100,1500,2000,2317,2460,3246,3252,3986,3604,2817,2651,3101,3627,3297,3472,3751,3378,3933,3411,3620,2363,1367,2239,1963,2036,2459,2607,2654,1805,2609,2513,2887,3083,2944,2944};
long exitinctionRate2[]={5151,5151,5151,5151,5151,5151,5151,5151,5151,5151,5151,4884,6293,6544,6832,6580,6741,5522,5289,6321,6495,5651,5500,5353,6449,5886,5226,5330,4904,5189,5938,6169,6272,6311,6350,6130,6369,6343,6318,6331,6150,6738,6777,6777,6777};

#elif ARDUINONUMBER=='5'
long exitinctionRate1[]={14451,14451,14451,14451,14451,14451,14451,14451,14451,14451,14451,14125,13800,13474,13149,12823,12498,12172,11847,7415,8689,9152,7439,7111,7192,4177,9643,5378,3997,5648,7074,16187,12338,13446,9839,10904,7062,9121,9121,9121,9121,9121,9121,9121,9121};
long exitinctionRate2[]={4205,4297,4389,4481,4574,4666,4758,4850,4896,4943,5681,6014,6260,6342,6534,6713,6837,6974,7253,7780,7770,7422,6880,6653,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337,6337};

#elif ARDUINONUMBER=='6'
long exitinctionRate1[]={1391,1391,1391,1391,1391,1391,1391,1391,1391,1391,1391,1324,1258,1125,993,860,836,902,634,500,366,255,184,425,257,257,257,257,257,257,257,257,257,257,257,257,257,257,257,257,257,257,257,257,257};
long exitinctionRate2[]={2587,2487,2388,2289,2190,2091,1991,1892,1843,1793,1000,966,932,864,796,728,660,626,592,524,457,428,400,371,357,343,315.125,286,258,244,230,230,230,230,230,230,230,230,230,230,230,230,230,230,230};

#elif ARDUINONUMBER=='7'
 long exitinctionRate1[]={3000000,2937500,2875000,2812500,2750000,2687500,2625000,2562500,2531250,2500000,2000000,1937500,1875000,1750000,1625000,1500000,1375000,1312500,1250000,1125000,1000000,894249,788499,682748,629873,576998,471247,365497,259746,206871,153996,142776,131556,120336,114726,109117,79739,65050,50361,41696,33032,27812,24322,13458,2595};
 long exitinctionRate2[]={5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,3,2,1,3,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

#elif ARDUINONUMBER=='8'
 long exitinctionRate1[]={138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,119,100,83,67,59,51,46,42,60,78,80,82,84,85,87,80,77,7468,62,31,0,0,0};
long exitinctionRate2[]={1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1313,1127,941,755,568,382,186,10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

#endif

/*
 * ARDUINONUMBER has to be changed every time
 */

#define DIAMETER 1.2
#define NOTIFICATIONPERTURN 8
#define THREADLENGTH  200
#define PROCENT 100
#define RPM 60
#define AMOUNTMOTORS 2
#define AMOUNTM 16

Button button(4);
Motor motor1(15,14); 
Motor motor2(19,18);
BusSlave bus(10, ARDUINONUMBER, MOTOR1, MOTOR2);
LightBarrier lightBarrier1(3, NOTIFICATIONPERTURN);
LightBarrier lightBarrier2(4, NOTIFICATIONPERTURN);
int oldValue1;
int oldValue2;
String _oldString;
int motorSetup;
int motorSetup1;
int motorSetup2;
String oldYear;
int motorPos1;
int motorPos2;
int oldCounter1;
int oldCounter2;

int setupMotorPos;
byte setupMotorPos1;
byte setupMotorPos2;
int amountOfPossibleTurns1;
int amountOfPossibleTurns2;
int countFirstPosTurns1;
int countFirstPosTurns2;
int size;
int countTurns1;
int countTurns2;

int newLength1;
int amountTurns1;
boolean newTimePeriod1;

int newLength2;
int amountTurns2;
boolean newTimePeriod2;



void setup() {
  Serial.begin(57600);
  motorSetup = 0;
  oldYear = "0";
  setupMotorPos = 0;
  setupMotorPos1 = 0;
  setupMotorPos2 = 0;
  amountOfPossibleTurns1 = 0;
  amountOfPossibleTurns2 = 0;
  countFirstPosTurns1 = 0;
  countFirstPosTurns2 = 0;
  size = sizeof(exitinctionRate1) / sizeof(int);
  countTurns1 = 0;
  countTurns2 = 0;
  oldValue1 = -1;
  oldValue2 = -1;
  newLength1 = 0;
  amountTurns1 = 0;
  countTurns2 = 0;
  oldValue2 = -1;
  newLength2 = 0;
  amountTurns2 = 0;
  amountOfPossibleTurns1 = calcTurns(THREADLENGTH);
  amountOfPossibleTurns2 = calcTurns(THREADLENGTH);
}

int calcLength1(int newProcent ){
  float percent = (exitinctionRate1[bus.changeYear().toInt()] * PROCENT) / findHightestNumber(exitinctionRate1, 45);
  int resultLength = (percent * THREADLENGTH) / PROCENT;
  return resultLength;
}

int calcLength2(int newProcent ){
  float percent = (exitinctionRate2[bus.changeYear().toInt()] * PROCENT) / findHightestNumber(exitinctionRate2, 45);
  int resultLength = (percent * THREADLENGTH) / PROCENT;
  return resultLength;
}


int findHightestNumber(long animalExtinction[], int sizeArray)
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


int calcTurns(int threadLength){
  int possibleTurns = threadLength/(PI  * DIAMETER);
  return possibleTurns;
}


void ceroPosition(){
  bus.checkMotorNumber();
  Serial.println(motorSetup);
  Serial.println(bus.getHaveMotorData1());
  Serial.println(bus.getHaveMotorData2());
  if(bus.getHaveMotorData1() == true)
  {
    motorSetup = 1;
    motor1.clockwise();
    motor2.deactivateMotor();
  }
  else if(bus.getHaveMotorData2() == true)
  {
    motorSetup = 2;
    motor2.clockwise();
    motor1.deactivateMotor();
  }
  else if (bus.getHaveMotorData1() == false && bus.getHaveMotorData2() == false && motorSetup == 2)
  {
    motor1.deactivateMotor();
    motor2.deactivateMotor();
    setupMotorPos = 1;  
    motorSetup = 0;
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
    lightBarrier1.notification();
    lightBarrier2.notification();
    if(3 > lightBarrier1.getCounter())
    {
      motor1.counterClockwise();
    }
    else{ 
      motorSetup1 = 1;
      motor1.deactivateMotor();
      lightBarrier1.setCounter(0);
    }
    
    if(3 > lightBarrier2.getCounter())
    {
      motor2.counterClockwise();
    }
    else
    {
      motorSetup2 = 1;
      motor2.deactivateMotor();
      lightBarrier2.setCounter(0);
    }
      Serial.print("motorSetup1: ");
      Serial.println(motorSetup1);
      Serial.print("motorSetup2: ");
      Serial.println(motorSetup2);
      Serial.println(bus.changeYear());

    if(motorSetup1 == 1 && motorSetup2 == 1)
    {
      motor1.deactivateMotor();
      motor2.deactivateMotor();
      Serial.println(bus.changeYear().toInt());
      if(bus.changeYear().toInt() >= 17 && setupMotorPos != 2)
      {
        setupMotorPos = 2;
      }
    }
  }
  // Normal Action 
  else if(setupMotorPos == 2)
  {
    //Serial.println("act normal");
    
    int yearNumber = bus.changeYear().toInt();
    Serial.println("1");

    lightBarrier1.notification();
    lightBarrier2.notification();
          Serial.println("2");
     Serial.println(yearNumber);
          

    newLength1 = calcLength1(exitinctionRate1[yearNumber]);
    newLength2 = calcLength2(exitinctionRate2[yearNumber]);
          Serial.println("3");

    amountTurns1 = calcTurns(newLength1);
    amountTurns2 = calcTurns(newLength2);
          Serial.println("4");

    amountTurns1 = amountOfPossibleTurns1 - amountTurns1;
    amountTurns2 = amountOfPossibleTurns2 - amountTurns2;
  
    Serial.println(yearNumber);
    
    Serial.println(newLength1);
    Serial.println(newLength2);
    
    Serial.println(amountTurns1);
    Serial.println(amountTurns2);

    Serial.println(lightBarrier1.getCounter());
    Serial.println(lightBarrier2.getCounter());

     
    if(amountOfPossibleTurns1 >= lightBarrier1.getCounter() && 
      amountTurns1 >= 0 && amountTurns1 >= lightBarrier1.getCounter())
      {
        if(exitinctionRate1[yearNumber] > exitinctionRate1[yearNumber - 1])
        {
           motor1.counterClockwise();
           if(lightBarrier1.getCounter() != oldCounter1)
           {
             oldCounter1 = lightBarrier1.getCounter();
             motorPos1++;
           }
        }
        else if(exitinctionRate1[yearNumber] < exitinctionRate1[yearNumber - 1])
        {
           motor1.clockwise();
           motorPos1 = motorPos1 - lightBarrier1.getCounter();
            if(lightBarrier1.getCounter() != oldCounter1)
           {
             oldCounter1 = lightBarrier1.getCounter();
             motorPos1--;
           }
        }
      }
      else if(amountOfPossibleTurns2 >= lightBarrier2.getCounter() && 
         amountTurns2 >= 0 && amountTurns2 >= lightBarrier2.getCounter())
      {
       if(exitinctionRate2[yearNumber] > exitinctionRate2[yearNumber - 1])
        {
           motor2.counterClockwise();
            if(lightBarrier1.getCounter() != oldCounter2)
           {
             oldCounter2 = lightBarrier2.getCounter();
             motorPos1++;
           }
        }
        else if(exitinctionRate2[yearNumber] < exitinctionRate2[yearNumber - 1])
        {
          motor2.clockwise();
           if(lightBarrier1.getCounter() != oldCounter2)
           {
             oldCounter2 = lightBarrier2.getCounter();
             motorPos1--;
           }
        }
      }
      else
      {
        motor1.deactivateMotor();
        motor2.deactivateMotor();
        lightBarrier1.setCounter(0);
        lightBarrier2.setCounter(0);
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
