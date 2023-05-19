# Software
This section will focus on the software side of Rockobot

## Components
- Arduino NANO V3

## Tools
- Computer
- Mini USB-B to USB-A
- Arduino IDE

## Requirements
- Modular software
- Clean code
- Focus on optimisation

## Functions
The majority of functions here are very simple, except for the main function that decides what to do. There is information about the library for controlling the motor driver [here](https://github.com/Pelochus/rockobot/blob/main/arduino/libraries/l298n-rockobot/README.md). Let's take a look at the main function of Rockobot:
```c++
void loop() {
    // TODO this whole function
}
```

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
