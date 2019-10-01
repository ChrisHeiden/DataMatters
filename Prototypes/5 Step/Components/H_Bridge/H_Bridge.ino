const int A1A = 9;//define pin 2 for A1A
const int A1B = 8;//define pin 3 for A1B

byte movement;

void setup() {  
  pinMode(A1A,OUTPUT);
  pinMode(A1B,OUTPUT);    
  delay(3000);
}

void loop() {
  
 
  movement = 1;
  motorA(movement);// move clockwise if -> 1
  delay(2000); 
  movement = 0;
  motorA(movement);// don't move if -> 0
  delay(2000);
  movement = 2;  
  motorA(movement);// move counterclockwise if -> 2
  delay(2000); 
}

void motorA(byte movement)
{
  if(movement == 0){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,LOW);    
  }
  else if(movement == 1){
    digitalWrite(A1A,HIGH);
    digitalWrite(A1B,LOW); 
  }
  else if (movement ==2){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,HIGH);    
  }
}
