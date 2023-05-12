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

// TODO change pin numbers
#define LMOTOR_EN 2
#define LMOTOR_IN1 3
#define LMOTOR_IN2 4
#define RMOTOR_IN1 5
#define RMOTOR_IN2 6
#define RMOTOR_EN 7

#define TRIGGER 4
#define ECHO_FRONT 5
#define ECHO_BACK 5

#define IR_READ_FRONT_PIN A2
#define IR_READ_BACK_PIN A2

#define MAX_DISTANCE 200 // Adapt to ring maximum distance (in cm)
#define ACTION_DELAY 50 // Delay in ms between one loop and another

UltraSonicDistanceSensor us_sensor_front(TRIGGER, ECHO_FRONT, MAX_DISTANCE);
UltraSonicDistanceSensor us_sensor_back(TRIGGER, ECHO_BACK, MAX_DISTANCE);

// Example scheme: 
// First read values from sensor, then think how to act and end with actuators
void sense() {

}

void think() {

}

void act() {

}

void setup() {
  /*
  pinMode(LMOTOR_IN1, OUTPUT);
  pinMode(LMOTOR_IN2, OUTPUT);
  pinMode(LMOTOR_EN, OUTPUT);
  pinMode(RMOTOR_IN1, OUTPUT);
  pinMode(RMOTOR_IN2, OUTPUT);
  pinMode(RMOTOR_EN, OUTPUT);

  digitalWrite(LMOTOR_IN1, HIGH);
  digitalWrite(LMOTOR_IN2, LOW);
  */

  Serial.begin(9600); // Remove in final versions
}

void loop() {
  uint8_t example_var = 1;

  delay(ACTION_DELAY); 
}
