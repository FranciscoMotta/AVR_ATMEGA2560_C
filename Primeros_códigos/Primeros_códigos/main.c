/*
 * Primeros_códigos.c
 *
 * Created: 25/10/2020 03:07:12
 * Author : HP
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		int z; /* Creamos una variable del tipo caracter sin signo */
		DDRB = 0XFF ; /* Ponemos a todo el puerto B como salida */
		PORTB = 0XFF;
	}
	return 0;
}

