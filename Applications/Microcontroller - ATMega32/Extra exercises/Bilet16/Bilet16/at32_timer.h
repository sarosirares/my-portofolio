/*
 * at32_timer.h
 *
 * Created: 12/17/2024 3:18:52 PM
 *  Author: rares
 */ 
#include <avr/io.h>

#ifndef AT32_TIMER_H_
#define AT32_TIMER_H_

void init_timer_0();
void init_timer_2();
void init_timer_0_int();
void init_timer_1_int();
void init_timer_2_int();
void init_PWM0();
void init_PWM2();
void init_INT0();
void init_INT1();


#endif /* AT32_TIMER_H_ */