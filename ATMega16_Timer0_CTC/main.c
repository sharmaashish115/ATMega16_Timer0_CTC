/*
 * ATMega16_Timer0_CTC.c
 *
 * Created: 2023-06-02 1:22:39 PM
 * Author : a_shi
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRD |= (1<<6);
	//timer_init();
	
	TCCR0 |= (1<<WGM01) | (1<<CS00) | (1<<CS02);
	TCCR0 &= ~(1<<CS01);
	
	TCNT0 = 0;
	OCR0 =220;
	
	TIMSK |= (1<<OCIE0);
	sei();
	
    while (1) 
    {
    }
}
/*
void timer_init(void)
{
	TCCR0 |= (1<<WGM01) | (1<<CS00) | (1<<CS02);
	TCCR0 &= ~(1<<CS01);
	
	TCNT0 = 0;
	OCR0 =220;
	
	TIMSK |= 1(<<OCIE0);
	sei();
	
}*/

ISR (TIMER0_COMP_vect)
{
	PORTD^= (1<<6);
	
}