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

const uint16_t FULL_POWER_THRESHOLD = 8000; // After 8 seconds, always use full power
const uint16_t IR_THRESHOLD = 300; // If higher than this, we are entering danger zone (out of ring)
const uint8_t US_NEARBY_ENEMY = 30; // When is considered to be near an enemy (cm)
const uint8_t FULL_POWER_NEAR_ENEMY = 10; // When under this value in cm, activate maximum speed
const uint8_t STUCK_COUNT = 50; // If we reach 50 loops detecting black lines, we are stuck
const uint8_t TURN_CYCLES = 700 / ACTION_DELAY; // Loops required for 90º rotation at 100% speed (We calculated 700 ms 90 deg at 16.7V battery)

uint16_t extra_delay = 0;
uint16_t initial_time = 0;
uint16_t current_time = 0;
uint8_t front_counter = 0;
uint8_t back_counter = 0;
uint8_t search_stage = 0;

// Structure: 
// First read values from sensor, then think what to do and send info to motors
void rockobot_think() {
  extra_delay = 800; // Add an extra delay when encountering black lines

  ////////////////
  // Read Sensors
  ////////////////
  uint8_t front_distance = us_front.measureDistanceCm();
  uint8_t back_distance = us_back.measureDistanceCm();
  bool ir_front = (analogRead(IR_FRONT) > IR_THRESHOLD);
  bool ir_back = (analogRead(IR_BACK) > IR_THRESHOLD);
  bool ir_right = (analogRead(IR_RIGHT) > IR_THRESHOLD);
  bool ir_left = (analogRead(IR_LEFT) > IR_THRESHOLD);

  /////////
  // Think
  /////////
  uint8_t speed = 100;
  direction_t direction = driver.get_direction(); // Maintain same path while thinking
  
  // Anti-ramp
  if ((ir_front ? 1 : 0) + (ir_back ? 1 : 0) + 
      (ir_right ? 1 : 0) + (ir_left ? 1 : 0) > 2) {
    direction = RIGHT;
  }
  else if (ir_front) {
    direction = BACKWARD;

    if (front_counter > STUCK_COUNT) {
      direction = RIGHT;
      front_counter /= 2; 
    }
    
    front_counter++;
    back_counter = 0;
  }
  else if (ir_back) {
    direction = FORWARD;

    if (back_counter > STUCK_COUNT) {
      direction = RIGHT;
      back_counter /= 2; 
    }

    front_counter = 0;
    back_counter++;
  }
  // We want even higher delays on rotations, because robot is slower with only one motor
  else if (ir_right) {
    extra_delay += 200;
    direction = WIDE_LEFT;
  }
  else if (ir_left) {
    extra_delay += 200;
    direction = WIDE_RIGHT;
  }
  else {
    ///////////////////////////////////////////////////////
    // Not in danger zone, search and target enemy with US
    ///////////////////////////////////////////////////////
    extra_delay = 0; // Reset delay if not in danger (black lines)
    direction = FORWARD;
    speed = 85;
    
    uint8_t us_min = (front_distance > back_distance) ? back_distance : front_distance;
    bool search = us_min > US_NEARBY_ENEMY; // Decide whether to skip or not search stage

    //////////
    // Search
    //////////
    
    if (search) {
      switch (search_stage) {
        case 0 ... (TURN_CYCLES - 1):
          direction = RIGHT;
          break;
        case TURN_CYCLES ... (2 * TURN_CYCLES):
          direction = LEFT;
          break;
        default:
          direction = FORWARD;
      }

      search_stage++;
      search_stage %= 3 * TURN_CYCLES;
    }

    ////////////////
    // Target enemy
    ////////////////

    if (front_distance < back_distance) direction = FORWARD;
    else direction = BACKWARD;

    // Activate max power if close enough
    if (us_min < FULL_POWER_NEAR_ENEMY) speed = 100;
  }

  //////////////////////
  // Act after thinking
  //////////////////////

  driver.set_speed_percentage(speed);
  driver.set_direction(direction);
}

void setup() {
  // Both Motors and US sensors pinModes are set inside their respective classes
  pinMode(IR_FRONT, INPUT);
  pinMode(IR_BACK, INPUT);
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);

  driver.set_speed_percentage(0);
  delay(STARTUP_DELAY); // Mandatory delay for official competition
  initial_time = millis(); 
}

void loop() {
  rockobot_think();

  // Overwrite speed always to 100% if combat takes too long
  // This also allows getting to full speed if we are in a pushing struggle and
  // the enemy is short enough that the US sensor doesn't activate full power 
  current_time = millis();
  if (current_time - initial_time > FULL_POWER_THRESHOLD) {
    driver.set_speed_percentage(100);
  }

  delay(ACTION_DELAY + extra_delay);
}
