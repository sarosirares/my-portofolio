/*
 * display_lib.c
 *
 * Created: 10/17/2024 3:11:05 PM
 *  Author: andap
 */
/*
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

void display(uint16_t p, uint16_t c)
{
	PORTA &=0b11110000;
	PORTC &= 0b00000000;
	
	switch(c)
	{
		case 0:
		PORTC |= 0b00111111; break;
		
		case 1:
		PORTC |= 0b00000110; break;
		
		case 2:
		PORTC |= 0b01011011; break;
		
		case 3:
		PORTC |= 0b01001111; break;
		
		case 4:
		PORTC |= 0b01100110; break;
		
		case 5:
		PORTC |= 0b01101101; break;
		
		case 6:
		PORTC |= 0b01111101; break;
		
		case 7:
		PORTC |= 0b00000111; break;
		
		case 8:
		PORTC |= 0b01111111; break;
		
		case 9:
		PORTC |= 0b01101111; break;
	}
	
	switch (p)
	{
		case 1: PORTA |= 0b00000001; break;
		//case 2: PORTA |= 0b00000010;
		case 2: PORTA |= 0b00000010; PORTC |= 0b10000000; break; //Ex with the temperature
		case 3: PORTA |= 0b00000100; break;
		case 4: PORTA |= 0b00001000; break;
	}
	
	//_delay_ms(4);
}*/

/*
 * display_lib.c
 *
 * Created: 10/17/2024 3:11:05 PM
 *  Author: andap
 */ 

//Ex2

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

void display(uint16_t p, uint16_t c)
{
	PORTA &=0b11110000;
	PORTC &= 0b00000000;
	
	switch(c)
	{
		case 0:
		PORTC |= 0b00111111; break;
		
		case 1:
		PORTC |= 0b00000110; break;
		
		case 2:
		PORTC |= 0b01011011; break;
		
		case 3:
		PORTC |= 0b01001111; break;
		
		case 4:
		PORTC |= 0b01100110; break;
		
		case 5:
		PORTC |= 0b01101101; break;
		
		case 6:
		PORTC |= 0b01111101; break;
		
		case 7:
		PORTC |= 0b00000111; break;
		
		case 8:
		PORTC |= 0b01111111; break;
		
		case 9:
		PORTC |= 0b01101111; break;
		
		case 'F':
		PORTC |= 0b01110001; break;
		
		case 'C':
		PORTC |= 0b00111001; break;
	}
	
	switch (p)
	{
		case 1: PORTA |= 0b00000001; break;
		case 2: PORTA |= 0b00000010; break;
		case 3: PORTA |= 0b00000100; break;
		case 4: PORTA |= 0b00001000; break;
	}
	
	//_delay_ms(4);
}

