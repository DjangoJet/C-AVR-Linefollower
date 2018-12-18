/*
 * motor.h
 *
 * Created: 18.12.2018 21:08:53
 *  Author: Mike
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>

#define m1 PB5
#define m2 PB4
#define m3 PB0
#define m4 PD7
#define pwm_12 PB2
#define pwm_34 PB1

void motorRightFront();
void motorRightBack();
void motorRightSpeed(uint8_t speed);
void motorLeftFront();
void motorLeftBack();
void motorLeftSpeed(uint8_t speed);
void motorSet(int8_t);
void motorInit();

#endif /* MOTOR_H_ */