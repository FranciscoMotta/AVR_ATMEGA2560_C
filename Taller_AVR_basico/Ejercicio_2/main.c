/*
 * Ejercicio_2.c
 *
 * Created: 27/10/2020 19:56:38
 * Author : HP
 */ 

#include <avr/io.h>


int main(void)
{
	//VAMOS A MOSTRAR TODO LO QUE EST� EN EL PUERTO C EN EL PUERTO B
    /* Replace with your application code */
	DDRB = 0XFF; //Ponemos al puerto B como salida
	DDRC = 0X00; //Ponemos al puerto C como entrada
	
	unsigned char lectorPuerto = 0;
	
    while (1) {
		lectorPuerto = PINC; //Leemos el puerto y lo guardamos en una variable
		PORTB = lectorPuerto; //Mostramos por el puerto B lo que est� en la variable
    }
	return 0;
}

