/*
 * hmi.h
 *
 * Created: 18.12.2018 21:29:22
 *  Author: Mike
 */ 


#ifndef HMI_H_
#define HMI_H_

#include <avr/io.h>

#define button PD5
#define led PD6
#define ButtonPush !(PIND & (1<<button))

void hmiInit();

#endif /* HMI_H_ */