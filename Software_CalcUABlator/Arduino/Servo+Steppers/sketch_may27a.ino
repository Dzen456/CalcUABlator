#include <Servo.h>

// Script that moves the two nema 17 steppers and the servo motor

const int dirPin1 = 12;
const int stepPin1 = 11;

const int dirPin2 = 8;
const int stepPin2 = 9;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int d = 0;

void setup() {
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object

  // put your setup code here, to run once:
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  delay(2000);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
}

void loop() {
  myservo.write(pos);
  if (d > 60){
    if (pos == 0)
      pos = 30;
    else if (pos == 30)
      pos = 0;
    d = 0;
  }

  // put your main code here, to run repeatedly:
  digitalWrite(stepPin1, HIGH);
  digitalWrite(stepPin2, HIGH);
  delay(25);
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  delay(25);
  d = d + 1;
}
