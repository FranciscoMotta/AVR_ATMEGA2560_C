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

#define PRIMER_BOTON 7
#define SEGUNDO_BOTON 6

void modoCaracter (void) { //PONEMOS AL LCD EN MODO CARACTER PARA MOSTRAR EL MENSAJE
	PORTC |= (1 << RS); //PONEMOS AL PIN 0 COMO 1 
	_delay_ms(3);
}

void modoComando (void){ //PONEMOS AL LCD EN MODO COMANDO PARA CONFIGURAR SUS CARACTERÍSTICAS
	PORTC &= ~ (1 << RS); //PONEMOS AL PIN 0 COMO 0
	_delay_ms(3);
}

void tiempoEnable (void){ //HACEMOS UNA FUNCIÓN PARA PODER CONTROLAR EL ENABLE
	PORTC |= (1 << ENABLE);
	_delay_ms(1);
	PORTC &= ~ (1 << ENABLE);
	_delay_ms(1);
}

void posicion_Linea_Inferior (int posicion){
	modoComando();
	PORTB = 0xC0 + posicion;
	tiempoEnable();
}

void posicion_Linea_Superior (int posicion){
	modoComando();
	PORTB = 0x80 + posicion;
	tiempoEnable();
}

int main(void)
{
	unsigned char dataConf[4] = {0x01, 0x38, 0x06, 0x0c}; //CREAMOS UN ARREGLO DE DATOS DE CONFIGURACIÓN
	unsigned char textmat[15] = {'H','O','L','A',' ','A',' ','T','O','D','O','S'}; //CREAMOS UN ARREGLO PARA EL MENSAJE A MOSTRAR
	unsigned char numboton[4] = {'1','2','3','4'};
	int counterLocal = 0; //UN CONTADOR PARA SACAR LOS DATOS DE CADA ARREGLO
	unsigned char lectorGeneral = 0;
	DDRB = 0XFF;
	DDRC = 0x0F;
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
		posicion_Linea_Superior(2);
		modoCaracter();
		for ( counterLocal = 0 ; counterLocal < 12 ; counterLocal++){
			PORTB = textmat[counterLocal];
			tiempoEnable();
		}
		while(1){
			posicion_Linea_Inferior(7);
			modoCaracter();
			lectorGeneral = PINC & 0XC0;
			if(lectorGeneral == 0x00){
				PORTB = numboton[0];
				tiempoEnable();
			}
			if(lectorGeneral == 0x40){
				PORTB = numboton[1];
				tiempoEnable();
			}
			if(lectorGeneral == 0x80){
				PORTB = numboton[2];
				tiempoEnable();
			}
			if(lectorGeneral == 0xC0){
				PORTB = numboton[3];
				tiempoEnable();
			} else {
			}
		}
    }
	return 0;
}

