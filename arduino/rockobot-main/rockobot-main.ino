/**
  * rockobot-main.ino
  * 
  * Arduino code for Rockobot
  * More information: https://github.com/Pelochus/rockobot/tree/main/arduino 
  *
  * Authors:
  *   Pelochus
  *   sharplusplus
*/

#include <HCSR04.h> // RCWL-1601 is compatible
#include <L298N_Rockobot.h>

// See PCB/Schematics for pin numbers
#define ENA 3
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define ENB 9

#define TRIGGER 10
#define ECHO_BACK 11
#define ECHO_FRONT 12

#define IR_BACK A0
#define IR_LEFT A1
#define IR_RIGHT A2
#define IR_FRONT A3

#define MAX_DISTANCE 200 // Adapt to ring maximum distance (in cm)
#define ACTION_DELAY 50 // Delay in ms between one loop and another

UltraSonicDistanceSensor us_sensor_front(TRIGGER, ECHO_FRONT, MAX_DISTANCE);
UltraSonicDistanceSensor us_sensor_back(TRIGGER, ECHO_BACK, MAX_DISTANCE);
L298N_Rockobot motor_driver(ENA, ENB, IN1, IN2, IN3, IN4);

// Example scheme: 
// First read values from sensor, then think how to act and end with actuators
void sense() {

}

void think() {

}

void act() {

}

void setup() {
  // Both Motors and US sensors pinModes are set in their respective classes
  pinMode(IR_FRONT, INPUT);
  pinMode(IR_BACK, INPUT);
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);

  Serial.begin(9600); // Remove in final version
}

void loop() {
  uint8_t example_var = 1;

  delay(ACTION_DELAY); 
}
