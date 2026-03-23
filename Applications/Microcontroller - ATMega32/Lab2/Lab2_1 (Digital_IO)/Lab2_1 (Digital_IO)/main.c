/*
 * Lab2_1 (Digital_IO).c
 *
 * Created: 10/10/2024 2:44:37 PM
 * Author : rares
 */

#include <avr/io.h>
#include <stdlib.h>

int main(void)
{
    DDRA |= 0b11111111;
	//DDRA |= (1<<6); //PA6 -> OUT
	DDRB &= ~(1<<7); //PB7 -> IN
	DDRD |= 0b11111111; //PDall -> OUT
	uint8_t statePB7 = 0;
	uint8_t contor = 0;
    while (1)
    {
		//FIRST EX//
		/*
		if(PINB & (1<<7)) //Button pressed
		{
			PORTD |= (1<<6);
			//PORTA |= 0b11111111; //LED ON
		}
		else
		{
			PORTD &= ~(1<<6);
			//PORTA &= 0b00000000; //LED OFF
		}
		*/

		//SECOND EXERCISE

		/*
		if(PINB & (1<<7))
		{
			if(statePB7 == 0)
			{

				PORTD ^= 1<<6;
				statePB7 = 1;
			}
		}
		else
			statePB7 = 0;
		*/
		if(PINB & (1<<7))
		{
			if(statePB7 == 0)
			{

				statePB7 = 1;
				contor++;
			}
			
		}
		else
		statePB7 = 0;

		PORTD = contor;

		if(contor == 256)
			contor = 0;

    }
}

