/*
 * Colocviu.c
 *
 * Created: 12/18/2024 5:24:46 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "display_lib.h"
#include "at32_timer.h"
#include "at32_adc.h"

float conversie(float gC);

uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;
uint16_t value = 0;
uint16_t valueF = 0;
uint8_t Celcius = 1;
uint8_t x = 50;
uint8_t k = 0;

uint8_t state_PD4 = 0;

uint16_t adc_l, adc_h, adc, T;

float Vin, tmp;

ISR(TIMER0_COMP_vect)
{
	digit++;
	if(Celcius)
	{
		switch(digit)
		{
			case 1: display_prot(1,'C'); break;
			case 2: display_prot(2,value%10); break;
			case 3: display_prot(3,(value/10)%10); PORTC |= (1<<7); break;
			case 4: display_prot(4,(value/100)%10); digit=0; break;
		}
	}
	else
	{
		switch(digit)
		{
			case 1: display_prot(1,'C'); break;
			case 2: display_prot(2,valueF%10); break;
			case 3: display_prot(3,(valueF/10)%10); PORTC |= (1<<7); break;
			case 4: display_prot(4,(valueF/100)%10); digit=0; break;
		}
	}
	if (ms == 10)
	{
		value = readADC(6);
		adc_l = ADCL;
		adc_h = ADCH;
		adc = ((adc_h << 8) | adc_l);
		Vin = ((float)adc * 5) / 1024;
		tmp = Vin*1000/10;
		value = (uint16_t)(tmp);
		valueF = conversie(value);
		ms = 0;
	}
	else
		ms++;
		
	if(value/10 >= 30)
		PORTD |= (1<<2);
	else
		PORTD &= ~(1<<2);
	if(valueF/10 >= 30)
		PORTD |= (1<<2);
	else
		PORTD &= ~(1<<2);
		
	if(value/10 <= 20)
		x--;
	if(x == 0)
		k++;
}


int main(void)
{
    //b
	
//	DDRD |= 1<<7;
// 	TCCR2 = 0b01101100; //FastPWM neinversat, N=64
// 	OCR2 = 127;

	//c
	
// 	DDRB |= 1<<3;
// 	TCCR0 = 0b01101011; //FastPWM neinversat, N=64
// 	OCR0 = 127;

	//d
	
 	DDRD |= (1<<2);		//iesire digitala
 	DDRD &= ~(1<<4);	//intrare digitala

	//e
	
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0_int();
	init_ADC();
	
	
    while (1) 
    {
		if(PIND & (1<<4))
		{
			if(state_PD4 == 0)
			{
				state_PD4 = 1;
				Celcius = 1 - Celcius;
			}
		}
		else
			state_PD4 = 0;
		
    }
}


float conversie(float gC)
{
	float F;
	F = (gC * (9/5)) + 32;
	return F;
}
