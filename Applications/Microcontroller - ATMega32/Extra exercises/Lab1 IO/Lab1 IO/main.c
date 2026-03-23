/*
 * Lab1 IO.c
 *
 * Created: 12/16/2024 8:46:31 PM
 * Author : rares
 */ 

#include <avr/io.h>			//provides definitions for all the input/output registers and bit names
#include <stdlib.h>			//

//Ex1

/*
int main(void)
{
    DDRB |= (1<<7);			//setare PB7 iesire
	DDRB &= ~(1<<3);		//setare PB3 intrare
	
    while (1) 
    {
		if(PINB & (1<<3))	//testare PB3
			PORTB |= (1<<7);//LED on
		else
			PORTB &= ~(1<<7);//LED off
    }
}
*/

//Ex2

/*
int main(void)
{
	DDRB |= (1<<6);					//setare PB6 iesire
	DDRB &= ~(1<<2);				//setare PB2 intrare
	uint8_t state_PB2 = 0;			//variabila de stare (tine minte starea anterioara a pinului)
	
	while (1)
	{
		if(PINB & (1<<2))			//testare PB2
		{
			if(state_PB2 == 0)		//daca starea anterioara a pinului a fost 0
			{
				state_PB2 = 1;		
				PORTB ^= (1<<6);	//toggle
			}
		}
		else
			state_PB2 = 0;
	}
}
*/

//Ex3
/*
int main(void)
{
	DDRD |= 0b11111111;				//setare PDall iesire
	DDRB &= ~(1<<2);				//setare PB2 intrare
	uint8_t state_PB2 = 0;			//variabila de stare (tine minte starea anterioara a pinului)
	uint8_t contor = 0;
	
	while (1)
	{
		if(PINB & (1<<2))			//testare PB2
		{
			if(state_PB2 == 0)		//daca starea anterioara a pinului a fost 0
			{
				state_PB2 = 1;
				contor++;
			}
		}
		else
			state_PB2 = 0;
			
		PORTD = contor;
		
		if(contor == 256)
			contor = 0;
	}
}
*/