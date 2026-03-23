/*
 * at32_timer.c
 *
 * Created: 10/24/2024 3:00:34 PM
 *  Author: rares
 */ 
#include "at32_timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void init_timer_0()
{
	TCCR0 = 0b00000011; // CTC-3,6, Prescaler-0,1,2
	TCNT0 = 0; 
}void init_timer_2(){
	TCCR2 = 0b00000100; // CTC-3,6, Prescaler-0,1,2
	TCNT2 = 0;
}
void init_timer_0_int()
{
	SREG = 1<<7;		 // Global Interrupt Enable
	TCCR0 = 0b00001011;	 //CTC-3,6; Prescaler-0,1,2
	TCNT0 = 0;			 
	OCR0 = 125;
	TIMSK |= 0b00000010; //set interrupt OCM
}

void init_timer2()
{
	SREG = 1<<7;		 // Global Interrupt Enable
	TCCR2 = 0b00001011;	 //CTC-3,6; Prescaler-0,1,2
	TCNT2 = 0;
	OCR2 = 254;
	TIMSK |= 0b10000000; //set interrupt OCM
}