/*
 * wizytowka.c
 *
 * Created: 08-10-2016 18:15:41
 * Author : Karol
 */ 

#include "common.h"
#include "avr/interrupt.h"
#include "led.h"
#include "hw_delay.h"
#include "animations.h"

#define buttonDDR DDRD
#define buttonPort PORTD
#define buttonPinReg PIND
#define buttonPin PIND2

static void init(void);
static void initIntButton(void);

volatile uint8_t animation = 0;

int main(void)
{
	init();
	
    while (1) 
    {
		animation %= 5;
		animation_show(animation);
		led_all_OFF();
		GIMSK |= (1<<INT0);
		if ( (buttonPinReg & (1<<buttonPin)))	hw_sleep(sleep_PowerDown);
    }
}

void init(void){
	ACSR |= (1<<ACD);
	PRR |= (1<<PRTIM1) | (1 << PRUSI) | (1 << PRUSART);

	hw_delay_init();
	led_init();
	initIntButton();
	sei();
}

void initIntButton(void){
	buttonDDR &= ~(1<<buttonPin);
	buttonPort |= (1<<buttonPin);
	
//	MCUCR |= (1<<ISC01) | (1<<ISC00);
	GIMSK |= (1<<INT0);
}

ISR(INT0_vect){
	animation++;
	GIMSK &= ~(1<<INT0);
}