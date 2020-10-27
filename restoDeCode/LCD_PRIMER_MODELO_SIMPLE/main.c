/*
 * LCD_PRIMER_MODELO_SIMPLE.c
 *
 * Created: 27/10/2020 16:39:46
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define ENABLE 1
#define RS 0

void modoCaracter (void) {
	PORTC |= (1 << RS);
	_delay_ms(3);
}

void modoComando (void){
	PORTC &= ~ (1 << RS);
	_delay_ms(3);
}

void tiempoEnable (void){
	PORTC |= (1 << ENABLE);
	_delay_ms(2);
	PORTC &= ~ (1 << ENABLE);
	_delay_ms(2);
}

int main(void)
{
	unsigned char dataConf[4] = {0x01, 0x38, 0x06, 0x0c};
	unsigned char textmat[15] = {'H','O','L','A',' ','A',' ','T','O','D','O','S'};
	int counterLocal = 0;
	DDRB = 0XFF;
	DDRC = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		//CONFIGURAMOS AL LCD
		modoComando();
		for (counterLocal = 0 ; counterLocal < 4 ; counterLocal++){
			PORTB = dataConf[counterLocal];
			tiempoEnable();
		}
		//MOSTRAMOS EL MENSAJE
		modoCaracter();
		for ( counterLocal = 0 ; counterLocal < 12 ; counterLocal++){
			PORTB = textmat[counterLocal];
			tiempoEnable();
		}
		while(1);
    }
	return 0;
}

