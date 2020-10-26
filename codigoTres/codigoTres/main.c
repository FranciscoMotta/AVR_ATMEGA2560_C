/*
 * codigoTres.c
 *
 * Created: 26/10/2020 02:10:04
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
		DDRB = 0XFF; /*Ponemos al puerto B como salida*/
		PORTB = 0XAA; /*Damos un valor al puerto B*/
		unsigned char counter; // Creamos una variable sin signo para la cuenta
		for( counter = 0 ; counter < 200 ; counter++){
			PORTB = ~PORTB;
			_delay_ms(1000);
		}
		while(1); //Creamos un bucle
		return 0;
}

