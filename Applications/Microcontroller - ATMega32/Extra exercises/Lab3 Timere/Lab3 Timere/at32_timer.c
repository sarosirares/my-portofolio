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