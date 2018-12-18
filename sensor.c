/*
 * sensor.c
 *
 * Created: 18.12.2018 20:49:59
 *  Author: Mike
 */ 
#include "sensor.h"

void sensorInit() {
	DDRB |= (1<<cz_pwm);
	PORTC |= (1<<cz_3)|(1<<cz_4)|(1<<cz_5)|(1<<cz_6)|(1<<cz_7);
	PORTD |= (1<<cz_0)|(1<<cz_1)|(1<<cz_2);
	
	TCCR2 |= (1<<WGM21)|(1<<WGM20);//Tryb: Fast PWM
	TCCR2 |= (1<<COM21);//Clear OC0 on Compare Match, set OC0 at BOTTOM
	TCCR2 |= (1<<CS22);//Preksaler = 64,  fpwm = 976,5Hz
}

uint8_t sensorBias() {
	uint8_t bias = 0;
	uint8_t n = 0;

	if(sensor0) {
		bias += 0;
		n++;
		} else if(sensor1) {
		bias += 4;
		n++;
		} else if(sensor2) {
		bias += 8;
		n++;
		} else if(sensor3) {
		bias += 12;
		n++;
		} else if(sensor4) {
		bias += 16;
		n++;
		} else if(sensor5) {
		bias += 20;
		n++;
		} else if(sensor6) {
		bias += 24;
		n++;
		} else if(sensor7) {
		bias += 28;
		n++;
	}

	return bias / n;
}

void sensorReferenceSet(uint8_t value) {
	OCR2 = value;
}