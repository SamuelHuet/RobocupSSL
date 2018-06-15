/*
 * spi.c
 *
 *  Created on: Jun 12, 2018
 *      Author: AVENIER
 */
#include"CapteurOptique.h"

void nrf24_setupPins() {
	PTCDD_PTCDD5 = 1; //CE as output
	PTEDD_PTEDD0 = 1; //CSN as output

	SPI1BR = 0x03; //No prescaler of bus clock
	SPI1C2_MODFEN = 0; //manual CS part 2
	SPI1C1_LSBFE = 0; //MSB first
	SPI1C1_SSOE = 0; //manual CS part 1 
	SPI1C1_CPHA = 1;
	SPI1C1_CPOL = 1;
	SPI1C1_MSTR = 1; //i'm the master
	SPI1C1_SPE = 1; //system enable
}

/* software spi routine */
unsigned char spi_transfer(unsigned char tx) {
	volatile unsigned char rx = 0;
	unsigned short i = 0;

	if (SPI1S_SPTEF) {  //Tant que le buffer n'est pas vide
		SPI1D = tx;
	}

	for (i = 5; i > 0; --i) {
	}

	if (SPI1S_SPRF) {
		rx = SPI1D;
	}

	return rx;

}

void initCapteur(void) {
	CS = 0;
	if (SPI1S_SPTEF) {
		SPI1D = 0x8a; //envoie des données sur le bus SPI
		delay(200);
	}
	if (SPI1S_SPTEF) {
		SPI1D = 0x10; //envoie des données sur le bus SPI
		delay(200);
	}
	CS = 1;
}

void delay(unsigned short delay) {
	unsigned short i;
	for (i = delay; i > 0; --i)
		;
}

