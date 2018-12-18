/*
 * hmi.c
 *
 * Created: 18.12.2018 21:29:35
 *  Author: Mike
 */ 
#include "hmi.h"

void hmiInit() {
	DDRD |= (1<<led); // led
	PORTD |= (1<<button);
	
	TCCR0 |= (1<<CS02);//Preksaler = 64,  fpwm = 976,5Hz
	TIMSK |= (1<<TOIE0);
}