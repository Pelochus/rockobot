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

#define LMOTOR_PIN 2
#define RMOTOR_PIN 3
#define TRIGGER 4
#define ECHO 5

#define MAX_DISTANCE 200 // Adapt to ring maximum distance (in cm)
#define ACTION_DELAY 50 // Delay in ms between one loop and another

UltraSonicDistanceSensor us_sensor(TRIGGER, ECHO, MAX_DISTANCE);

// Example scheme: 
// First read values from sensor, then think how to act and end with actuators
void sense() {

}

void think() {

}

void act() {

}

void setup() {
  pinMode(LMOTOR_PIN, OUTPUT);
  pinMode(RMOTOR_PIN, OUTPUT);

  Serial.begin(9600); // Remove in final versions
}

void loop() {
  uint8_t example_var = 1;

  delay(ACTION_DELAY); 
}
