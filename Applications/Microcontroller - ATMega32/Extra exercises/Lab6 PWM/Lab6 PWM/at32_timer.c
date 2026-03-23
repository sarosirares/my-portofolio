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

void init_timer_1_int()
{
	SREG = (1<<7);		//enable global interrupt
	//         76543210
	TCCR1A = 0b00000000; //prescaler 64, mod de operare - CTC
	TCCR1B = 0b00001011;
	TCNT1 = 0;			//se initializeaza numaratorul cu 0
	OCR1AH = 250 >> 8;
	OCR1AL = 250 & 255;
	//         76543210
	TIMSK |= 0b00010000; //Compare Match interrupt is enabled for TIMER1A
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

void init_PWM0()
{
	DDRB |= 1<<3; //PB3 – pin de iesire
	//        76543210
	TCCR0 = 0b01111001; //FastPWM inversat, N=1
}

void init_PWM2()
{
	DDRD |= 1<<7; //PD7 – pin de ie?ire
	//        76543210
	TCCR2 = 0b01101111; //FastPWM neinversat, N=1024
}void init_Buzzer()
{
	DDRD |= 1<<4; //PD4 - output
	TCCR1A = 0b00100010;
	TCCR1B = 0b00011010;
}void init_INT0()
{
	GICR |= (1<<6); // activarea întreruperii externe INT0
	MCUCR |= 0b00000011; // precizare c? evenimentul va avea loc pe frontul descrescator
	SREG |= (1<<7); // activarea globala a întreruperilor
}

void init_INT1()
{
	GICR |= (1<<7); // activarea întreruperii externe INT0
	MCUCR |= 0b00001100; // precizare ca evenimentul va avea loc pe frontul descrescator
	SREG |= (1<<7); // activarea globala a întreruperilor
}