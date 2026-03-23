/*
 * Lab8.c
 *
 * Created: 11/21/2024 2:04:32 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "at32_adc.h"
#include "at32_timer.h"
#include "display_lib.h"

float interp(int R1, int R2, int T1, int T2, float Rntc);
float conversionC_F(float tmp);
float conversionF_C(float tmp);

uint8_t m = 0;
uint8_t s = 0;
uint8_t digit = 0;
uint16_t ms = 0;
uint16_t value = 0;
uint16_t adv;
uint8_t offset; 
uint8_t j;
uint8_t StatePB7 = 0;
uint8_t StatePB6 = 0;

uint8_t T[] = {15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
uint16_t R[] = {1520, 1228, 1000, 817, 673, 557, 463, 327, 323, 282, 230, 167, 143, 123, 106, 92, 80 };

float Vin, tmp, ref, Vcc = 5, Rntc, Rref = 1000; 

ISR(TIMER0_COMP_vect)
{
	digit++;
	if(StatePB6 == 0) //Celsius
	{
		switch(digit)
		{
			case 1: display(1,'C'); break;
			case 2: display(2,(value%10)); PORTD |= 0b10000000; break;
			case 3: display(3,(value/10)%10); break;
			case 4: display(4,(value/100)%10); digit=0; break;
		}
	}
	else
	{
		switch(digit)
		{
			case 1: display(1,'F'); break;
			case 2: display(2,(value%10)); PORTD &= ~(1<<7); break;
			case 3: display(3,(value/10)%10); break;
			case 4: display(4,(value/100)%10); digit=0; break;
		}
	}
	if (ms==99){
		//cite?te senzor temperatura si converte?te in grade Celsius
		adv = readADC(7);
		Vin = ((float)adv*5)/1024;
		Rntc = Rref / (Vcc/Vin -1);

		for(j = 0; j <= 17; j++)
		if(R[j] < Rntc)
		break;
		tmp = interp(R[j-1], R[j], T[j-1], T[j], Rntc);
		tmp = (int16_t)(tmp*10);
		//referin?a - cite?te poten?iometrul si converte?te valoarea in
		//grade Celsius
		adv = readADC(6);
		ref = 20 + adv / 12.78; //domeniul [20;100]
		ref = (int)(ref * 10);

		offset = 60;
		if(tmp < (ref - offset / 2))
		PORTD |= 1<<4; //comand? ON
		if(tmp > (ref + offset / 2))
		PORTD &= ~(1<<4); //comand? OFF
		//in func?ie de starea butonului, pe display se afi?eaz?
		//temperatura curenta sau referin?a
		if(PINB & (1<<7))
		{
			if(StatePB7 == 0)
			{
				StatePB7 = 1;
			}
			else
			{
				StatePB7 = 0;
			}
		}
		else
		{
			if(StatePB7 == 0)
				value = tmp;
			else
				value = ref;
		}
		
		if(PINB & (1<<6))
		{
			if(StatePB6 == 0) //Celsius
			{
				StatePB6 = 1;
			}
			else
			{
				StatePB6 = 0;
			}
		}
		else
		{
			if(StatePB6 == 0) //celsius
				tmp = conversionF_C(tmp);
			else			  //F
				tmp = conversionC_F(tmp);
		}
		ms = 0;
	}else ms++;
}

ISR(ADC_vect)
{
	uint16_t adc_value = 0;
	float tmp, Vin;
	uint16_t adc_l = ADCL;
	uint16_t adc_h = ADCH;
	adc_value = ((adc_h << 8) | adc_l);
	Vin = ((float)adc_value * 5)/1024;
	tmp = Vin * 1000 / 10;
	value = (int16_t)(tmp * 10);
}


int main(void)
{
	DDRA = 0b00001111; //seteaza pinii de iesire
	DDRC = 0b11111111;
	DDRD |= 1<<4;
	init_timer_0_int();
	Init_adc();
	SREG |= (1<<7); //sei(); Set enable interrupt
	while(1)
	{
	}
}


float interp(int16_t R1, int16_t R2, int16_t T1, int16_t T2, float Rntc)
{
	return (T1 + (Rntc - R2)*((float)(T2 - T1)/(R2 - R1)));
}

float conversionC_F(float tmp)
{
	return ((tmp * 1.8) + 32);
}

float conversionF_C(float tmp)
{
	return (float)(tmp - 32)/1.8;
}