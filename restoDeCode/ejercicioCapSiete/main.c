/*
 * ejercicioCapSiete.c
 *
 * Created: 27/10/2020 14:59:55
 * Author : HP
 */ 

/* Escribir un código AVR C que pueda leer los pines del puerto B, y que envíe unos datos
 por el puerto D siguiendo la siguiente tabla:
			pin1     pin0    
			0         0    Envia 0
			0         1	   Envia 1
			1         0    Envia 2 
			1         1    Envía 4
*/

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	unsigned char lectorPuerto = 0;
	DDRB = 0x00; //Ponemos solo los pines 1 y 0 como entrada digital
	DDRD = 0xFF; //Ponemos al puerto B como salida
    while (1) 
    {
		lectorPuerto = PINB;
		lectorPuerto = lectorPuerto & 0X03;
		switch(lectorPuerto){
			case 0:
			{
				PORTD = 0b00000000;
				break;
			}
			case 1:
			{
				PORTD = 0b00000001;
				break;
			}
			case 2:
			{
				PORTD = 0b00000010;
				break;
			}
			case 3:
			{
				PORTD = 0b00000011;
				break;
			}
		}
    }
	return 0;
}

