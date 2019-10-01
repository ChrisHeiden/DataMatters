#include "Motor.h"
#include "HallSensor.h"
#include "PIRSensor.h"
#include "LightBarrier.h"

Motor motor(3);
HallSensor hallSensor(4);
PIRSensor ripSensor(10);
LightBarrier lightBarrier(11);

void setup() {
  Serial.begin(115200);
}

void loop() {
  testingComponents();
}

void testingComponents(){
  //hallSensor.readHallSensor(); 
  //hallSensor.printCountTurns(); 
  //ripSensor.readSensor();
  //Serial.println(ripSensor.getSensorValue());
  //testMotor();
  lightBarrier.notification();
  delay(10);
}


void testMotor(){
  //delay(1000);
  motor.activateMotor();
  //delay(1000);
  //motor.deactivateMotor();
}
