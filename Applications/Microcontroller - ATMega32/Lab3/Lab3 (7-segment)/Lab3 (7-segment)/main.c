/*
 * Lab3 (7-segment).c
 *
 * Created: 10/17/2024 2:19:22 PM
 * Author : rares
 */ 

#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>


int main(void)
{
	DDRA |= 0b00001111; //PA0-PA3 - OUTPUT
	//DDRA |= (1<<3)|(1<<2)|(1<<1)|(1<<0);
	DDRC |= 0b11111111; //PC0-PC7 - OUTPUT
	//DDRC |= 255;
    while (1) 
    {
		PORTA &= ~(1<<3); // Disable Digit 4
		PORTC &= 0b00000000; // disable display number
		PORTC |= 0b00000110; // display number 1
		//PORTA |= 0b00000001;
		PORTA |= (1<<0); // Enable Digit 1
		_delay_ms(4);
		
		PORTA &= ~(1<<0); // Disable Digit 1
		PORTC &= 0b00000000; // disable display number
		PORTC |= 0b01011011; // display number 2
		PORTA |= (1<<1); // Enable Digit 2
		_delay_ms(4);
		
		PORTA &= ~(1<<1); // Disable Digit 2
		PORTC &= 0b00000000; // disable display number
		PORTC |= 0b01001111; // display number 3
		PORTA |= (1<<2); // Enable Digit 3
		_delay_ms(4);
		
		PORTA &= ~(1<<2); // Disable Digit 3
		PORTC &= 0b00000000; // disable display number
		PORTC |= 0b01100110; // display number 4
		PORTA |= (1<<3); // Enable Digit 4
		_delay_ms(4);
    }
}

//display number 0: PORTC |= 0b00111111;
//display number 5: PORTC |= 0b01101101;
//display number 6: PORTC |= 0b01111101;
//display number 7: PORTC |= 0b00000111;
//display number 8: PORTC |= 0b01111111;
//display number 9: PORTC |= 0b01101111;


/*
	switch (p)
	{
		case 0: PORTA |= 0b00000001; break;
		case 1: PORTA |= 0b00000010; break;
		case 2: PORTA |= 0b00000100; break;
		case 3: PORTA |= 0b00001000; break;
	}
*/

000100000