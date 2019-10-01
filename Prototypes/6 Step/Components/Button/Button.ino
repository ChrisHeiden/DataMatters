const int buttonPin = 4;     // the number of the pushbutton pin
byte buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    Serial.println("Pushed");
  } else {
    Serial.println("not Pushed");
  }
}
