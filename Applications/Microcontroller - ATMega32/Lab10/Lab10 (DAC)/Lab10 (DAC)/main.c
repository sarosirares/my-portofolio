/*
 * Lab7PWM.c
 *
 * Created: 11/14/2024 3:08:55 PM
 * Author : draga
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "at32_timer.h"
#include "at32_adc.h"
#include "display_lib.h"

uint8_t sinus_2_10[] = {128, 226, 226, 151, 104, 128, 151, 104, 29, 29};
uint8_t sinus10[] = {128, 202, 249, 249, 202, 128, 53, 6, 6, 53};
uint8_t sinus100[] = {128, 136, 143, 151, 159, 167, 174, 182, 189, 196, 202, 209, 215, 220, 226, 231, 235, 239, 243, 246, 249, 251, 253, 254, 255, 255, 255, 254, 253, 251, 249, 246, 243, 239, 235, 231, 226, 220, 215, 209, 202, 196, 189, 182, 174, 167, 159, 151, 143, 136, 128, 119, 112, 104, 96, 88, 81, 73, 66, 59, 53, 46, 40, 35, 29, 24, 20, 16, 12, 9, 6, 4, 2, 1, 0, 0, 0, 1, 2, 4, 6, 9, 12, 16, 20, 24, 29, 35, 40, 46, 53, 59, 66, 73, 81, 88, 96, 104, 112, 119};
uint8_t digit = 0;
uint16_t value = 0;
uint16_t ms = 0;
uint16_t adc_value;
uint16_t tmp;
uint16_t Vin;
uint8_t i;

ISR(TIMER0_COMP_vect)
{
	digit++;
	switch(digit){
		case 1: display(1,value%10); break;
		case 2: display(2,(value/10)%10); break;
		case 3: display(3,(value/100)%10); break;
		case 4: display(4,(value/1000)%10); digit=0; break;
	}
	
	/*
	if (ms == 100){
		OCR2 = sinus10[i++];
		if (i == 10)
		i = 0;
		ms=0;
	} else ms++;
	*/
	/*
	if (ms == 9){
		OCR2 = sinus100[i++];
		if (i == 100)
		i = 0;
		ms=0;
	} else ms++;
	*/
	
	if (ms == 0){
		OCR2 = sinus_2_10[i++];
		if (i == 10)
		i = 0;
		ms=0;
	} else ms++;
}


int main(void)
{
    /* Replace with your application code */
	DDRA = 0b00001111; //seteza pinii de iesire
	DDRC = 0b11111111;
	init_timer_0_int();
	init_PWM2();
	SREG |= (1<<7);
    while (1)
	{
	}
}