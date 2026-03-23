/*
 * Bilet7.c
 *
 * Created: 12/18/2024 7:48:18 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "at32_adc.h"
#include "display_lib.h"
#include "at32_timer.h"

uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

uint8_t numarator = 255;

ISR(TIMER2_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display_prot(1,numarator%10); break;
		case 2: display_prot(2,(numarator/10)%10); break;
		case 3: display_prot(3,(numarator/100)%10); break;
		case 4: display_prot(4,(numarator/1000)%10); digit=0; break;
	}
	
	if(numarator != 0)
	{
		if(ms == 499)
		{
			ms = 0;
			numarator--;
		}
		else
		ms++;
	}
		
}

ISR(INT0_vect)
{
	numarator++;
}

ISR(INT1_vect)
{
	numarator = (readADC(6)/4);
}


int main(void)
{
	
	//b
	
	DDRB |= 1<<3; //PB3 – pin de iesire

	TCCR0 = 0b01101100; //FastPWM inversat, N=256
	OCR0 = 102;	
	
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_ADC();
	init_INT0();
	init_INT1();
	init_timer_2_int();
	
	
    while (1) 
    {
		
    }
}

