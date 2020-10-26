/*
 * codigoDos.c
 *
 * Created: 26/10/2020 02:01:38
 * Author : HP
 */ 

#include <avr/io.h>


int main(void)
{
	unsigned char myList[] = "0123456789ABCDEF";
	unsigned char contadorDeLista;
	DDRB = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		for(contadorDeLista = 0 ; contadorDeLista < 16 ; contadorDeLista ++){
			PORTB = myList[contadorDeLista];
		}
    }
	return 0;
}

