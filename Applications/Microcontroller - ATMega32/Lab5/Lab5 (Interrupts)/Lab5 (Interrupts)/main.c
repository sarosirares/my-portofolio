/*
 * Lab5 (Interrupts).c
 *
 * Created: 10/31/2024 2:55:39 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "at32_timer.h"
#include "display_lib.h"

uint8_t m = 0;
uint8_t s = 0;
uint8_t digit = 0;
uint16_t ms = 0;
uint8_t start = 0;

ISR(TIMER2_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display(1,s%10); break;
		case 2: display(2,(s/10)%10); break;
		case 3: display(3,m%10); break;
		case 4: display(4,(m/10)%10); digit=0; break;
	}
	if (ms == 999){
		s++;
		ms = 0;
		if(s == 60){
			s = 0;
			m++;
		}
	}else ms++;
}



int main(void)
{
	DDRA = 0b00001111; //seteaz? pinii de ie?ire
	DDRC = 0b11111111;
	
	init_timer2();
	SREG |= (1<<7); //sei(); Set enable interrupt
	
    while (1) 
    {
    }
}

