/*
 * codeCinco.c
 *
 * Created: 26/10/2020 02:42:38
 * Author : HP
 */ 

// CONTADOR DE NÚMEROS NEGATIVOS

#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	
	unsigned char myList[] = {-4,-3,-2,-1,0,1,2,3,4};
	unsigned char myCounter = 0;
	
	DDRB = 0xFF;
	
    while (1) 
    {
		for(myCounter = 0 ; myCounter <= 8 ; myCounter++){
			PORTB = myList[myCounter];
			_delay_ms(1000);
		}
    }
	return 0;
}

