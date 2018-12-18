/*
 * sensor.h
 *
 * Created: 18.12.2018 20:50:17
 *  Author: Mike
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

#include <avr/io.h>

#define cz_0 PD4
#define cz_1 PD3
#define cz_2 PD2
#define cz_3 PC5
#define cz_4 PC4
#define cz_5 PC3
#define cz_6 PC2
#define cz_7 PC1
#define cz_pwm PB3

#define sensor0 !(PIND & (1<<cz_0))
#define sensor1 !(PIND & (1<<cz_1))
#define sensor2 !(PIND & (1<<cz_2))
#define sensor3 !(PINC & (1<<cz_3))
#define sensor4 !(PINC & (1<<cz_4))
#define sensor5 !(PINC & (1<<cz_5))
#define sensor6 !(PINC & (1<<cz_6))
#define sensor7 !(PINC & (1<<cz_7))

uint8_t referenceSensor;

void sensorInit();
void sensorReferenceSet(uint8_t value);
uint8_t sensorBias();

#endif /* SENSOR_H_ */