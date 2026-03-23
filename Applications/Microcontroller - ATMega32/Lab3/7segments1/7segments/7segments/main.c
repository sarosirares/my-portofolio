/*
 * 7segments.c
 *
 * Created: 10/17/2024 2:20:55 PM
 * Author : andap
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "display_lib.h"
#include <stdlib.h>


int main(void)
{
	uint16_t cnt=0;
	uint8_t state=0;
	uint8_t stateD7=0;
	DDRD &=0b01111110;
	DDRA |=0b00001111;//PA0-PA3 output
	//DDRA |=(1<<3)|(1<<2)|(1<<1)|(1<<0); or like this
	DDRC|=0b11111111;//PC0-PC7 output
	//DDRC|=255; or like this
    while (1) 
    {
		/*
		PORTA &=~(1<<3);//disable digit 4
	
		//PORTC &=0b0000000;
		//PORTC|=0b00000000;  varianta buna
		PORTC =0b00000110;// display no 1
		PORTA |=(1<<0);//enable digit 1  //PORTA|=0b00000001;
		_delay_ms(4);
		PORTA &=~(1<<0);//disable digit 1
		
		PORTC =0b01011011;// display no 2
		PORTA |=(1<<1);//enable digit 2
		_delay_ms(4);
		PORTA &=~(1<<1);//disable digit 2
		
		PORTC =0b01001111;// display no 3
		PORTA |=(1<<2);//enable digit 3
		_delay_ms(4);
		PORTA &=~(1<<2);//disable digit 3
		
		PORTC =0b01100110;// display no 4
		PORTA |=(1<<3);//enable digit 4
		_delay_ms(4);
		*/
	
	if(PIND &(1<<0))
	{
		if(state==0)
		{
			if(PINA &(1<<5))
			cnt++;
			else
			cnt--;
			state=1;
		}
		
	}
	else
	state=0;
	
	if(PIND &(1<<7)) //reset cnt button
	{
		if(stateD7==0)
		{
			cnt=0;
			stateD7=1;
		}
		
	}
	else
	stateD7=0;
	display(1, cnt%10);
	display(2, cnt/10%10);
	display(3, cnt/100%10);
	display(4, cnt/1000%10);
   
	}
}

