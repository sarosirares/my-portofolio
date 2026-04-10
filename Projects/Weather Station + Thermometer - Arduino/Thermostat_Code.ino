#include <avr/io.h>
#include <avr/interrupt.h>

/*pins 22-31 segments of 7-segment
  pins 34-37 digits of 7 segment
  pins 43-49 segments of 2nd 7 segment, single digit
  pin 12 PWM led
  pin A0 ADC input*/

uint8_t digit = 0;
uint16_t value;
uint16_t ms = 0;
uint16_t adc_value;
uint16_t tmp;
uint16_t Vin;
uint8_t modeSel;
bool state = false;

unsigned long lastInterruptTime = 0;

ISR(TIMER0_COMPA_vect)
{
  digit++;
  switch(digit){
	  case 1: display(4,value*4%10, modeSel); break;
	  case 2: display(3,(value*4/10)%10, -1); break;
	  case 3: display(2,(value*4/100)%10, -1); break;
	  case 4: display(1,(value*4/1000)%10, -1); digit=0; break;
  }
  if (ms == 100){
	  value = readADC(0)/4;
    OCR1A = value;
    ms = 0;
  }else ms++;
}

ISR(INT1_vect)
{
  //unsigned long interruptTime = millis();
  //if (interruptTime - lastInterruptTime > 200)
  //{
    if (modeSel < 4)
      modeSel++;
    else
      modeSel = 0;
  //}
  //lastInterruptTime = interruptTime;
}

void setup() {
  // put your setup code here, to run once:
  DDRA = 0b11111111;
  DDRC = 0b00011111;
  DDRL = 0b01111111;
  cli();
  EICRA |= 0b0001100;
  EIMSK = 0b00000010;
  sei();
  init_timer();
  init_PWM();
  init_adc();
  value = 0;

}

void loop() {
  // put your main code here, to run repeatedly:

}
void init_timer()
{
  TCCR0A = 0b01000000;
  TCCR0B = 0b00000011;
  TCNT0 = 0;
  OCR0A = 125;
  TIMSK0 |= 0b00000010;
  SREG |= 1<<7; 
}

void init_PWM()
{
  DDRB |= 1<<5;
  TCCR1A = 0b10000011;
  TCCR1B = 0b00001001;
}

void init_adc()
{
  ADMUX = 0b01000000;
  ADCSRA = 0b10000111;
  ADCSRA |= (1<<3);
  SREG |= (1<<7);
}

uint16_t readADC(uint8_t ch)
{
  uint16_t adc_l, adc_h;
  ADMUX &= 0b11100000;
  ADMUX |= ch;
  ADCSRA |= (1<<6);
  while (ADCSRA & (1<<6));
  adc_l = ADCL;
  adc_h = ADCH;
  return ((adc_h << 8) | adc_l); 
}

void display(int digit, int value, int mode)
{
  switch(value)
	{
    case -1:
    PORTA = 0b10000000; break;

		case 0:
		PORTA = 0b00111111; break;
		
		case 1:
		PORTA = 0b00000110; break;
		
		case 2:
		PORTA = 0b01011011; break;
		
		case 3:
		PORTA = 0b01001111; break;
		
		case 4:
		PORTA = 0b01100110; break;
		
		case 5:
		PORTA = 0b01101101; break;
		
		case 6:
		PORTA = 0b01111101; break;
		
		case 7:
		PORTA = 0b00000111; break;
		
		case 8:
		PORTA = 0b01111111; break;

		case 9:
		PORTA = 0b01101111; break;
	}

  switch(mode)
  {
    case -1:
    PORTL = 0b00000000; break;

    case 0:
    PORTL = 0b00111111; break;

    case 1:
    PORTL = 0b00000110; break;

    case 2:
    PORTL = 0b01011011; break;

    case 3:
    PORTL = 0b01001111; break;

    case 4:
    PORTL = 0b01100110; break;

    case 5:
    PORTL = 0b01101101; break;

    case 6:
    PORTL = 0b01111101; break;

    case 7:
    PORTL = 0b00000111; break;

    case 8:
    PORTL = 0b01111111; break;

    case 9: 
    PORTL =0b011011111; break;
  }
	
	switch (digit)
	{
    case -1: PORTC = 0b11110000; break;
    case 0: PORTC = 0b11111111; break;
		case 1: PORTC = 0b11111110; break;
		case 2: PORTC = 0b11111101; break;
		case 3: PORTC = 0b11111011; break;
		case 4: PORTC = 0b11110111; break;
	}
  delay(2);
}