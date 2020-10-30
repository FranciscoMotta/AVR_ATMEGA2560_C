/*
 * Manejo de pines.c
 *
 * Created: 30/10/2020 00:20:53
 * Author : HP
 */ 
#define F_CPU 16000000UL		

#include <avr/io.h>
#include <util/delay.h>

#define pinSerial 1 
#define clockLCD 0

void tiempoEnable (void){ //HACEMOS UNA FUNCIÓN PARA PODER CONTROLAR EL ENABLE
	PORTC |= (1 << clockLCD);
	_delay_ms(1);
	PORTC &= ~ (1 << clockLCD);
	_delay_ms(1);
}

void Desplazador_De_Datos( char dato ){
		unsigned char byteParalelo = dato;
		unsigned char registroDesplazamiento = 0;
		unsigned char contadorDeDesplazamiento = 0;
		registroDesplazamiento = byteParalelo;
		for (contadorDeDesplazamiento = 0 ; contadorDeDesplazamiento < 8 ; contadorDeDesplazamiento++){
			if(registroDesplazamiento & 0x01){
				PORTC |= (1<<pinSerial);
				} else {
				PORTC &= ~(1 << pinSerial);
			}
			tiempoEnable();
			_delay_ms(1);
			registroDesplazamiento = registroDesplazamiento >> 1;
		}	
}

int main(void)
{
	DDRC = 0x0F;
	
	 
    /* Replace with your application code */
    while (1){
		Desplazador_De_Datos(0xAA);
		_delay_ms(1000);
		Desplazador_De_Datos(0x55);
		_delay_ms(1000);
		while(1);	
    }
	return 0;
}

