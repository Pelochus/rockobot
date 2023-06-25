/*
  L298N Rockobot specific library. 
  Made for controlling Rockobot v1.0 motors with the L298N motor driver
  Created by Pelochus, May 2023.
*/

#ifndef L298N_ROCKOBOT_H
#define L298N_ROCKOBOT_H

#include "Arduino.h"

enum direction_t {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

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
	bool in_fast_stop = false;
	uint8_t speed = 255; // Max speed, equals 100%
	direction_t direction = FORWARD; // Default direction is forward
	
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
     * @brief Returns current robot direction
     * @returns enum direction_t with current direction
     */
    direction_t get_direction() const;
	
	/**
     * @brief Returns current robot speed
     * @returns uint8_t with current speed
     */
    uint8_t get_speed() const;
	
	/**
     * @brief Returns current robot speed, in percentage
     * @returns uint8_t with current speed
     */
    uint8_t get_speed_percentage() const;
    
    /**
     * @brief Returns true if motors are in fast stop
     * @returns bool
     */
    bool is_in_fast_stop() const;
	
	/**
     * @brief Sets new speed
	 * @param speed, accepted in range 0-255
	 * @note Motors will probably not work (or work slowly and stressed) with values below 100
     */
    void set_speed(const uint8_t new_speed);
	
	/**
     * @brief Sets new speed, in percentage
	 * @param speed, accepted in range 0-100
	 * @note Motors will probably not work well with values below 40%
     */
    void set_speed_percentage(uint8_t new_speed);
	
	/**
     * @brief Sets a new direction
	 * @param new_direction, entered via enum direction_t
     * @note sets speed to previous speed if called after fast_stop
     */
    void set_direction(const direction_t new_direction);
    
    /**
     * @brief Stops actively shorting the motor, fast stopping at a high speed can cause
     * damage to the motor or estructural integrity of the device
	 * @param new_direction, entered via enum direction_t
     */
    void fast_stop();
};

#endif // L298N_ROCKOBOT_H
