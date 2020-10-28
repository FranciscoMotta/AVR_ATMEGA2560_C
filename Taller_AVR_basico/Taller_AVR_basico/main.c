/*
 * Taller_AVR_basico.c
 *
 * Created: 27/10/2020 19:50:22
 * Author : HP
 */ 

#include <avr/io.h>


int main(void)
{
	//COMPARATIVA MPLABX -> ATMEL STUDIO
	//MANEJO DE PUERTOS 
	/*
	TRISX -> ENTRADA/SALIDA == DDRX -> ENTRADA/SALIDA
	PORTX -> LEER PUERTO == PINX -> LEER PUERTO
	LATX -> ESCRIBIR == PORTX -> ESCRIBIR
	PARA PONER UN PUERTO COMO SALIDA 0X00 -> 0XFF
	*/
    /* Replace with your application code */
	
	/*TODO EL PUERTO B TENGA EL VALOR DE 10101010 = 0XAA*/
	
	DDRB = 0XFF; //PONEMOS A TODO EL PUERTO COMO SALIDA 
	
    while (1){
		PORTB = 0XAA;
    }
	return 0;
}

