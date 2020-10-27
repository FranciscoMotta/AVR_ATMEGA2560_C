/*
 * codigosVarios.c
 *
 * Created: 27/10/2020 00:15:15
 * Author : HP
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	
	unsigned char lector = 0;
	
	DDRB = 0X00; //Puerto B como entrada
	DDRC = 0XFF; //Puerto C como salida
	DDRD = 0XFF; //Puerto D como salida
	
    while (1) 
    {
		lector = PINB; //LEEMOS LOS DATOS DEL PUERTO B
		if (lector < 100){ //Hacemos una comparación para determinar el puerto de salida
			PORTC = lector;
		} else {
			PORTD = lector;
		}
			
    }
	return 0;
}

