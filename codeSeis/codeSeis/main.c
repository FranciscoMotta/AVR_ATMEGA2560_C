/*
 * codeSeis.c
 *
 * Created: 26/10/2020 02:50:00
 * Author : HP
 */ 

#define F_CPU 16000000UL	

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /*Replace with your application code*/
	
	DDRB = 0XFF;
	
	// HACEMOS UN ITERADOR DE ESTADOS SIN EL NEGADOR ~
	
    while (1) 
    {
		PORTB = 0XAA;
		_delay_ms(1000);
		PORTB = 0X55;
		_delay_ms(1000);
    }
	return 0;
}

