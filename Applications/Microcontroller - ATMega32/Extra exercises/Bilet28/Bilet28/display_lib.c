/*
 * display_lib.c
 *
 * Created: 10/17/2024 3:11:05 PM
 *  Author: andap
 */ 
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

void display(uint8_t p, uint8_t c)
{
	PORTA &= 0b11110000;				//liniile de sel. digit - oprite
	PORTC &= 0b00000000;				//liniile de sel. seg. - oprite
	
	switch(c)
	{
		case 0:
		PORTC |= 0b00111111; break;		//codificare cifra 0
		
		case 1:
		PORTC |= 0b00000110; break;		//codificare cifra 1
		
		case 2:
		PORTC |= 0b01011011; break;		//codificare cifra 2
		
		case 3:
		PORTC |= 0b01001111; break;		//codificare cifra 3
		
		case 4:
		PORTC |= 0b01100110; break;		//codificare cifra 4
		
		case 5:
		PORTC |= 0b01101101; break;		//codificare cifra 5
		
		case 6:
		PORTC |= 0b01111101; break;		//codificare cifra 6
		
		case 7:
		PORTC |= 0b00000111; break;		//codificare cifra 7
		
		case 8:
		PORTC |= 0b01111111; break;		//codificare cifra 8
		
		case 9:
		PORTC |= 0b01101111; break;		//codificare cifra 9
	}
	
	switch (p)
	{	
		case 1: PORTA |= 0b00000001; break;		//activare digit 1
		case 2: PORTA |= 0b00000010; break;		//activare digit 2
		case 3: PORTA |= 0b00000100; break;		//activare digit 3
		case 4: PORTA |= 0b00001000; break;		//activare digit 4
	}
	
	//_delay_ms(4);
}

void display_prot(uint8_t p, uint8_t c)
{
	PORTA &= 0b11110000;				//liniile de sel. digit - oprite
	PORTC &= 0b00000000;				//liniile de sel. seg. - oprite
	
	switch(c)
	{
		case 0:
		PORTC |= 0b00111111; break;		//codificare cifra 0
		
		case 1:
		PORTC |= 0b00000110; break;		//codificare cifra 1
		
		case 2:
		PORTC |= 0b01011011; break;		//codificare cifra 2
		
		case 3:
		PORTC |= 0b01001111; break;		//codificare cifra 3
		
		case 4:
		PORTC |= 0b01100110; break;		//codificare cifra 4
		
		case 5:
		PORTC |= 0b01101101; break;		//codificare cifra 5
		
		case 6:
		PORTC |= 0b01111101; break;		//codificare cifra 6
		
		case 7:
		PORTC |= 0b00000111; break;		//codificare cifra 7
		
		case 8:
		PORTC |= 0b01111111; break;		//codificare cifra 8
		
		case 9:
		PORTC |= 0b01101111; break;		//codificare cifra 9
	}
	
	switch (p)
	{
		case 4: PORTA |= 0b00000001; break;		//activare digit 4
		case 3: PORTA |= 0b00000010; break;		//activare digit 3
		case 2: PORTA |= 0b00000100; break;		//activare digit 2
		case 1: PORTA |= 0b00001000; break;		//activare digit 1
	}
	
	//_delay_ms(4);
}