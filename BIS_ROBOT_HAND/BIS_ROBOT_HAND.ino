// BIS ROBOT HAND code
// Author: Anders Reiche

#include <Servo.h>

const int R = 15;
const int G = 3;
const int B = 1;
const int pinflex = A0; //D3
const int buzzerPin = 16;
Servo myServo;

void setup() {
  
//Serial.begin(9600);    
myServo.attach(2);
//Set PWM frequency 500, default is 1000
//Set range 0~100, default is 0~1023
analogWriteFreq(500);
analogWriteRange(100);
pinMode(R, OUTPUT);
pinMode(G, OUTPUT);
pinMode(B, OUTPUT);
pinMode(buzzerPin, OUTPUT);
digitalWrite(G, 0);
digitalWrite(R, 0);
digitalWrite(B, 0);

}

void loop() {

int flexpos;
int servopos;
flexpos = analogRead(pinflex);
servopos = map(flexpos, 600, 900, 0, 180);
servopos = constrain(servopos, 0, 180);
myServo.write(servopos);


if (flexpos < 650 ) {
  digitalWrite(G, 1);
  digitalWrite(R, 0);
  digitalWrite(B, 0);
  analogWrite(buzzerPin, 0);
} else if (flexpos < 780) {
  digitalWrite(G, 0);
  digitalWrite(B, 1);
  digitalWrite(R, 0);  
  analogWrite(buzzerPin, 0);
} else {
  digitalWrite(R, 1);
  digitalWrite(G, 0);
  digitalWrite(B, 0);
  analogWrite(buzzerPin, 50);
}

delay(25);
}
