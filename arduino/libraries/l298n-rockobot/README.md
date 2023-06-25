# L298N library for Rockobot
This README will briefly explain the what the functions of the library for controlling Rockobot's motors. All of them are very simple, so we will only take a look at each function and what they do, not how they are programmed

## enums
We have created two enums for simplifying code reading, one for setting the direction of the robot and one for referring to a specific motor (or both):

```c++
enum direction_t {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
 	WIDE_LEFT,
  	WIDE_RIGHT
};

enum motor_t {
	LMOTOR,
	RMOTOR,
	BOTH
};
```

```motor_t``` does not need to be used outside the class, because the public functions always set both motors at once depending on the direction selected.
```WIDE_LEFT``` and ```WIDE_RIGHT``` turn off one motor so rotation is in a wider circle instead of in its own center

## Constructor
Very simple stuff, just call it with the corresponding Arduino pins for each L298N driver input
```c++
L298N_Rockobot(uint8_t ena, uint8_t enb, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);
```
For the v1.0 PCB it's this order (respectively):

**3, 4, 5, 6, 7, 9**

## Getters
They do what their name say, so the first one returns a ```direction_t``` with the current direction. 
The other two return the current speed in two forms: range 0-255 (8 bit value, because PWM is 8 bit) and range 0-100% for the percentage version
```c++
direction_t get_direction() const;

uint8_t get_speed() const;

uint8_t get_speed_percentage() const;

bool is_in_fast_stop() const;
```
## Setters
Exactly the same as the getters but setters. The ```set_direction()``` function sets the robot direction, NOT the motors. 
Internally, it uses a private function which sets the motors correspondingly to what direction is wanted.
```c++
void set_speed(const uint8_t new_speed);

void set_speed_percentage(uint8_t new_speed);

void set_direction(const direction_t new_direction);

void fast_stop();
```
