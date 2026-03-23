/*
 * at32_timer.c
 *
 * Created: 12/17/2024 3:18:42 PM
 *  Author: rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include "at32_timer.h"

void init_timer_0()
{
	//        76543210
	TCCR0 = 0b00000011; //prescaler 64, mod normal de operare
	TCNT0 = 0;			//se initializeaza numaratorul cu 0
}

void init_timer_2()
{
	//        76543210
	TCCR2 = 0b00000100;	//prescaler 64, mod normal de operare
	TCNT2 = 0;			//se initializeaza numaratorul cu 0
}

void init_timer_0_int()
{
	SREG = (1<<7);		//enable global interrupt
	//        76543210
	TCCR0 = 0b00001011; //prescaler 64, mod de operare - CTC
	TCNT0 = 0;			//se initializeaza numaratorul cu 0
	OCR0 = 125;			
	TIMSK |= 0b00000010; //Compare Match interrupt is enabled for TIMER0
}

void init_timer_2_int()
{
	SREG = (1<<7);		//enable global interrupt
	//        76543210
	TCCR2 = 0b00001011; //prescaler 32, mod de operare - CTC
	TCNT2 = 0;			//se initializeaza numaratorul cu 0
	OCR2 = 250;
	TIMSK |= 0b10000000; //Compare Match interrupt is enabled for TIMER2
}

void init_INT0()
{
	GICR |= (1<<6); // activarea întreruperii externe INT0
	MCUCR |= 0b00000011; // precizare c? evenimentul va avea loc pe frontul descresc?tor
	SREG |= (1<<7); // activarea globala a întreruperilor
}

void init_INT1()
{
	GICR |= (1<<7); // activarea întreruperii externe INT0
	MCUCR |= 0b00001100; // precizare c? evenimentul va avea loc pe frontul descresc?tor
	SREG |= (1<<7); // activarea globala a întreruperilor
}