/*
 * Lab4 Intreruperi.c
 *
 * Created: 12/17/2024 5:57:15 PM
 * Author : rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "at32_timer.h"
#include "display_lib.h"

//EX1
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

ISR(TIMER0_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display(1,s%10); break;
		case 2: display(2,(s/10)%10); break;
		case 3: display(3,m%10); break;
		case 4: display(4,(m/10)%10); digit=0; break;
	}
	if (ms == 999)
	{
		s++;
		ms = 0;
		if(s == 60)
		{
			s = 0;
			m++;
		}
	}
	else
	ms++;
}


int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0_int();
	
    while (1) 
    {
    }
}
*/

//EX2
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

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
	if (ms == 999)
	{
		s++;
		ms = 0;
		if(s == 60)
		{
			s = 0;
			m++;
		}
	}
	else
	ms++;
}


int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_2_int();
	
	while (1)
	{
	}
}
*/

//EX3
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

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
	if (ms == 999)
	{
		s++;
		ms = 0;
		if(s == 60)
		{
			s = 0;
			m++;
		}
	}
	else
	ms++;
}

ISR(INT0_vect)
{
	ms = 0;
	s = 0;
	m = 0;
}

int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_2_int();
	init_INT0();
	
	while (1)
	{
	}
}
*/


//EX4
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

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
	if (ms == 999)
	{
		s++;
		ms = 0;
		if(s == 60)
		{
			s = 0;
			m++;
		}
	}
	else
	ms++;
}

ISR(INT0_vect)
{
	m++;
}

ISR(INT1_vect)
{
	s++;
}

int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_2_int();
	init_INT0();
	init_INT1();
	
	while (1)
	{
	}
}
*/

//EX1-proteus
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

ISR(TIMER0_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display_prot(1,s%10); break;
		case 2: display_prot(2,(s/10)%10); break;
		case 3: display_prot(3,m%10); break;
		case 4: display_prot(4,(m/10)%10); digit=0; break;
	}
	if (ms == 999)
	{
		s++;
		ms = 0;
		if(s == 60)
		{
			s = 0;
			m++;
		}
	}
	else
	ms++;
}


int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_0_int();
	
    while (1) 
    {
    }
}
*/

//EX2-proteus
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

ISR(TIMER2_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display_prot(1,s%10); break;
		case 2: display_prot(2,(s/10)%10); break;
		case 3: display_prot(3,m%10); break;
		case 4: display_prot(4,(m/10)%10); digit=0; break;
	}
	if (ms == 999)
	{
		s++;
		ms = 0;
		if(s == 60)
		{
			s = 0;
			m++;
		}
	}
	else
	ms++;
}


int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_2_int();
	
	while (1)
	{
	}
}
*/

//EX3-proteus
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

ISR(TIMER2_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display_prot(1,s%10); break;
		case 2: display_prot(2,(s/10)%10); break;
		case 3: display_prot(3,m%10); break;
		case 4: display_prot(4,(m/10)%10); digit=0; break;
	}
	if (ms == 999)
	{
		s++;
		ms = 0;
		if(s == 60)
		{
			s = 0;
			m++;
		}
	}
	else
	ms++;
}

ISR(INT0_vect)
{
	ms = 0;
	s = 0;
	m = 0;
}

int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;
	
	init_timer_2_int();
	init_INT0();
	
	while (1)
	{
	}
}
*/

//EX4-proteus
/*
uint16_t ms = 0;
uint8_t s = 0;
uint8_t m = 0;
uint8_t digit = 0;

ISR(TIMER2_COMP_vect)
{
	digit++;
	switch(digit)
	{
		case 1: display_prot(1,s%10); break;
		case 2: display_prot(2,(s/10)%10); break;
		case 3: display_prot(3,m%10); break;
		case 4: display_prot(4,(m/10)%10); digit=0; break;
	}
	if (ms == 999)
	{
		s++;
		ms = 0;
		if(s == 60)
		{
			s = 0;
			m++;
		}
	}
	else
	ms++;
}

ISR(INT0_vect)
{
	m++;
}

ISR(INT1_vect)
{
	s++;
}

int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b11111111;

	init_INT0();
	init_INT1();

	init_timer_2_int();

	while (1)
	{
	}
}
*/