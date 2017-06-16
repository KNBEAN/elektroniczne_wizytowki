/*
 * led.c
 *
 * Created: 08-10-2016 20:14:04
 *  Author: Karol
 */ 

#include "led.h"

void led_init(void){
	led_6to7_DDR |= (led_6 | led_7);
	led_4to5_8to11_DDR |= (led_4 | led_5 | led_8 | led_9 | led_10 | led_11); 
	led_1to3_12to16_DDR |= (led_1 | led_2 | led_3 | led_12 | led_13 | led_14 | led_15 | led_16);
}

void led_all_OFF(void){
	led_6to7_Port &= ~(led_6 | led_7);
	led_4to5_8to11_Port &= ~(led_4 | led_5 | led_8 | led_9 | led_10 | led_11);
	led_1to3_12to16_Port &= ~(led_1 | led_2 | led_3 | led_12 | led_13 | led_14 | led_15 | led_16);
}

void led_all_ON(void){
	led_6to7_Port |= (led_6 | led_7);
	led_4to5_8to11_Port |= (led_4 | led_5 | led_8 | led_9 | led_10 | led_11);
	led_1to3_12to16_Port |= (led_1 | led_2 | led_3 | led_12 | led_13 | led_14 | led_15 | led_16);
}

void led_set(ledFlag_t led_Flag){
	
	led_all_OFF();
	
	uint8_t tmp;
	
	tmp = ((led_Flag & (led_12Flag | led_13Flag | led_14Flag | led_15Flag | led_16Flag)) >> 11);
	tmp |= ( (led_Flag & (led_1Flag | led_2Flag | led_3Flag)) << 5);
	led_1to3_12to16_Port = tmp;
	
	tmp = 0;
	tmp = (led_Flag & (led_4Flag | led_5Flag)) >> 3;				// | led_8Flag | led_9Flag | led_10Flag | led_11Flag));
	tmp |= (led_Flag & (led_8Flag | led_9Flag | led_10Flag | led_11Flag)) >> 4;
	led_4to5_8to11_Port |= tmp;
	
	if (led_Flag & led_6Flag)	led_6to7_Port |= led_6;
	if (led_Flag & led_7Flag)	led_6to7_Port |= led_7;
	
}