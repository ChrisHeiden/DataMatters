int enablePin = 2;  

void setup()
{
  Serial.begin(9600);            
  pinMode(enablePin, OUTPUT);
  delay(10); 
  digitalWrite(enablePin, HIGH);  
}
void loop()
{
    Serial.println(10);
    delay(100);
}
