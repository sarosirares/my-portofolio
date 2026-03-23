/*
 * Lab4 (Timers).c
 *
 * Created: 10/24/2024 2:55:19 PM
 * Author : rares
 */ 

#include "at32_timer.h"
#include "display_lib.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


int main(void)
{
	uint8_t m = 0;
	uint8_t s = 0;
	uint16_t ms = 0;
	uint8_t start = 1;
	uint8_t state_PD4 = 0;
	uint8_t state_PD5 = 0;
	
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	DDRD &= 0b11100111;
	
	
	//init_timer_0(); ex1
	init_timer_2();
	
    while (1)
    {
		
		for(;;)
		{
			if(TCNT2>=125) //se împlineste o milisecunda
			{ 
				//TCNT0 = 0; //resetare software ex1
				TCNT2 = 0; //resetare software ex2
				ms++;
				if(ms>=1000) //împlinirea unei secunde
				{ 
					ms=0;
					s++;
				}
				if(s==60){
					s=0;
					m++;
				}
			}
			
			display(1,s%10);
			display(2,(s/10)%10);
			display(3,(m%10));
			display(4,(m/10)%10);
		}
		/*
		for(;;)
		{
			if(start)
			{
				if(TCNT2>=125) //se împlineste o milisecunda
				{
					//TCNT0 = 0; //resetare software ex1
					TCNT2 = 0; //resetare software ex2
					ms++;
					if(ms>=1000) //împlinirea unei secunde
					{
						ms=0;
						s++;
					}
					if(s==60){
						s=0;
						m++;
					}
				}
			}
			
			if(PIND & (1<<4))
			{
				if(state_PD4 == 0)
				{
					state_PD4 = 1;
					start = !start;
				}
			}
			else
				state_PD4 = 0;
					
			if(PIND & (1<<5))
			{
				if(state_PD5 == 0)
				{
					state_PD5 = 1;
					s = 0;
					ms = 0;
				}
			}
			else
				state_PD5 = 0;		
			display(1,(ms%10)%10);
			display(2,(ms/100)%10);
			display(3,(s%10));
			display(4,(s/10)%10);
		}
    }
	*/
	}
}

