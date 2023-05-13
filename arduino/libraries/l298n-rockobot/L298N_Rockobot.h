/*
  L298N Rockobot specific library. 
  Made for controlling Rockobot v1.0 motors with the L298N motor driver
  Created by Pelochus, May 2023.
*/

#ifndef L298N_ROCKOBOT_H
#define L298N_ROCKOBOT_H

#include "Arduino.h"

// Created for more readable code when selecting direction
enum direction_t {
	FWD,
	RWD,
	LEFT,
	RIGHT
};

// Created for more readable code when selecting motors
enum motor_t {
	LMOTOR,
	RMOTOR,
	BOTH
};

class L298N_Rockobot {
private:

    const uint8_t ENA;
	const uint8_t ENB;
	const uint8_t IN1;
	const uint8_t IN2;
	const uint8_t IN3;
	const uint8_t IN4;
	uint8_t speed = 255; // Max speed, equals 100%
	direction_t direction = FWD; // Default direction is forward
	
	/**
	 * @brief Sets direction for motor L or R
     * @param motor, selects which motor, can be both
	 * @param new_direction, selects which direction to be applied
     */
	void set_motor_direction(const motor_t motor, const direction_t new_direction) const;
	
public:

    /**
	 * @brief Class constructor
     * @param ena Controls power delivered to motor A
	 * @param enb Controls power delivered to motor B
	 * @param in1 to in4 Controls H-Bridge inside L298N Driver 
     */
    L298N_Rockobot(uint8_t ena, uint8_t enb, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);

    /**
     * Returns current robot direction
     * @returns enum direction_t with current direction
     */
    inline direction_t current_direction() const;
	
	/**
     * Returns current robot speed
     * @returns uint8_t with current speed
     */
    inline uint8_t current_speed() const;
	
	/**
     * Sets new speed
	 * @param speed, accepted in range 0-255
	 * @note Motors will probably not work (or work slowly and stressed) with values below 100
     */
    void set_speed(const uint8_t new_speed);
	
	/**
     * Sets a new direction
	 * @param new_direction, entered via enum direction_t
     */
    void set_direction(const direction_t new_direction);

};

#endif // L298N_ROCKOBOT_H
