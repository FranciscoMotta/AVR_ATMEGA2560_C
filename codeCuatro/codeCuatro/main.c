/*
 * codeCuatro.c
 *
 * Created: 26/10/2020 02:31:51
 * Author : HP
 */ 

#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	
	DDRB = 0xFF;
	
    while (1) 
    {
		PORTB = 1;
		_delay_ms(1000);
		PORTB = 0;
		_delay_ms(1000);
    }
}

