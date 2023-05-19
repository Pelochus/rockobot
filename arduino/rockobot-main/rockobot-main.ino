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
#define ECHO_FRONT 11
#define ECHO_BACK 12

#define IR_BACK A0
#define IR_LEFT A1
#define IR_RIGHT A2
#define IR_FRONT A3

#define MAX_DISTANCE 200 // Adapt to ring max dimension
#define ACTION_DELAY 100 // Delay in ms between one loop and another
#define STARTUP_DELAY 3000 // 3 seconds mandatory delay for competition

UltraSonicDistanceSensor us_front(TRIGGER, ECHO_FRONT, MAX_DISTANCE);
UltraSonicDistanceSensor us_back(TRIGGER, ECHO_BACK, MAX_DISTANCE);
L298N_Rockobot motor_driver(ENA, ENB, IN1, IN2, IN3, IN4);

// Scheme: 
// First read values from sensor, then think what to do and send info to motors
void rockobot_think() {
  const uint16_t IR_THRESHOLD = 300;
  const uint8_t US_NEARBY_ENEMY = 75; // When is considered to be near an enemy

  uint8_t front_distance = us_front.measureDistanceCm();
  uint8_t back_distance = us_back.measureDistanceCm();
  uint16_t ir_front = analogRead(IR_FRONT);
  uint16_t ir_back = analogRead(IR_BACK);
  uint16_t ir_right = analogRead(IR_RIGHT);
  uint16_t ir_left = analogRead(IR_LEFT);

  // Prioritise IR because it means the robot is getting out of the ring
  if (ir_front > IR_THRESHOLD) {

  }
  else if (ir_back > IR_THRESHOLD) {

  }
  else if (ir_right > IR_THRESHOLD) {

  }
  else if (ir_left > IR_THRESHOLD) {

  }
  else { // Not in danger zone, search and target enemy with US + motors

  }
}

void setup() {
  // Both Motors and US sensors pinModes are set in their respective classes
  pinMode(IR_FRONT, INPUT);
  pinMode(IR_BACK, INPUT);
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);

  Serial.begin(9600); // Remove in final version

  delay(STARTUP_DELAY); // Mandatory delay for official competition
}

void loop() {
  //rockobot_think();

  // SECCION DE PRUEBAS, BORRAR CUANDO NO SEA NECESARIO
  Serial.println(motor_driver.current_speed());
  Serial.println(motor_driver.current_speed_percentage());

  if (motor_driver.current_speed_percentage() == 0) motor_driver.set_speed_percentage(100);
  motor_driver.set_speed_percentage(motor_driver.current_speed_percentage() - 1);

  // Serial.println(us_front.measureDistanceCm());

  delay(ACTION_DELAY);
}
