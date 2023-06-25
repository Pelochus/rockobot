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
#define IR_RIGHT A1
#define IR_LEFT A2
#define IR_FRONT A3

#define MAX_DISTANCE 200 // Adapt to ring max dimension
#define ACTION_DELAY 50 // Delay in ms between one full loop and next loop
#define STARTUP_DELAY 3000 // 3 seconds mandatory delay for competition

UltraSonicDistanceSensor us_front(TRIGGER, ECHO_FRONT, MAX_DISTANCE);
UltraSonicDistanceSensor us_back(TRIGGER, ECHO_BACK, MAX_DISTANCE);
L298N_Rockobot driver(ENA, ENB, IN1, IN2, IN3, IN4);

// Structure: 
// First read values from sensor, then think what to do and send info to motors
void rockobot_think() {
  const uint16_t IR_THRESHOLD = 300; // If higher than this, we are entering danger zone (out of ring)

  uint8_t front_distance = us_front.measureDistanceCm();
  uint8_t back_distance = us_back.measureDistanceCm();
  uint16_t ir_front = analogRead(IR_FRONT);
  uint16_t ir_back = analogRead(IR_BACK);
  uint16_t ir_right = analogRead(IR_RIGHT);
  uint16_t ir_left = analogRead(IR_LEFT);

  //////////////////////////////////
  // Prioritise exiting danger zone
  //////////////////////////////////
  if (ir_front > IR_THRESHOLD) {
    driver.set_speed_percentage(100);
    driver.set_direction(BACKWARD);
  }
  else if (ir_back > IR_THRESHOLD) {
    driver.set_speed_percentage(100);
    driver.set_direction(FORWARD);
  }
  else if (ir_right > IR_THRESHOLD) {
    driver.set_speed_percentage(100);
    driver.set_direction(LEFT);

    // TODO remove since every void loop() it will repeat itself anyway?
    // Rotate while IR detects the black line
    while (ir_right > IR_THRESHOLD) {
      ir_right = analogRead(IR_RIGHT);
    }

    driver.set_direction(FORWARD);
  }
  else if (ir_left > IR_THRESHOLD) {
    driver.set_speed_percentage(100);
    driver.set_direction(RIGHT);

    // TODO remove since every void loop() it will repeat itself anyway?
    // Rotate while IR detects the black line
    while (ir_left > IR_THRESHOLD) {
      ir_left = analogRead(IR_LEFT);
    }

    driver.set_direction(FORWARD);
  }
  else {
    ///////////////////////////////////////////////////////
    // Not in danger zone, search and target enemy with US
    ///////////////////////////////////////////////////////
    
    const uint8_t US_NEARBY_ENEMY = 50; // When is considered to be near an enemy (cm)
    const uint8_t FULL_POWER_NEAR_ENEMY = 25;
    uint8_t us_min = (front_distance > back_distance) ? back_distance : front_distance;
    bool search = (us_min < US_NEARBY_ENEMY) ? false : true; // Decide whether to skip or not search stage

    //////////
    // Search
    //////////

    // Complete loop will last LOOP_ITERATIONS * LOOP_DURATION milliseconds
    const uint8_t LOOP_ITERATIONS = 10;
    const uint8_t LOOP_DURATION = 25;

    uint8_t loop_exit = 0;
    while (search && loop_exit > LOOP_ITERATIONS) {
      driver.set_speed_percentage(65);
      driver.set_direction(RIGHT); // Could be left, indifferent

      front_distance = us_front.measureDistanceCm();
      back_distance = us_back.measureDistanceCm();

      us_min = (front_distance > back_distance) ? back_distance : front_distance;
      search = (us_min < US_NEARBY_ENEMY) ? false : true;
      loop_exit++;

      delay(LOOP_DURATION);
    }

    ////////////////
    // Target enemy
    ////////////////

    driver.set_speed_percentage(80); // Not necessary to use full power

    if (front_distance < back_distance) driver.set_direction(FORWARD);
    else driver.set_direction(BACKWARD);

    // Activate max power if close enough
    if (us_min < FULL_POWER_NEAR_ENEMY) driver.set_speed_percentage(100);
  }
}

void setup() {
  // Both Motors and US sensors pinModes are set inside their respective classes
  pinMode(IR_FRONT, INPUT);
  pinMode(IR_BACK, INPUT);
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);

  Serial.begin(9600); // Remove in final version

  driver.set_speed_percentage(0);
  delay(STARTUP_DELAY); // Mandatory delay for official competition
}

void loop() {
  //rockobot_think();

  // SECCION DE PRUEBAS, BORRAR CUANDO NO SEA NECESARIO

  // Serial.println(us_front.measureDistanceCm());

  driver.set_direction(BACKWARD);
  driver.set_speed_percentage(100);
  delay(5000);
  driver.set_speed_percentage(0);
  delay(3000);

/*
  delay(500);

  driver.set_speed_percentage(75);

  while(true) {
    while(analogRead(IR_FRONT) < 300) {} // Wait till we detect black line

    driver.set_speed_percentage(0);
    delay(500);
    driver.set_direction(RIGHT);
    driver.set_speed_percentage(80);
    delay(2000);
    driver.set_speed_percentage(0);
    delay(500);
    driver.set_direction(FORWARD);
    driver.set_speed_percentage(75);

    while(analogRead(IR_FRONT) < 300) {}

    driver.set_speed_percentage(0);
    delay(500);
    driver.set_direction(LEFT);
    driver.set_speed_percentage(80);
    delay(2000);
    driver.set_speed_percentage(0);
    delay(500);
    driver.set_direction(BACKWARD);
    driver.set_speed_percentage(75);

  }
  
  driver.set_speed_percentage(0);

  delay(10000);
  */
  
  delay(ACTION_DELAY);
}
