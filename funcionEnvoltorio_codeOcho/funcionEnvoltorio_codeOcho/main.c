/*
 * funciónEnvoltorio_codeOcho.c
 *
 * Created: 26/10/2020 23:54:22
 * Author : HP
 */ 

#define  F_CPU 16000000UL		

#include <avr/io.h>
#include <util/delay.h>

/************************************************************************/
/*	FUNCION ENVOLTORIO PARA EVITAR PROBLEMAS DE PORTABILIDAD                                                                     */
/************************************************************************/

int main(void)
{
    /* Replace with your application code */
	void delay_ms(int tiempo){
		_delay_ms(tiempo);
		/*Así sí ocurriera algún problema de portabilidad solo es cambiar la función anterior*/
	}
	DDRB = 0xFF;
	
    while (1){
		PORTB = 0XFF;
		delay_ms(1000);
		PORTB = 0X00;
		delay_ms(500);
    }
	return 0;
}

