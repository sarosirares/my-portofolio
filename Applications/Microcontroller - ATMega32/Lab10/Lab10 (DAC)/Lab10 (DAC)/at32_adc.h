/*
 * at32_adc.h
 *
 * Created: 11/13/2024 2:50:41 PM
 *  Author: rares
 */ 

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef AT32_ADC_H_
#define AT32_ADC_H_

void Init_adc();
void Init_adc_int();
uint16_t readADC(uint8_t ch);
void readADC_interrupt(uint8_t ch);

#endif /* AT32_ADC_H_ */