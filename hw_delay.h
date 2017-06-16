/*
 * hw_delay.h
 *
 * Created: 11-10-2016 12:03:07
 *  Author: Karol
 */ 


#ifndef HW_DELAY_H_
#define HW_DELAY_H_

#define sleep_Idle 0
#define sleep_PowerDown 1
#define sleep_Standby 2

inline void hw_delay_init(void){
	//ustawienie licznika 0 na czêstotliwoœæ 1kHz
	// f = fclk/(preskaler*OCR0)
	TCCR0A |= (1<<WGM01);
	OCR0A = 0x3F; //przy F_CPU 1MHz -> 0x7D;
	TCCR0B |= (1<<CS01);	//preskaler 8
	TIMSK |= (1<<OCIE0A);
}

uint16_t getCurrentTime(void);

inline uint8_t getRawCurrentTime(void){
	return TCNT0;
}

void hw_delay_ms(uint16_t delay_time);

void hw_sleep_ms(uint16_t delay_time);

void hw_sleep(uint8_t sleep_mode);


#endif /* HW_DELAY_H_ */