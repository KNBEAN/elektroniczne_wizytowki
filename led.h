/*
 * led.h
 *
 * Created: 08-10-2016 20:14:17
 *  Author: Karol
 */ 


#ifndef LED_H_
#define LED_H_
#include "common.h"

typedef uint16_t ledFlag_t;

#define led_6to7_Port PORTA
#define led_4to5_8to11_Port PORTD
#define led_1to3_12to16_Port PORTB

#define led_6to7_DDR DDRA
#define led_4to5_8to11_DDR DDRD
#define led_1to3_12to16_DDR DDRB

#define led_1 (1<<PINB5)
#define led_2 (1<<PINB6)
#define led_3 (1<<PINB7)
#define led_4 (1<<PIND0)
#define led_5 (1<<PIND1)
#define led_6 (1<<PINA1)
#define led_7 (1<<PINA0)
#define led_8 (1<<PIND3)
#define led_9 (1<<PIND4)
#define led_10 (1<<PIND5)
#define led_11 (1<<PIND6)
#define led_12 (1<<PINB0)
#define led_13 (1<<PINB1)
#define led_14 (1<<PINB2)
#define led_15 (1<<PINB3)
#define led_16 (1<<PINB4)

#define led_1Flag (1<<0)
#define led_2Flag  (1<<1)
#define led_3Flag  (1<<2)
#define led_4Flag  (1<<3)
#define led_5Flag  (1<<4)
#define led_6Flag  (1<<5)
#define led_7Flag  (1<<6)
#define led_8Flag  (1<<7)
#define led_9Flag  (1<<8)
#define led_10Flag  (1<<9)
#define led_11Flag  (1<<10)
#define led_12Flag  (1<<11)
#define led_13Flag  (1<<12)
#define led_14Flag  (1<<13)
#define led_15Flag  (1<<14)
#define led_16Flag  (1<<15)


void led_init(void);
void led_all_OFF(void);
void led_all_ON(void);
void led_set(ledFlag_t led_Flag);


#endif /* LED_H_ */