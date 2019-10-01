#include "Motor.h"
#include "HallSensor.h"
#include "UltrasonicSensor.h"
#include "TouchButton.h"

Motor motor(3);
HallSensor hallSensor(4);
UltrasonicSensor ultrasonicSensor(3,2);
//TouchButton touchButton(6,5);
TouchButton touchButton;

void setup() {
  Serial.begin(19200);
}

void loop() {
  touchButton.readTouchButton();
  Serial.println(touchButton.getButtonState());
  //testingComponents();
}
/*
private void testingComponents(){
  //hallSensor.readHallSensor(); 
  //hallSensor.printCountTurns(); 
  //ultrasonicSensor.activateUltrasonicSensor(); //doesn't work
  //testMotor();
  
}


private void testMotor(){
  delay(1000);
  motor.activateMotor();
  delay(1000);
  motor.deactivateMotor();
}
*/

/*

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(19200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}

 */
