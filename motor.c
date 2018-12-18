/*
 * motor.c
 *
 * Created: 18.12.2018 21:08:36
 *  Author: Mike
 */ 
#include "motor.h"

int8_t baseSpeed = 100;

void motorRightFront() {
	PORTB &= ~(1<<m3);
	PORTD &= ~(1<<m4);
	
	PORTD |= (1<<m4);
}

void motorRightBack() {
	PORTB &= ~(1<<m3);
	PORTD &= ~(1<<m4);

	PORTB |= (1<<m3);
}

void motorLeftFront() {
	PORTB &= ~((1<<m1)|(1<<m2));

	PORTB |= (1<<m1);
}

void motorLeftBack() {
	PORTB &= ~((1<<m1)|(1<<m2));

	PORTB |= (1<<m2);
}

void motorLeftSpeed(uint8_t speed) {
	OCR1B = speed;
}

void motorRightSpeed(uint8_t speed) {
	OCR1A = speed;
}

void motorSet(int8_t valueRegulation) {
	int8_t speedBias = valueRegulation/10;
	motorLeftSpeed(baseSpeed + speedBias);
	motorRightSpeed(baseSpeed - speedBias);
}

void motorInit() {
	DDRB |= (1<<m1)|(1<<m2)|(1<<m3)|(1<<m4)| // wyjscie driver
			(1<<pwm_12)|(1<<pwm_34); // pwm driver
			
	TCCR1A |= (1<<WGM10);//Tryb: Fast PWM 8bit
	TCCR1B |= (1<<WGM12);
	TCCR1A |= (1<<COM1A1)|(1<<COM1B1);//Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM
	TCCR1B |= (1<<CS10)|(1<<CS11);//Preksaler = 64,  fpwm = 976,5Hz
}