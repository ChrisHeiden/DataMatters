#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin) {
  //_trigPin = trigPin;  
  //_echoPin = echoPin;
  
  //pinMode(_trigPin, OUTPUT);
  //pinMode(_echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void UltrasonicSensor::activateUltrasonicSensor(){
  /*
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long _duration = pulseIn(_echoPin, HIGH);
  // Calculating the distance
  int _distance = _duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(_distance);


  val = analogRead(_sensorpin);       // reads the value of the sharp sensor
  Serial.println(_val);            // prints the value of the sensor to the serial monitor
  delay(400);  */                  // wait for this much time before printing next value
}

void UltrasonicSensor::deactivateUltrasonicSensor(){
  
}  
