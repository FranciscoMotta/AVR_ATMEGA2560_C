/*
 * LecturaDePuerto.c
 *
 * Created: 27/10/2020 00:08:04
 * Author : HP
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	
	unsigned char lecturaPuerto = 0;
	
	DDRB = 0X00; //Ponemos al puerto B como entrada digital
	DDRC = 0XFF; //Ponemos al puerto C como salida digital 
	
    while (1) 
    {
		lecturaPuerto = PINB;
		PORTC = lecturaPuerto;
    }
	return 0;
}

