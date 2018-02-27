// BIS BUZZER code
// Author: Anders Reiche

const int MIN = 10;
const int MAX = 40;
const int buttonPin = 2;
const int buzzerPin = 15;
int state = 0;

void ok (void) {
  for (int i = 0; i < 3; i++) {
  digitalWrite(buzzerPin, LOW);                       
  delay(1);                     
  digitalWrite(buzzerPin, HIGH);  
  delay(2000);        
  }
}

void warning(void) {
  delay(1000);
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
}

void error(void) {
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
}

void busy(void) {
  for (int i=0; i <= 100; i++){
  digitalWrite(buzzerPin, LOW);                       
  delay(random(MIN, MAX));                     
  digitalWrite(buzzerPin, HIGH);  
  delay(random(MIN, MAX)); 
  }
}

int next_state(void) {
  while (digitalRead(buttonPin) == 0) {
    delay(0);
    // wait here till button is pressed
  }
  state++;
  if (state == 4) { state = 0; }
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}


void loop() {
  switch (state) {
    case 0: ok();       next_state();   break;
    case 1: warning();  next_state();   break;
    case 2: error();    next_state();   break;
    case 3: busy();     next_state();   break;
  }
}
