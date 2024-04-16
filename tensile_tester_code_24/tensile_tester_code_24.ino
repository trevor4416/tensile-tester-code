#include <HX711.h>
#include <Arduino.h>

// stepper pin definition
#define ENA 8 // enable pin
#define DIR 9 // direction pin
#define PUL 10 // step pin

void driveStepper(int steps, bool dir);

void setup() {
  // Serial communication setup
  Serial.begin(9600);
  String serialBuffer = "";

  int state = 0;
  // state 0 corresponds to no action (just reading)
  // state 1 correspond to movement test of the stepper motor

  // Stepper motor pin setup
  pinMode(ENA, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(PUL, OUTPUT);
  digitalWrite(ENA, LOW);
  digitalWrite(DIR, HIGH);
  digitalWrite(PUL, HIGH);

  // Stepper motor driving variables
  int stepTarget = 0; // number of steps to move
  int stepsTaken = 0; // number of steps towards target

}

void loop() {
  char input = Serial.read();
  if (input > 0) {
    serialBuffer = serialBuffer + String(input); // add each input character to the serial buffer
    continue;
  } else if (serialBuffer.length() > 0) {
    
    String params[3];
    // FORMAT:  commandname(PARAM1, PARAM2, PARAM3)
    // parsing input strings to get command names and parameters
    // this will leave the params array filled with the parameters up to the number of parameters there are for a given command
    int searchIndex = serialBuffer.indexOf('(');
    int paramIndex = 0;
    String cmd = serialBuffer.substring(0,searchIndex);
    while (searchIndex != -1 && paramIndex < 3) {
      int nextSearchIndex = serialBuffer.substring(searchIndex+1).indexOf(',');
      if (nextSearchIndex != -1) {
        params[paramIndex] = serialBuffer.substring(searchIndex+1, nextSearchIndex);
      } else {
        params[paramIndex] = serialBuffer.substring(searchIndex+1, serialBuffer.length()-1);
      }
      searchIndex = nextSearchIndex;
      paramIndex++;
    }

    // TODO: implement "stop" command and "drive" state; will need to process parameters inside of following if statement
    // i.e. assign their values to variables that can be used within the state switch statement
    
    // select for commands from serial input
    if (cmd.equalsIgnoreCase("drive")) {
      state = 1;
    }
    serialBuffer = "";
    continue;
  }
  switch (state) {
    case 1:

  }
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