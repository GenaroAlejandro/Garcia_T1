#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"

#define DELAY 1000000

void delay(uint32_t delay);


int main(void) {

	SIM->SCGC5 = 0x2400; //Inicialización del reloj del PORTB y PORTE

	PORTB->PCR[22] = 0x00000100; //001 Alternative 1 (GPIO) para el pin 22 en el PORTB
	PORTB->PCR[21] = 0x00000100; //001 Alternative 1 (GPIO) para el pin 21 en el PORTB
	PORTE->PCR[26] = 0x00000100; //001 Alternative 1 (GPIO) para el pin 26 en el PORTC

	GPIOB->PDOR = 0x00600000; //Buena práctica (Pines de salida 22 y 21 off)
	GPIOE->PDOR = 0x04000000; //Buena práctica (Pine de salida 26 off)

	GPIOB->PDDR = 0x00600000; //PDDR: configuración de salida en el PORTB, pines 22 y 21
	GPIOE->PDDR = 0x04000000; //PDDR: configuración de salida en el PORTB, pine 26
    while(1) {

		GPIOB->PDOR = 0x00400000;
		printf("BLUE LED ON\n");
		delay(DELAY);

		GPIOB->PDOR= 0x00600000;
		printf("BLUE LED OFF\n");
		delay(DELAY);

		GPIOB->PDOR= 0x00200000;
		printf("RED LED ON\n");
		delay(DELAY);

		GPIOB->PDOR= 0x00600000;
		printf("RED LED OFF\n");
		delay(DELAY);

		GPIOE->PDOR = 0;
		printf("GREEN LED ON\n");
		delay(DELAY);

		GPIOE->PDOR= 0x04000000;
		printf("GREEN LED OFF\n");
		delay(DELAY);

    }
    return 0 ;
}

void delay(uint32_t delay)
{
  volatile uint32_t i;
  for (i = 0; i<delay; ++i)
    {
    }
}

