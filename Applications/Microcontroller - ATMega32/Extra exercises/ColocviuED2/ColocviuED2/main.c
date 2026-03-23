/*
 * ColocviuED2.c
 *
 * Created: 12/18/2024 6:20:37 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "at32_timer.h"
#include "at32_adc.h"
#include "display_lib.h"

uint16_t value = 0;
uint8_t state_PD6 = 0;
uint8_t state_PD7 = 0;
uint16_t adc = 0;

ISR(TIMER0_COMP_vect)
{
	if(PIND & (1<<7))
	{
		if(state_PD7 == 0)
		{
			state_PD7 = 1;
			value++;
		}
	}
	else
	state_PD7 = 0;
	
	if(PIND & (1<<6))
	{
		if(state_PD6 == 0)
		{
			state_PD6 = 1;
			value--;
		}
	}
	else
		state_PD7 = 0;
		
	adc = readADC(6);
		
	if(value % 10 == 0)
	{
		OCR2 = adc/4;
	}
}

int main(void)
{
    //b
	
// 	DDRD |= (1<<4);
// 	DDRD &= ~(1<<6);
	
	//c
	
	DDRD |= 1<<7; //PD7 – pin de iesire
	//        76543210
	TCCR2 = 0b01111010; //FastPWM inversat, N=256
	OCR2 = 204;
	
	//d
	
	DDRD &= ~(1<<6);
	DDRD &= ~(1<<7);
	
	init_ADC();
	
    while (1) 
    {	
    }
}

