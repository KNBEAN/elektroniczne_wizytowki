/*
 * hw_delay.c
 *
 * Created: 11-10-2016 12:23:06
 *  Author: Karol
 */ 

#include <avr/interrupt.h>
#include "hw_delay.h"
#include "common.h"

volatile static uint16_t time = 0;

uint16_t getCurrentTime(void){
	return time;
}

void hw_delay_ms(uint16_t delay_time){
	//Zerowanie preskalera?
	uint16_t endTime = time + delay_time;
	while (time != endTime);
}

void hw_sleep_ms(uint16_t delay_time){
	
	uint16_t endTime = time + delay_time;
	MCUCR |= (1<<SE);
	while (time != endTime){
		asm volatile("SLEEP");
		asm volatile("NOP");
	};
	MCUCR &= ~(1<<SE);
}

void hw_sleep(uint8_t sleep_mode){
	if (sleep_mode == 1) MCUCR |= (1 << SM0);
	if (sleep_mode == 2) MCUCR |= (1 << SM1);
	MCUCR |= (1<<SE);
	asm volatile("SLEEP");
	asm volatile("NOP");
	MCUCR &= ~((1<<SE) | (1<<SM0) | (1<<SM1));
}

ISR(TIMER0_COMPA_vect){
	time++;
}