/*
 * Lab2 7-Segment Display.c
 *
 * Created: 12/16/2024 10:24:07 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "display_lib.h"


//EX1

/*
int main(void)
{
    DDRA |= 0b00001111; //se seteaza pinii pentru digiti de iesire
	DDRC |= 0b11111111; //se seteaza pinii pentru segmente de iesire
	
    while (1) 
    {
		PORTC = 0b00000110; //afisarea cifrei 1
		PORTA = 0b00001000; //activarea digitului 1
		_delay_ms(4);
		PORTA &= ~(1<<3);	//dezactivare digit 1
		
		PORTC = 0b01011011; //afisarea cifrei 2
		PORTA = 0b00000100; //activarea digitului 2
		_delay_ms(4);
		PORTA &= ~(1<<2);	//dezactivare digit 2
		
		PORTC = 0b01001111; //afisarea cifrei 3
		PORTA = 0b00000010; //activarea digitului 3
		_delay_ms(4);
		PORTA &= ~(1<<1);	//dezactivare digit 3
		
		PORTC = 0b01100110; //afisarea cifrei 4
		PORTA = 0b00000001; //activarea digitului 4
		_delay_ms(4);
		PORTA &= ~(1<<0);	//dezactivare digit 4
    }
}
*/

//EX2

/*
uint16_t value = 445;

int main(void)
{
	DDRA |= 0b00001111; //se seteaza pinii pentru digiti de iesire
	DDRC |= 0b11111111; //se seteaza pinii pentru segmente de iesire
	
	while (1)
	{
		display(1,(value%10));
		display(2,(value/10)%10);
		display(3,(value/100)%10);
		display(4,(value/1000)%10);
	}
}
*/

//EX3

/*
uint16_t value = 0;
uint8_t state_PB7 = 0;

int main(void)
{
	DDRA |= 0b00001111; //se seteaza pinii pentru digiti de iesire
	DDRC |= 0b11111111; //se seteaza pinii pentru segmente de iesire
	
	DDRB &= ~(1<<7); //PB7 intrare
	
	while (1)
	{
		if(PINB & (1<<7))
		{
			if(state_PB7 == 0)
			{
				state_PB7 = 1;
				value++;
			}
		}
		else
			state_PB7 = 0;
		
		
		display(1,(value%10));
		display(2,(value/10)%10);
		display(3,(value/100)%10);
		display(4,(value/1000)%10);
	}
}
*/

//EX1 proteus

/*
int main(void)
{
	DDRA |= 0b00001111; //se seteaza pinii pentru digiti de iesire
	DDRC |= 0b11111111; //se seteaza pinii pentru segmente de iesire
	
	while (1)
	{
		PORTC = 0b01100110; //afisarea cifrei 4
		PORTA = 0b00001000; //activarea digitului 4
		_delay_ms(4);
		PORTA &= ~(1<<3);	//dezactivare digit 4
		
		PORTC = 0b01001111; //afisarea cifrei 3
		PORTA = 0b00000100; //activarea digitului 3
		_delay_ms(4);
		PORTA &= ~(1<<2);	//dezactivare digit 3
		
		PORTC = 0b01011011; //afisarea cifrei 2
		PORTA = 0b00000010; //activarea digitului 2
		_delay_ms(4);
		PORTA &= ~(1<<1);	//dezactivare digit 2
		
		PORTC = 0b00000110; //afisarea cifrei 1
		PORTA = 0b00000001; //activarea digitului 1
		_delay_ms(4);
		PORTA &= ~(1<<0);	//dezactivare digit 1
	}
}
*/

//EX2 proteus

/*
uint16_t value = 445;

int main(void)
{
	DDRA |= 0b00001111; //se seteaza pinii pentru digiti de iesire
	DDRC |= 0b11111111; //se seteaza pinii pentru segmente de iesire
	
	while (1)
	{
		display_prot(1,(value%10));
		display_prot(2,(value/10)%10);
		display_prot(3,(value/100)%10);
		display_prot(4,(value/1000)%10);
	}
}
*/

//EX3 proteus

/*
uint16_t value = 0;
uint8_t state_PB7 = 0;

int main(void)
{
	DDRA |= 0b00001111; //se seteaza pinii pentru digiti de iesire
	DDRC |= 0b11111111; //se seteaza pinii pentru segmente de iesire
	
	DDRB &= ~(1<<7); //PB7 intrare
	
	while (1)
	{
		if(PINB & (1<<7))
		{
			if(state_PB7 == 0)
			{
				state_PB7 = 1;
				value++;
			}
		}
		else
			state_PB7 = 0;
		
		
		display_prot(1,(value%10));
		display_prot(2,(value/10)%10);
		display_prot(3,(value/100)%10);
		display_prot(4,(value/1000)%10);
	}
}
*/