/*
 * Lab6 PWM.c
 *
 * Created: 12/18/2024 12:01:43 AM
 * Author : rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "display_lib.h"
#include "at32_timer.h"
#include "at32_adc.h"

//EX1

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
	if (ms == 99)
	{
		value = (readADC(6));
		OCR2 = value/4;
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
	init_PWM2();
	init_ADC();

	while (1)
	{
	}
}

//EX2

// uint16_t ms = 0;
// uint8_t s = 0;
// uint8_t m = 0;
// uint8_t digit = 0;
// uint16_t value = 0;
// 
// ISR(TIMER0_COMP_vect)
// {
// 	digit++;
// 	switch(digit)
// 	{
// 		case 1: display(1,value%10); break;
// 		case 2: display(2,(value/10)%10); break;
// 		case 3: display(3,(value/100)%10); break;
// 		case 4: display(4,(value/1000)%10); digit=0; break;
// 	}
// 	if (ms == 99)
// 	{
// 		value = (readADC(6));
// 		OCR2 = value/4;
// 		ms = 0;
// 	}
// 	else
// 		ms++;
// }
// 
// 
// int main(void)
// {
// 	DDRA = 0b00001111;
// 	DDRC = 0b11111111;
// 
// 	init_timer_0_int();
// 	init_PWM2();
// 	init_ADC();
// 
// 	while (1)
// 	{
// 	}
// }

//EX3

// uint16_t ms = 0;
// uint8_t s = 0;
// uint8_t m = 0;
// uint8_t digit = 0;
// uint16_t value = 0;
// 
// uint16_t ADCMax=1023, fMax=20000, fMin=20, freq, icr, TOP, value;
// 
// ISR(TIMER0_COMP_vect)
// {
// 	digit++;
// 	switch(digit)
// 	{
// 		case 1: display(1,value%10); break;
// 		case 2: display(2,(value/10)%10); break;
// 		case 3: display(3,(value/100)%10); break;
// 		case 4: display(4,(value/1000)%10); digit=0; break;
// 	}
// 	if (ms == 9){
// 		adv = (adc(6));
// 		freq = ((float)(fMax-fMin))/ADCmax*adv+fMin;
// 		TOP = 1000000/freq-1;
// 		ICR1H = TOP>>8;
// 		ICR1L = TOP;
// 		OCR1BH = ((TOP+1)/2)>>8;
// 		OCR1BL = (TOP+1)/2;
// 		value=freq/10;
// 		ms=0;
// 	}
// 	else 
// 		ms++;
// }
// 
// 
// int main(void)
// {
// 	DDRA = 0b00001111;
// 	DDRC = 0b11111111;
// 
// 	init_timer_0_int();
// 	init_PWM2();
// 	init_ADC();
// 
// 	while (1)
// 	{
// 	}
// }

//EX1-proteus

// uint16_t ms = 0;
// uint8_t s = 0;
// uint8_t m = 0;
// uint8_t digit = 0;
// uint16_t value = 0;
// 
// ISR(TIMER0_COMP_vect)
// {
// 	digit++;
// 	switch(digit)
// 	{
// 		case 1: display_prot(1,value%10); break;
// 		case 2: display_prot(2,(value/10)%10); break;
// 		case 3: display_prot(3,(value/100)%10); break;
// 		case 4: display_prot(4,(value/1000)%10); digit=0; break;
// 	}
// 	if (ms == 99)
// 	{
// 		value = (readADC(6));
// 		OCR2 = value/4;
// 		ms = 0;
// 	}
// 	else
// 		ms++;
// }
// 
// 
// int main(void)
// {
// 	DDRA = 0b00001111;
// 	DDRC = 0b11111111;
// 	
// 	init_timer_0_int();
// 	init_PWM2();
// 	init_ADC();
// 	
// 	while (1)
// 	{
// 	}
//}

//EX2-proteus

// uint16_t ms = 0;
// uint8_t s = 0;
// uint8_t m = 0;
// uint8_t digit = 0;
// uint16_t value = 0;
// 
// ISR(TIMER0_COMP_vect)
// {
// 	digit++;
// 	switch(digit)
// 	{
// 		case 1: display_prot(1,value%10); break;
// 		case 2: display_prot(2,(value/10)%10); break;
// 		case 3: display_prot(3,(value/100)%10); break;
// 		case 4: display_prot(4,(value/1000)%10); digit=0; break;
// 	}
// 	if (ms == 99)
// 	{
// 		value = (readADC(6));
// 		OCR2 = value/4;
// 		ms = 0;
// 	}
// 	else
// 		ms++;
// }
// 
// 
// int main(void)
// {
// 	DDRA = 0b00001111;
// 	DDRC = 0b11111111;
// 
// 	init_timer_0_int();
// 	init_PWM2();
// 	init_ADC();
// 
// 	while (1)
// 	{
// 	}
// }


// float conversie(float gC);
// 
// uint16_t ms = 0;
// uint8_t s = 0;
// uint8_t m = 0;
// uint8_t digit = 0;
// uint16_t value = 0;
// uint16_t valueF = 0;
// /*uint8_t Celcius = 1;*/


// uint16_t adc_l, adc_h, adc, T;
// float Vin, tmp;

// ISR(TIMER0_COMP_vect)
// {
// 	digit++;
// 	if(Celcius)
// 	{
// 		switch(digit)
// 		{
// 			case 1: display_prot(1,'C'); break;
// 			case 2: display_prot(2,value%10); break;
// 			case 3: display_prot(3,(value/10)%10); PORTC |= (1<<7); break;
// 			case 4: display_prot(4,(value/100)%10); digit=0; break;
// 		}
// 	}
// 	else
// 	{
// 		switch(digit)
// 		{
// 			case 1: display_prot(1,'C'); break;
// 			case 2: display_prot(2,valueF%10); break;
// 			case 3: display_prot(3,(valueF/10)%10); PORTC |= (1<<7); break;
// 			case 4: display_prot(4,(valueF/100)%10); digit=0; break;
// 		}
// 	}
// 	if (ms == 10)
// 	{
// 		value = readADC(6);
// 		adc_l = ADCL;
// 		adc_h = ADCH;
// 		adc = ((adc_h << 8) | adc_l);
// 		Vin = ((float)adc * 5) / 1024;
// 		tmp = Vin*1000/10;
// 		value = (uint16_t)(tmp);
// 		valueF = conversie(value);
// 		ms = 0;
// 	}
// 	else
// 	ms++;
// }