/*
 * at32_adc.c
 *
 * Created: 11/13/2024 2:50:21 PM
 *  Author: rares
 */ 

#include "at32_adc.h"
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void Init_adc()
{
	ADMUX = 0b01000000; //Referinta - AVCC
	ADCSRA = 0b10000110; //Activare ADC; Prescaler = 64;
}void Init_adc_int()
{
	ADMUX = 0b01000000; //Referinta - AVCC
	ADCSRA = 0b10000110; //Activare ADC; Prescaler = 64;
	
	//ex2
	
	ADCSRA |= (1<<3); //Activare întrerupere ADIE
	SREG |= (1<<7); //Global Interrupt Enable
}uint16_t readADC(uint8_t ch){	uint16_t adc_l, adc_h;	ADMUX &= 0b11100000; //Reseteaza canalul de conversie
	ADMUX |= ch; //Seteaz? canalul conversiei
	ADCSRA |= (1<<6); //Începe conversia
	while(ADCSRA & (1<<6)); //Asteapta finalizarea conversiei
	adc_l = ADCL;
	adc_h = ADCH;
	return ((adc_h << 8) | adc_l);}void readADC_interrupt(uint8_t ch){	ADMUX &= 0b11100000; //Reseteaz? canalul de conversie
	ADMUX |= ch; //Seteaz? canalul conversiei
	ADCSRA |= (1<<6); //Începe conversia}