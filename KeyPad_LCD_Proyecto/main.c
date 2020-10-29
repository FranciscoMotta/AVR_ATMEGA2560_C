/*
 * LCD_PRIMER_MODELO_SIMPLE.c
 *
 * Created: 27/10/2020 16:39:46
 * Author : HP
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define ENABLE 7 
#define RS 6

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
	unsigned char textmat[15] = {'K','E','Y','P','A','D',' ','L','C','D',' ','K'}; //CREAMOS UN ARREGLO PARA EL MENSAJE A MOSTRAR
	unsigned char numboton[16] = {'7','8','9','%','4','5','6','x','1','2','3','-','o','0','=','+'};
	int counterLocal = 0; //UN CONTADOR PARA SACAR LOS DATOS DE CADA ARREGLO
	unsigned char keyPadDataEnable = 0;
	unsigned char lectorGeneral = 0;
	DDRB = 0XFF;
	DDRC = 0xC0;
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
			keyPadDataEnable = PINC & 0b00010000;
			if(keyPadDataEnable){
				lectorGeneral = PINC & 0b00001111;
				posicion_Linea_Inferior(7);
				modoCaracter();
				PORTB = numboton[lectorGeneral];
				tiempoEnable();			
			} else {
			}
		}
    }
	return 0;
}

