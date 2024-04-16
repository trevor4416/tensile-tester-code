#include <HX711.h>
#include <Arduino.h>

// stepper pin definition
#define ENA 8 // enable pin
#define DIR 9 // direction pin
#define PUL 10 // step pin

void driveStepper(int steps, bool dir);

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(PUL, OUTPUT);
  digitalWrite(ENA, LOW);
  digitalWrite(DIR, HIGH);
  digitalWrite(PUL, HIGH);
}

void loop() {
  
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