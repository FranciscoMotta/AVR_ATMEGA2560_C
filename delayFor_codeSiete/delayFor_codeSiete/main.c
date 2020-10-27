/*
 * delayFor_codeSiete.c
 *
 * Created: 26/10/2020 23:21:08
 * Author : HP
 */ 

#include <avr/io.h>

void timeDelay100Ms (void){ //Creamos una función para realizar un delay
	unsigned int z ;
	for (z = 0 ; z < 42150 ; z++); //Hacemos un loop de cuenta para que se repita N veces
}

//Consideraciones Cristal de 8MHZ

void multiplicadorDeTiempoDe100Ms (int multiplicador){ //Creamos una función de repetición para el tiempo base de 100ms
	int variableLocal = 0;
	for( variableLocal = 0 ; variableLocal < multiplicador ;variableLocal ++){
		timeDelay100Ms();
	}
}

int main(void)
{
    /* Replace with your application code */
	DDRB = 0XFF; //Ponemos el puerto B como salida digital
    while (1) 
    {
		PORTB = 0x55;
		multiplicadorDeTiempoDe100Ms(10);
		PORTB = 0xAA;
		multiplicadorDeTiempoDe100Ms(10);
    }
	return 0;
}

