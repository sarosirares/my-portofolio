/*
 * Bilet16.c
 *
 * Created: 12/18/2024 10:47:59 AM
 * Author : rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "at32_timer.h"
#include "display_lib.h"
#include "at32_adc.h"

uint16_t N = 0;
uint8_t digit = 0;
uint8_t state_PD1 = 0;
uint8_t direction = 1;
uint16_t value = 0;
float Vin = 0;
uint16_t adc = 0;
uint8_t mult = 0;

//c

// ISR(TIMER1_COMPA_vect)
// {
// 	N++;
// }

//d

// ISR(TIMER1_COMPA_vect)
// {
// 	if(N != 0)
// 	{
// 		if(direction == 1)
// 			N++;
// 		else
// 			N--;
// 	}
// 	else
// 		if(direction == 1)
// 			N++;
// }

ISR(TIMER1_COMPA_vect)
{
	if(N != 0)
	{
		if(direction == 1)
			N++;
		else
			N--;
	}
	else
		if(direction == 1)
			N++;
			
	adc = readADC(6);
	
	Vin = ((float)adc*5)/1024;
	Vin *= 1000;
	
	value = (uint16_t)Vin;
	
	if((N % 10) == 0)
		mult = 1;
	else
		mult = 0;
}




int main(void)
{
	//c
	
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	init_timer_1_int();

	//b
// 	
// 	TCCR0 = 0b01111001; //FastPWM inversat, N=1
// 	OCR0 = 51;			//DC = 80%
//     

	//d
	
	DDRD &= ~(1<<1);
	
	//e
	
	init_ADC();
	
    while (1) 
    {
		if(PIND & (1<<1))
		{
			if(state_PD1 == 0)
			{
				state_PD1 = 1;
				direction = 1 - direction;
			}
		}
		else
		state_PD1 = 0;
		
		digit++;
		if(mult == 1)
		{
			switch(digit)
			{
				case 1: display_prot(1,value%10); break;
				case 2: display_prot(2,(value/10)%10); break;
				case 3: display_prot(3,(value/100)%10); break;
				case 4: display_prot(4,(value/1000)%10); digit=0; break;
			}
		}
		else
		{
			switch(digit)
			{
				case 1: display_prot(1,N%10); break;
				case 2: display_prot(2,(N/10)%10); break;
				case 3: display_prot(3,(N/100)%10); break;
				case 4: display_prot(4,(N/1000)%10); digit=0; break;
			}
		}
			
    }
}

