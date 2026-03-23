/*
 * at32_adc.c
 *
 * Created: 12/17/2024 10:05:04 PM
 *  Author: rares
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include "at32_adc.h"

void init_ADC()
{
	ADMUX = 0b01000000; //Referin?a - AVCC
	ADCSRA= 0b10000111; //Activare ADC; Prescaler = 128;
}

void init_ADC_int()
{
	ADMUX = 0b01000000;		//Referin?a - AVCC
	ADCSRA = 0b10000111;	//Activare ADC; Prescaler = 128;
	ADCSRA |= (1<<3);		//Activare întrerupere ADIE
	SREG |= (1<<7);			//Global Interrupt Enable
}

uint16_t readADC(uint8_t ch)
{
	uint8_t adc_l, adc_h;
	ADMUX &= 0b11100000;	//Reseteaz? canalul de conversie
	ADMUX |= ch;			//Seteaz? canalul conversiei
	ADCSRA |= (1<<6);		//Începe conversia
	while(ADCSRA & (1<<6)); //A?teapt? finalizarea conversiei
	adc_l = ADCL;
	adc_h = ADCH;
	return ((adc_h << 8) | adc_l);
}

void readADC_int(uint8_t ch)
{
	ADMUX &= 0b11100000;	//Reseteaz? canalul de conversie
	ADMUX |= ch;			//Seteaz? canalul conversiei
	ADCSRA |= (1<<6);		//Începe conversia
}