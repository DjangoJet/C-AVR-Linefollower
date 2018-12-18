/*
 * Linefollower.c
 *
 * Created: 18.12.2018 20:48:00
 * Author : Mike
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "motor.h"
#include "sensor.h"
#include "pid.h"
#include "hmi.h"

#define True 1
#define False 0

int main(void) {
	sensorInit();
	motorInit();
	hmiInit();
	
	sei();
	
	uint8_t state = False;
	
	while(state == False) {
		if(ButtonPush) {
			uint8_t lowLimit = 0;
			uint8_t highLimit = 0;
			uint8_t i = 0;
			for(i=0 ; i<255 ; i++) {
				
				sensorReferenceSet(i);
				if(sensor0 || sensor1 || sensor2 || sensor3 || sensor4 || sensor5 || sensor6 || sensor7) {
					lowLimit = i;
					i = 255;
				}
			}
			for(i=255 ; i>0 ; i--) {
				sensorReferenceSet(i);
				if(!(sensor0 && sensor1 && sensor2 && sensor3 && sensor4 && sensor5 && sensor6 && sensor7)) {
					highLimit = i;
					i = 0;
				}
			}
			referenceSensor = (lowLimit + highLimit)/2;
			state = True;
			_delay_ms(2000);
		}
	}
	
	cli();
	sensorReferenceSet(referenceSensor);
	while(True) {
		
	
	}
}

ISR(TIMER0_OVF_vect)
{
	PORTD ^= (1<<led);
}

