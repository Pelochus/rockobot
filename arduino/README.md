# Software
This section will focus on the software side of Rockobot

## Components
- Arduino NANO V3 or clone. We used Elegoo NANO V3

## Tools
- Computer
- Mini USB-B to USB-A/USB-C
- Arduino IDE

## Functions
The majority of functions here are very simple, except for the main function that decides what to do. There is information about the library for controlling the motor driver [here](https://github.com/Pelochus/rockobot/blob/main/arduino/libraries/l298n-rockobot/README.md). Let's take a look at the main function of Rockobot:
```c++
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
  }

  /**
   * Rest of IR ifs
   */

  // We want even higher delays on rotations, because robot is slower with only one motor
  else if (ir_right) {
    extra_delay += 200;
    direction = WIDE_LEFT;
  }
  else {
    ///////////////////////////////////////////////////////
    // Not in danger zone, search and target enemy with US
    ///////////////////////////////////////////////////////
    extra_delay = 0; // Reset delay if not in danger
    speed = 80;

    int16_t us_diff = front_distance - back_distance; // If negative, back_distance is farther from something and viceversa
    uint8_t us_min = (front_distance < back_distance) ? front_distance : back_distance;
    bool search = us_min > US_NEARBY_ENEMY; // Decide whether to skip or not search stage

    //////////
    // Search
    //////////

    if (search) {
      switch (search_stage) {
        case 0 ... (TURN_CYCLES - 1):
          direction = RIGHT;
          break;
        case 2 * TURN_CYCLES ... (3 * TURN_CYCLES):
          direction = LEFT;
          break;
        default:
          direction = FORWARD;
      }

      search_stage++;
      search_stage %= 4 * TURN_CYCLES;
    }

    ////////////////
    // Target enemy
    ////////////////

    if (abs(us_diff) > DIRECTION_CHANGE_THRESHOLD && us_min < US_NEARBY_ENEMY) {
      if (us_diff > 0) direction = BACKWARD;
      else if (us_diff < 0) direction = FORWARD;
      // else will retain current direction
    }

    // Activate max power if close enough
    if (us_min < FULL_POWER_NEAR_ENEMY) speed = 100;
  }

  //////////////////////
  // Act after thinking
  //////////////////////

  driver.set_speed_percentage(speed);
  driver.set_direction(direction);
}
```

As we can see, we can easily divide the function in 3 parts: **sense, think and act**

We have some extra functionality to the robot, like the ```extra_delay``` variable, which augments the delay between one loop and the following when encountering black lines. This way, we do not allow the robot to rethink actions very frequently while it is avoiding black lines, just escapes from the black lines. Some of this extra functionality is outside the main function and is implemented either on the ```void setup()``` or the ```void loop()```. For extra details on the main function, see [rockobot-main.ino](https://github.com/Pelochus/rockobot/blob/main/arduino/rockobot-main/rockobot-main.ino)

## Reducing the number of digital pins
Since an Arduino NANO only has 13 digital pins, controlling 2 US sensors, 4 infrarred sensors and 2 motors is almost impossible without using transistors or other methods of switching elements.
Luckily, since we have some redundancy, we can "compress" the number of pins used. First, let's see how many pins we need:

- **2 digital pins** for each ultrasonic sensor, so **4 in total**
- **1 digital pin** per infrarred sensor, **4 in total**
- **4 analogic pins**, 1 per infrarred sensor
- **6 digital pins** (2 must be PWM) for the motor driver

As we can see, **14 digital pins**, 1 more than what a Nano has. We reduced the pins the following way:

- **3 digital pins** for the US sensors, we used the same pin for the trigger pin of each one, since we will mostly reading both at once
- **0 digital pins** for the infrarred sensors, changed for 5V pin. This was necessary for the infrarred LED to be turned on or off, but we can keep it on indefinitely
- The driver **could be using 5 pins** (combine the digital pin used for PWM), but we will keep them separately just in case we want to have different speeds per motor

With this reduction, **we only use 9 digital pins**, having some spare digital pins in case we wanted to add, for example, bumpers or decorative LEDs.

## Ideas
- Switch between IR controlled mode and autonomous mode:
    - Wait for an input at setup with 2 buttons, one for each mode, in loop function, call either autonomous or controlled mode
    - Make the input a key, similar to a car

## Knowledge Base
- [Arduino Docs](https://docs.arduino.cc/)
- [UltraSonic Sensor Library](https://github.com/Martinsos/arduino-lib-hc-sr04)
