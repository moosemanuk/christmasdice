#include <Arduino.h>

// Define the output pins
int topLeft = 5;
int middleLeft = 4;
int bottomLeft = 2;
int middle = 3;
int topRight = 8;
int middleRight = 7;
int bottomRight = 6;
int pinSwitch = 9;
int state = 0;
long randomNumber;

// Functions to switch the LEDs on
void rollOne() {
  digitalWrite(middle, HIGH);
}

void rollTwo() {
  digitalWrite(topLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
}

void rollThree() {
  digitalWrite(topLeft, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(bottomRight, HIGH);
}

void rollFour() {
  digitalWrite(topLeft, HIGH);
  digitalWrite(topRight, HIGH);
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
}

void rollFive() {
  digitalWrite(topLeft, HIGH);
  digitalWrite(topRight, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(bottomRight, HIGH);  
}

void rollSix(){
  digitalWrite(topLeft, HIGH);
  digitalWrite(topRight, HIGH);
  digitalWrite(middleLeft, HIGH);
  digitalWrite(middleRight, HIGH);
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
}

void clearLEDs() {
  digitalWrite(middle, LOW);
  digitalWrite(topLeft, LOW);
  digitalWrite(topRight, LOW);
  digitalWrite(middleLeft, LOW);
  digitalWrite(middleRight, LOW);
  digitalWrite(bottomLeft, LOW);
  digitalWrite(bottomRight, LOW);
}

void setup() {
  pinMode(topLeft, OUTPUT);
  pinMode(middleLeft, OUTPUT);
  pinMode(bottomLeft, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(topRight, OUTPUT);
  pinMode(middleRight, OUTPUT);
  pinMode(bottomRight, OUTPUT);
  pinMode(pinSwitch, INPUT);

  Serial.begin(9600);
  randomSeed(analogRead(0));
  clearLEDs();
}

void loop() {
  
  if (digitalRead(pinSwitch) == LOW && state == 0)
  {
    state = 1;
    randomNumber = random(1,7);
    delay(100);
    Serial.print(randomNumber);
    
    if (randomNumber == 1) {
      rollOne();
    }

    if (randomNumber == 2) {
      rollTwo();
    }

    if (randomNumber == 3) {
      rollThree();
    }

    if (randomNumber == 4) {
      rollFour();
    }

    if (randomNumber == 5) {
      rollFive();
    }

    if (randomNumber == 6) {
      rollSix();
    }

    delay(3000);
    clearLEDs();
    state = 0;
  }
}

