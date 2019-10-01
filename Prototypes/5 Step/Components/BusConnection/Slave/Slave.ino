/**
 *  Upload the sketch with ATmega328P old Bootloader
 */
int enablePin = 10; 

void setup() 
{
  Serial.begin(9600);                  
  pinMode(enablePin, OUTPUT);
  delay(10);
  digitalWrite(enablePin, LOW);      
  
}

void loop() 

{                                                  
  while (Serial.available())                   //While have data at Serial port this loop executes
     {
        int test = Serial.parseInt();            //Receive INTEGER value from Master throught RS-485
        Serial.println(test);
        delay(500);
    }
 } 
