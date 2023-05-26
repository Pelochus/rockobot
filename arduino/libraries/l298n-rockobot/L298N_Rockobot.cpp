/*
  L298N Rockobot specific library. 
  Made for controlling Rockobot v1.0 motors with the L298N motor driver
  Created by Pelochus, May 2023.
*/

#include "Arduino.h"
#include "L298N_Rockobot.h"

L298N_Rockobot::L298N_Rockobot(uint8_t ena, uint8_t enb, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4) 
							 : ENA(ena), ENB(enb), IN1(in1), IN2(in2), IN3(in3), IN4(in4)
{	
	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	
	set_speed(speed);
	set_direction(FORWARD);
}

direction_t L298N_Rockobot::current_direction() const {
	return this->direction;
}

uint8_t L298N_Rockobot::current_speed() const {
	return this->speed;
}

uint8_t L298N_Rockobot::current_speed_percentage() const {
	// Converts from 8 bit integer to percentage
	return map(this->speed, 0, 255, 0, 100);
}

void L298N_Rockobot::set_speed(const uint8_t new_speed) {
	speed = new_speed;
	
	analogWrite(ENA, speed);
	analogWrite(ENB, speed);
}

void L298N_Rockobot::set_speed_percentage(uint8_t new_speed) {
	if (new_speed > 100) new_speed = 100;
	
	// Convert percentage to 8 bit integer
	set_speed(map(new_speed, 0, 100, 0, 255));
}

void L298N_Rockobot::set_direction(const direction_t new_direction) {
	direction = new_direction;
	set_motor_direction(BOTH, direction);
}

// Private function, users should not be able to change directions of each single motor
void L298N_Rockobot::set_motor_direction(const motor_t motor, const direction_t new_direction) const {
	if (motor == BOTH) {
		set_motor_direction(LMOTOR, new_direction);
		set_motor_direction(RMOTOR, new_direction);
	}
	// TODO VERY IMPORTANT. Check if LMOTOR corresponds to IN1/2 and RMOTOR with IN3/4
	// Also check if HIGH/LOW values are set correctly
	else if (motor == LMOTOR) {
		// Makes left motor go forward
		if (new_direction == FORWARD || new_direction == RIGHT) {
			digitalWrite(IN1, HIGH);
			digitalWrite(IN2, LOW);
		}
		else {
			digitalWrite(IN1, LOW);
			digitalWrite(IN2, HIGH);
		}
	}
	else {
		// Makes right motor go forward
		if (new_direction == FORWARD || new_direction == LEFT) {
			digitalWrite(IN3, LOW);
			digitalWrite(IN4, HIGH);
		}
		else {
			digitalWrite(IN3, HIGH);
			digitalWrite(IN4, LOW);
		}
	}
}