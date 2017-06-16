/*
 * animations.c
 *
 * Created: 12-10-2016 01:48:10
 *  Author: Karol
 */ 

#include "animations.h"
#include "hw_delay.h"
#include "led.h"

uint16_t animation_3_tab[] = {
	(led_1Flag | led_16Flag | led_15Flag),
	(led_2Flag | led_14Flag),
	(led_3Flag | led_13Flag),
	(led_4Flag | led_12Flag),
	(led_5Flag | led_11Flag),
	(led_6Flag | led_10Flag),
	(led_7Flag | led_8Flag | led_9Flag),
};

uint16_t animation_4_tab[] = {
	(led_1Flag | led_16Flag | led_15Flag | led_7Flag | led_8Flag | led_9Flag),
	(led_2Flag | led_14Flag | led_6Flag | led_10Flag),
	(led_3Flag | led_13Flag | led_5Flag | led_11Flag),
	(led_4Flag | led_12Flag),
	(led_3Flag | led_13Flag | led_5Flag | led_11Flag),
	(led_2Flag | led_14Flag | led_6Flag | led_10Flag),
	(led_1Flag | led_16Flag | led_15Flag | led_7Flag | led_8Flag | led_9Flag)
};

static void animation_1(void);
static void animation_2(void);
static void animation_3(void);
static void animation_4(void);
static void animation_5(void);

void animation_1(void){
	uint16_t step = 1;
	while (step > 0)
	{
		led_set(step);
		hw_sleep_ms(100);
		step = step << 1;
	}
}

void animation_2(void){
	uint16_t step = (1<<15);
	while (step > 0)
	{
		led_set(step);
		hw_sleep_ms(100);
		step = step >> 1;
	}
}

void animation_3(void){
	for(uint8_t step = 0; step < 7; ++step){
		led_set(animation_3_tab[step]);
		hw_sleep_ms(150);
	}
	
	for(uint8_t step = 7; step > 0; --step){
		led_set(animation_3_tab[step-1]);
		hw_sleep_ms(150);
	}
}

void animation_4(void){
		for(uint8_t step = 0; step < 7; ++step){
			led_set(animation_4_tab[step]);
			hw_sleep_ms(150);
		}
}

void animation_5(void){
	for (uint8_t step = 0; step < 5; ++step)
	{
		led_set(led_1Flag | led_3Flag | led_5Flag | led_7Flag | led_9Flag | led_11Flag | led_13Flag | led_15Flag);
		hw_sleep_ms(200);
		led_set(led_2Flag | led_4Flag | led_6Flag | led_8Flag | led_10Flag | led_12Flag | led_14Flag | led_16Flag);
		hw_sleep_ms(200);
	}
}

void animation_show(uint8_t animation){
	switch (animation)
	{
	case 0:
		animation_1();
		break;
	case 1:
		animation_2();
		break;
	case 2:
		animation_3();
		break;
	case 3:
		animation_4();
		break;
	case 4:
		animation_5();
		break;
	}
}
