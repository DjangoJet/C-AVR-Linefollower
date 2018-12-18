/*
 * pwm.h
 *
 * Created: 18.12.2018 21:01:34
 *  Author: Mike
 */ 


#ifndef PID_H_
#define PID_H_

#include <avr/io.h>

#define TaskValue 14
#define P 1
#define D 0.2

int8_t pidOutput(int8_t current);

#endif /* PID_H_ */