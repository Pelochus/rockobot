/**
  * rockobot-main.ino
  * 
  * Arduino code for Rockobot
  * More information: https://github.com/Pelochus/rockobot/tree/main/arduino 
  *
  * Authors:
  *   Pelochus
  *   Jose-HH
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

uint8_t front_c = 0;
uint8_t back_c = 0;
uint8_t search_stage = 0;

const uint16_t IR_THRESHOLD = 300; // If higher than this, we are entering danger zone (out of ring)
const uint8_t STUCK_COUNT = 40;
//TODO
const uint8_t TURN_CYCLES = 22;
const uint8_t US_NEARBY_ENEMY = 40; // When is considered to be near an enemy (cm)
const uint8_t FULL_POWER_NEAR_ENEMY = 20;


// Structure: 
// First read values from sensor, then think what to do and send info to motors
void rockobot_think() {
  float front_distance = us_front.measureDistanceCm();
  float back_distance = us_back.measureDistanceCm();
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

    if (front_c > STUCK_COUNT) {
      driver.set_speed_percentage(100);
      driver.set_direction(RIGHT);
      front_c /= 2; 
    }
    
    front_c++;
    back_c = 0;
  }
  else if (ir_back > IR_THRESHOLD) {
    driver.set_speed_percentage(100);
    driver.set_direction(FORWARD);

    if (back_c > STUCK_COUNT) {
      driver.set_speed_percentage(100);
      driver.set_direction(RIGHT);
      back_c /= 2; 
    }

    front_c = 0;
    back_c++;
  }
  else if (ir_right > IR_THRESHOLD) {
    driver.set_speed_percentage(100);
    driver.set_direction(LEFT);

    driver.set_direction(FORWARD);

  }
  else if (ir_left > IR_THRESHOLD) {
    driver.set_speed_percentage(100);
    driver.set_direction(RIGHT);

    driver.set_direction(FORWARD);
  }
  else {
    ///////////////////////////////////////////////////////
    // Not in danger zone, search and target enemy with US
    ///////////////////////////////////////////////////////
    
    uint8_t us_min = (front_distance > back_distance) ? back_distance : front_distance;
    bool search = (us_min < US_NEARBY_ENEMY) ? false : true; // Decide whether to skip or not search stage

    //////////
    // Search
    //////////
    
    if (search) {
      switch (search_stage) {
        case 0 ... TURN_CYCLES-1:
          driver.set_speed_percentage(70);
          driver.set_direction(RIGHT);
          break;
        case TURN_CYCLES ... 2*TURN_CYCLES:
          driver.set_speed_percentage(70);
          driver.set_direction(LEFT);
          break;
        default:
          driver.set_speed_percentage(70);
          driver.set_direction(FORWARD);
      }

      search_stage++;
      search_stage %= 3*TURN_CYCLES;
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
