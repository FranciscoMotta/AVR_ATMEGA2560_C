/*
 * lcdPrimeraInterfaz.c
 *
 * Created: 27/10/2020 14:51:25
 * Author : HP
 */ 

#include <avr/io.h>


int main(void)
{
	unsigned char mensaje[] = "The Earth is but One Country"; //Creamos un arreglo para el mensaje por el LCD
	unsigned char variableDeConteo = 0;
    /* Replace with your application code */
	DDRB = 0xFF; //Ponemos al puerto B como salida
	DDRC = DDRC | 0b00100000 ; //Ponemos al pin 6 como salida
    while (1){
		for(variableDeConteo = 0 ; variableDeConteo < 28 ; variableDeConteo ++){
			//Realizamos un conteo para poder sacar las variables del arreglo
			PORTB = mensaje[variableDeConteo]; //Ponemos al puerto B los datos del arreglo
			PORTC = PORTC | 0b00100000; //Ponemos al pin 6 del puerto C como 1 
			PORTC = PORTC & 0b11011111; //Ponemos al pin 6 del puerto C como 0
		}
		while(1);
		return 0;
    }
}

