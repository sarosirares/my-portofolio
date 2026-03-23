/*
 * at32_adc.h
 *
 * Created: 12/17/2024 10:04:45 PM
 *  Author: rares
 */ 


#ifndef AT32_ADC_H_
#define AT32_ADC_H_

void init_ADC();
void init_ADC_int();
uint16_t readADC(uint8_t ch);
void readADC_int(uint8_t ch);


#endif /* AT32_ADC_H_ */