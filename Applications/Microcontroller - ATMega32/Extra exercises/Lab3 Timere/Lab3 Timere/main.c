/*
 * Lab3 Timere.c
 *
 * Created: 12/17/2024 3:01:14 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "display_lib.h"
#include "at32_timer.h"

//EX1

/*
int main(void)
{
    uint16_t ms = 0;
	uint8_t s = 0;
	uint8_t m = 0;
	
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0();
	
    while (1) 
    {
		if(TCNT0 >= 125)
		{
			TCNT0 = 0;
			ms++;
			if(ms >= 1000)
			{
				ms = 0;
				s++;
			}
			if(s == 60)
			{
				s = 0;
				m++;
			}
		}
		
		display(1,s%10);
		display(2,(s/10)%10);
		display(3,(m%10));
		display(4,(m/10)%10);
    }
}
*/

//EX2
/*
int main(void)
{
	uint16_t ms = 0;
	uint8_t s = 0;
	uint8_t m = 0;
	
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_2();
	
	while (1)
	{
		if(TCNT2 >= 125)
		{
			TCNT2 = 0;
			ms++;
			if(ms >= 1000)
			{
				ms = 0;
				s++;
			}
			if(s == 60)
			{
				s = 0;
				m++;
			}
		}
		
		display(1,s%10);
		display(2,(s/10)%10);
		display(3,(m%10));
		display(4,(m/10)%10);
	}
}
*/


//EX3
/*
int main(void)
{
	uint16_t ms = 0;
	uint8_t s = 0;
	uint8_t m = 0;
	uint8_t start = 0;
	uint8_t state_PB0 = 0;
	uint8_t state_PB1 = 0;
	
	DDRA = 0b00001111;		//se seteaza pinii pentru digiti de iesire
	DDRC = 0b11111111;		//se seteaza pinii pentru segmente de iesire
	DDRB &= 0b11111100;		//se seteaza pinii de intrare PB1 PB0
	
	init_timer_2();			//initializare timer 2
	
	while (1)
	{
		if(start)						//daca butonul de start a fost apasat
		{
			if(TCNT2 >= 125)			//cand se implineste o milisecunda
			{
				TCNT2 = 0;				//resetare la 0
				ms++;
				if(ms >= 1000)			//cand se implineste o secunda
				{
					ms = 0;				
					s++;
				}
				if(s == 60)				//cand se implineste un minut
				{
					s = 0;
					m++;
				}
			}
		}
		
		if(PINB & (1<<1))				
		{
			if(state_PB1 == 0)
			{
				state_PB1 = 1;
				start = 1 - start;
			}
		}
		else
			state_PB1 = 0;
			
		if(PINB & (1<<0))
		{
			if(state_PB0 == 0)
			{
				state_PB0 = 1;
				ms = 0;
				s = 0;
			}
		}
		else
			state_PB0 = 0;
		
		display(1,(ms/10)%10);
		display(2,(ms/100)%10);
		display(3,(s%10));
		display(4,(s/10)%10);
	}
}
*/

//EX1-proteus

/*
int main(void)
{
    uint16_t ms = 0;
	uint8_t s = 0;
	uint8_t m = 0;
	
	DDRA = 0b00001111;	//se seteaza pinii pentru digiti de iesire
	DDRC = 0b11111111;	//se seteaza pinii pentru segmente de iesire
	
	init_timer_0();
	
    while (1) 
    {
		if(TCNT0 >= 125)
		{
			TCNT0 = 0;
			ms++;
			if(ms >= 1000)
			{
				ms = 0;
				s++;
			}
			if(s == 60)
			{
				s = 0;
				m++;
			}
		}
		
		display_prot(1,s%10);
		display_prot(2,(s/10)%10);
		display_prot(3,(m%10));
		display_prot(4,(m/10)%10);
    }
}
*/

//EX2-proteus
/*
int main(void)
{
	uint16_t ms = 0;
	uint8_t s = 0;
	uint8_t m = 0;
	
	DDRA = 0b00001111;	//se seteaza pinii pentru digiti de iesire
	DDRC = 0b11111111;	//se seteaza pinii pentru segmente de iesire
	
	init_timer_2();
	
	while (1)
	{
		if(TCNT2 >= 125)	//cand se implineste o milisecunda
		{
			TCNT2 = 0;		//resetare la 0
			ms++;
			if(ms >= 1000)	//cand se implineste o secunda
			{
				ms = 0;
				s++;
			}
			if(s == 60)		//cand se implineste un minut
			{
				s = 0;
				m++;
			}
		}
		
		display_prot(1,s%10);
		display_prot(2,(s/10)%10);
		display_prot(3,(m%10));
		display_prot(4,(m/10)%10);
	}
}
*/

//EX3-proteus
/*
int main(void)
{
	uint16_t ms = 0;
	uint8_t s = 0;
	uint8_t m = 0;
	uint8_t start = 0;
	uint8_t state_PB0 = 0;
	uint8_t state_PB1 = 0;
	
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	DDRB &= 0b11111100;
	
	init_timer_2();
	
	while (1)
	{
		if(start)
		{
			if(TCNT2 >= 125)
			{
				TCNT2 = 0;
				ms++;
				if(ms >= 1000)
				{
					ms = 0;
					s++;
				}
				if(s == 60)
				{
					s = 0;
					m++;
				}
			}
		}
		
		if(PINB & (1<<1))
		{
			if(state_PB1 == 0)
			{
				state_PB1 = 1;
				start = 1 - start;
			}
		}
		else
		state_PB1 = 0;
		
		if(PINB & (1<<0))
		{
			if(state_PB0 == 0)
			{
				state_PB0 = 1;
				ms = 0;
				s = 0;
			}
		}
		else
		state_PB0 = 0;
		
		display_prot(1,(ms/10)%10);
		display_prot(2,(ms/100)%10);
		display_prot(3,(s%10));
		display_prot(4,(s/10)%10);
	}
}
*/