#include <HX711.h>
#include <Arduino.h>

// stepper pin definition
#define ENA 11 // enable pin
#define DIR 12 // direction pin
#define PUL 13 // step pin

void driveStepper(int steps, bool dir);

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(PUL, OUTPUT);
  digitalWrite(ENA, LOW);
  digitalWrite(DIR, HIGH);
  digitalWrite(PUL, HIGH);
}

void loop() {
  // this is a comment I added
  // Josh comment
  // 🐟 - updated to be an update
  // this is a trevor comment
  
  //fish
}

void driveStepper(int steps, bool dir) {
  digitalWrite(ENA, HIGH);
  delayMicroseconds(5);
  digitalWrite(DIR, dir);
  delayMicroseconds(5);
  for (int i = 0; i < steps; i++) {
    digitalWrite(PUL, LOW);
    delayMicroseconds(2.5);
    digitalWrite(PUL, HIGH);
    delayMicroseconds(2.5);
  }
  digitalWrite(DIR, HIGH);
  digitalWrite(ENA, LOW);
}