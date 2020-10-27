/*
 * restoDeCode.c
 *
 * Created: 27/10/2020 14:42:52
 * Author : HP
 */ 

#include <avr/io.h>


int main(void)
{
	unsigned char lector_Puerto = 0;
	DDRC = 0XFF; //Ponemos al puerto C como salida
	DDRB = 0X00; //Ponemos al puerto B como entrada
    /* Replace with your application code */
    while (1) 
    {
		lector_Puerto = PINB; //Leemos el puerto B
		if(lector_Puerto & 0b00010000) { //Leemos solo el pin 5 del puerto B
			PORTC = 0X55; //Ponemos el valor de 55 en hexa al puerto C
		} else {
			PORTC = 0xAA; //Ponemos el valor de AA en hexa en el puerto C
		}
    }
	return 0;
}

