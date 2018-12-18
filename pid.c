/*
 * pwm.c
 *
 * Created: 18.12.2018 21:01:53
 *  Author: Mike
 */ 
#include "pid.h"

int8_t lastError = 0;

int8_t pidOutput(int8_t current) {
	int8_t error = TaskValue - current;
	int8_t valueRegulation = P*error + D*(error - lastError);
	lastError = error;
	return valueRegulation;
}