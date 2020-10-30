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
#define ENABLE 3
#define RS 2

void tiempoEnable (void){ //HACEMOS UNA FUNCIÓN PARA PODER CONTROLAR EL ENABLE
	PORTC |= (1 << clockLCD);
	_delay_ms(1);
	PORTC &= ~ (1 << clockLCD);
	_delay_ms(1);
}

void Modo_Comando(void){
	PORTC &= ~(1 << RS);
	_delay_ms(1);
}

void Modo_Caracter(void){
	PORTC |= (1 << RS);
	_delay_ms(1);
}

void Tiempo_De_Enable (void) {
	PORTC |= (1 << ENABLE);
	_delay_ms(3);
	PORTC &= ~(1 << ENABLE);
	_delay_ms(3);
}

void Desplazador_De_Datos( char dato ){
		unsigned char byteParalelo = dato;
		unsigned char registroDesplazamiento = 0;
		unsigned char contadorDeDesplazamiento = 0;
		
		registroDesplazamiento = byteParalelo;
		for (contadorDeDesplazamiento = 0 ; contadorDeDesplazamiento < 8 ; contadorDeDesplazamiento++){
			if(registroDesplazamiento & 0x01){
				PORTC |= (1<< pinSerial);
				//PORTBbits.RB0  = 0 ; NO EXISTE!!!!
				//PUERTO AVR POR LO GENERAL TIENE 8 BITS -> 1 BYTE 
				//REGISTRO ES EL PORTX -> A,B,C,D,E,F,G,H
				// << # >> # DESPLAZAR UN BIT
				// PORTB = (1 << 5) = (0B00100000) PORTCbits.RC5 
				//suma = suma or (1 << pinSerial) 
				} else {
				PORTC &= ~(1 << pinSerial);
				// PORTC = PORTC & ~(1 << pinSerial)
			}
			tiempoEnable();
			_delay_ms(1);
			registroDesplazamiento = registroDesplazamiento >> 1;
		}	
}

int main(void){
	DDRC = 0X0F;
	//Areglos para el manejo del LCD
		
	unsigned char datosConf[4] = {0x01, 0x38,0x0C, 0X06};
	unsigned char mensajeLcd[15] = {'H','O','L','A', ' ', 'L','C','D',' ','C','O','N',' ','F','F'};
		
	int contador_Local = 0;
    /* Replace with your application code */
    while (1){
		Modo_Comando();
		for(contador_Local = 0; contador_Local < 4 ; contador_Local ++){
			Desplazador_De_Datos(datosConf[contador_Local]);
			Tiempo_De_Enable();	
		}
		Modo_Caracter();
		for (contador_Local = 0 ; contador_Local < 15 ; contador_Local ++){
			Desplazador_De_Datos(mensajeLcd[contador_Local]);
			Tiempo_De_Enable();
		}
		while(1);	
    }
	return 0;
}

