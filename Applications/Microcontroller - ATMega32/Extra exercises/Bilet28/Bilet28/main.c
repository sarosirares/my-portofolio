/*
 * Bilet28.c
 *
 * Created: 12/18/2024 1:10:48 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "at32_timer.h"
#include "display_lib.h"
#include "at32_adc.h"

uint16_t ms = 0;
uint16_t ms2 = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

//e

uint8_t state_PB7 = 0;
uint8_t state_PB6 = 0;
uint8_t state_PB5 = 0;
uint8_t start = 0;

ISR(TIMER1_COMPA_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display_prot(1,(ms/10)%10); break;
		case 2: display_prot(2,(ms/100)%10); break;
		case 3: display_prot(3,(s%10)); PORTC |= 0b10000000; break;
		case 4: display_prot(4,(s/10)%10); digit=0; break;
	}
	
	ms2 += 2;
	
	if(start)
	{
		if (ms >= 999)
		{
			s++;
			ms = 0;
			if(s == 60)
			{
				s = 0;
				m++;
			}
		}
		else
			ms += 2;	
	}
	
	if(ms2 >= 2000)
	{
		PORTB |= (1<<0);
		if(ms2 >= 2500)
			ms2 = 500;
	}
	else
		PORTB &= ~(1<<0);
	
	
}


int main(void)
{
	//b
//  DDRD |= 1<<7; //PD7 – pin de iesire
// 	TCCR2 = 0b01111110; //FastPWM inversat, N=256
// 	OCR2 = 204;

	//c

 	DDRB |= (1<<0); //pin de iesire digitala PB0
// 	DDRB &= 0b00011111; //PB7, PB6, PB5 pini de intrare digitala
// 	
// 	PORTB |= 0b11100000; //activare PULL-UP

	//d
	
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_1_int();
	
	//e
	
	
    while (1) 
    {
		if(PINB & (1<<7))
		{
			if(state_PB7 == 0)
			{
				state_PB7 = 1;
				start = 1;
			}
		}
		else
		state_PB7 = 0;
		
		if(PINB & (1<<6))
		{
			if(state_PB6 == 0)
			{
				state_PB6 = 1;
				start = 0;
			}
		}
		else
		state_PB6 = 0;
		
		if(PINB & (1<<5))
		{
			if(state_PB5 == 0)
			{
				state_PB5 = 1;
				ms = 0;
				s = 0;
				m = 0;
			}
		}
		else
		state_PB5 = 0;
    }
}

