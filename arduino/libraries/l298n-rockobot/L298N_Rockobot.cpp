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

direction_t L298N_Rockobot::get_direction() const {
    return this->direction;
}

uint8_t L298N_Rockobot::get_speed() const {
    return this->speed;
}

uint8_t L298N_Rockobot::get_speed_percentage() const {
    // Converts from 8 bit integer to percentage
    return map(this->speed, 0, 255, 0, 100);
}

void L298N_Rockobot::set_speed(const uint8_t new_speed) {
    speed = new_speed;
    set_direction(get_direction());
}

void L298N_Rockobot::set_speed_percentage(uint8_t new_speed) {
    if (new_speed > 100) new_speed = 100;

    // Convert percentage to 8 bit integer
    set_speed(map(new_speed, 0, 100, 0, 255));
}

// Private function, users should not be able to change directions of each single motor
void L298N_Rockobot::set_direction(const direction_t new_direction) {
    direction = new_direction;

    switch (new_direction) {
        case FORWARD:
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, speed);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            analogWrite(ENB, speed);
            break;
        case BACKWARD:
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            analogWrite(ENA, speed);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
            analogWrite(ENB, speed);
            break;
        case LEFT:
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            analogWrite(ENA, speed);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            analogWrite(ENB, speed);
            break;
        case RIGHT:
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, speed);
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
            analogWrite(ENB, speed);
            break;
        case WIDE_LEFT:
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, 0);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            analogWrite(ENB, speed);
            break;
        case WIDE_RIGHT:
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, speed);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
            analogWrite(ENB, 0);
            break;
        case FAST_STOP:
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            digitalWrite(ENA, HIGH);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
            digitalWrite(ENB, HIGH);
            break;
        default:
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, 0);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            analogWrite(ENB, 0);
    }
}
