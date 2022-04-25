#include<Servo.h>
Servo motorservo;
int R = 6; //red
int G = 7; // green
int B = 13; // buzzer = 13
int S = 9; // smoke
int F = 19; //flame 
void setup() {
  // put your setup code here, to run once:
  pinMode(F, INPUT);
  pinMode(S, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600);
  motorservo.attach (8);
  motorservo.write (0) ;
}
void loop() {
  // put your main code here, to run repeatedly:
  int FR = digitalRead(F);
  int SR = digitalRead(S);
  Serial.print ("Value of Flame: ");
  Serial.println (FR);
  Serial.print ("Value of Smoke: ");
  Serial.println (SR);
  if (SR==HIGH or FR==HIGH)
  {
    Serial.println ("The Fire Alarm is Active");
    digitalWrite (R, HIGH);
    digitalWrite (G, LOW);
    tone (B, 1000, 200);
    motorservo.write (180);
  }
  else
  {
    Serial.println ("There is no fire");
    digitalWrite (R, LOW );
    digitalWrite (G, HIGH);
    motorservo.write (0);
    noTone (B);
  }
  delay (100);
}
