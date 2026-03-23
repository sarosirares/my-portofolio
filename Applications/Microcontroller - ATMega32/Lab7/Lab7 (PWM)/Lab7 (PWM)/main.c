/*
 * Lab7 (PWM).c
 *
 * Created: 11/14/2024 3:08:55 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "at32_adc.h"
#include "at32_timer.h"
#include "display_lib.h"

uint8_t m = 0;
uint8_t s = 0;
uint8_t digit = 0;
uint16_t ms = 0;
uint8_t start = 0;
uint16_t value = 0;

uint16_t adc_l, adc_h, adc, T, adc_value;
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
	if(ms == 99)
	{
		value = (readADC(6)/4);
		OCR2 = value;
		value = 255 - value;
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
   
    init_timer_0_int();
	Init_adc();
	init_PWM2();
    SREG |= (1<<7); //sei(); Set enable interrupt
    while(1) 
    {
    }
}


