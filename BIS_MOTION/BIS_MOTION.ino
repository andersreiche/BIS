// BIS MOTION code
// Author: Anders Reiche

#include <Servo.h>

Servo myServo;  

int const potPin = 5; // ESP8266 pin D1
int potVal;
int angle; 

void setup() {
  myServo.attach(2); // ESP8266 pin D4
}

void loop() {
  potVal = analogRead(potPin);
  angle = map(potVal, 0, 1023, 0, 179);
  myServo.write(angle);

  delay(15); // wait for servo to respond
}


