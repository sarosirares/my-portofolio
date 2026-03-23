/*
 * Lab5 ADC.c
 *
 * Created: 12/17/2024 10:02:32 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "display_lib.h"
#include "at32_timer.h"
#include "at32_adc.h"

//EX1
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;
uint16_t value = 0;

ISR(TIMER0_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display(1,value%10); break;
		case 2: display(2,(value/10)%10); break;
		case 3: display(3,(value/100)%10); break;
		case 4: display(4,(value/1000)%10); digit=0; break;
	}
	if (ms == 999)
	{
		value = readADC(6);
		ms = 0;
	}
	else
		ms++;
}


int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0_int();
	init_ADC();
	
	while (1)
	{
	}
}
*/

//EX2
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;
uint16_t value = 0;

uint16_t adc_l, adc_h, adc, T;

float Vin, tmp;

ISR(TIMER0_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display(1,value%10); break;
		case 2: display(2,(value/10)%10); break;
		case 3: display(3,(value/100)%10); break;
		case 4: display(4,(value/1000)%10); digit=0; break;
	}
	if (ms == 999)
	{	
		readADC_int(7);
		ms = 0;
	}
	else
		ms++;
}

ISR(ADC_vect)
{
	adc_l = ADCL;
	adc_h = ADCH;
	adc = ((adc_h << 8) | adc_l);
	Vin = ((float)adc * 5) / 1024;
	tmp = Vin*1000/10;
	value = (uint16_t)(tmp);
}

int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0_int();
	init_ADC_int();
	
	while (1)
	{
	}
}
*/

//EX3
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;
uint16_t value = 0;

uint16_t adc_l, adc_h, adc, T;

float Vin, tmp;

ISR(TIMER0_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display(1,value%10); break;
		case 2: display(2,(value/10)%10); PORTC |= 0b10000000; break;
		case 3: display(3,(value/100)%10); break;
		case 4: display(4,(value/1000)%10); digit=0; break;
	}
	if (ms == 999)
	{	
		readADC_int(7);
		ms = 0;
	}
	else
		ms++;
}

ISR(ADC_vect)
{
	adc_l = ADCL;
	adc_h = ADCH;
	adc = ((adc_h << 8) | adc_l);
	Vin = ((float)adc * 5) / 1024;
	tmp = Vin*1000/10;
	value = (uint16_t)(tmp * 10);
}

int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0_int();
	init_ADC_int();
	
	while (1)
	{
	}
}
*/

//EX1-proteus
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;
uint16_t value = 0;

ISR(TIMER0_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display_prot(1,value%10); break;
		case 2: display_prot(2,(value/10)%10); break;
		case 3: display_prot(3,(value/100)%10); break;
		case 4: display_prot(4,(value/1000)%10); digit=0; break;
	}
	if (ms == 999)
	{
		value = readADC(6);
		ms = 0;
	}
	else
		ms++;
}


int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0_int();
	init_ADC();
	
	while (1)
	{
	}
}
*/

//EX2-proteus
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;
uint16_t value = 0;

uint16_t adc_l, adc_h, adc, T;

float Vin, tmp;

ISR(TIMER0_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display_prot(1,value%10); break;
		case 2: display_prot(2,(value/10)%10); break;
		case 3: display_prot(3,(value/100)%10); break;
		case 4: display_prot(4,(value/1000)%10); digit=0; break;
	}
	if (ms == 999)
	{	
		readADC_int(7);
		ms = 0;
	}
	else
		ms++;
}

ISR(ADC_vect)
{
	adc_l = ADCL;
	adc_h = ADCH;
	adc = ((adc_h << 8) | adc_l);
	Vin = ((float)adc * 5) / 1024;
	tmp = Vin*1000/10;
	value = (uint16_t)(tmp);
}

int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0_int();
	init_ADC_int();
	
	while (1)
	{
	}
}
*/

//EX3-proteus
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;
uint16_t value = 0;

uint16_t adc_l, adc_h, adc, T;

float Vin, tmp;

ISR(TIMER0_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display_prot(1,value%10); break;
		case 2: display_prot(2,(value/10)%10); PORTC |= 0b10000000; break;
		case 3: display_prot(3,(value/100)%10); break;
		case 4: display_prot(4,(value/1000)%10); digit=0; break;
	}
	if (ms == 999)
	{	
		readADC_int(7);
		ms = 0;
	}
	else
		ms++;
}

ISR(ADC_vect)
{
	adc_l = ADCL;
	adc_h = ADCH;
	adc = ((adc_h << 8) | adc_l);
	Vin = ((float)adc * 5) / 1024;
	tmp = Vin*1000/10;
	value = (uint16_t)(tmp * 10);
}

int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0_int();
	init_ADC_int();
	
	while (1)
	{
	}
}
*/