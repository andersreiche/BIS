// BIS HAPTIC code
// Author: Anders Reiche

const int MIN = 10;
const int MAX = 40;
const int buttonPin = 2;
const int buzzerPin = 0;
const int R = 15;
const int G = 3;
const int B = 1;
const int motorPin = 16;

int state = 0;

void ok (void) {
  analogWrite(G, 100);
  analogWrite(motorPin, 50);
  delay(500);
  analogWrite(motorPin, 0); 
  delay(1000);       
}

void warning(void) {
  analogWrite(G, 0);
  analogWrite(motorPin, 50);
  delay(170);
  analogWrite(motorPin, 0);
  delay(170); 
  analogWrite(motorPin, 50);
  delay(170);
  analogWrite(motorPin, 0);
  delay(170);
  for (int i = 0; i < 5; i++) {
  digitalWrite(buzzerPin, LOW);                       
  delay(3);                     
  digitalWrite(buzzerPin, HIGH);  
  delay(3);        
  }
  delay(200);
  for (int i = 0; i < 5; i++) {
  digitalWrite(buzzerPin, LOW);                       
  delay(1);                     
  digitalWrite(buzzerPin, HIGH);  
  delay(1);        
  }
  delay(1000);
  analogWrite(G, 100);
  delay(500);
  analogWrite(G, 0);
  delay(500);
  analogWrite(G, 100);
}

void error(void) {
  analogWrite(R, 100);
  analogWrite(G, 0);
  analogWrite(B, 0);
  for (int i = 0; i < 300; i++) {
  digitalWrite(buzzerPin, LOW);                       
  delay(1);                     
  digitalWrite(buzzerPin, HIGH);  
  delay(1); 
  }
  delay(300);
  for (int i = 0; i < 300; i++) {
  digitalWrite(buzzerPin, LOW);                       
  delay(1);                     
  digitalWrite(buzzerPin, HIGH);  
  delay(1); 
  }
  delay(300);
  for (int i = 0; i < 300; i++) {
  digitalWrite(buzzerPin, LOW);                       
  delay(1);                     
  digitalWrite(buzzerPin, HIGH);
  delay(1);  
  }
  delay(1000);
  analogWrite(R, 100); 
}

void busy(void) {
  analogWrite(R, 0);
  analogWrite(B, 0);
  analogWrite(G, 0);
  for (int i=0; i <= 100; i++){
  digitalWrite(buzzerPin, LOW);  
  analogWrite(B, random(0, 100));                     
  delay(random(MIN, MAX));                     
  digitalWrite(buzzerPin, HIGH);  
  delay(random(MIN, MAX)); 
  }
  analogWrite(B, 0);
}

int next_state(void) {
  while (digitalRead(buttonPin) == 0) {
    delay(100);
    // wait here till button is pressed
  }
  state++;
  if (state == 4) { state = 0; }
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  //Set PWM frequency 500, default is 1000
  //Set range 0~100, default is 0~1023
  analogWriteFreq(500);
  analogWriteRange(100);
  analogWrite(B, 0);
  analogWrite(R, 0);
  analogWrite(G, 0);
  
}


void loop() {
  switch (state) {
    case 0: ok();       next_state();   break;
    case 1: warning();  next_state();   break;
    case 2: error();    next_state();   break;
    case 3: busy();     next_state();   break;
  }
}
