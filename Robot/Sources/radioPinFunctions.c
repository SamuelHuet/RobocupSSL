/*
 * radioPinFunctions.c
 *
 *  Created on: May 3, 2018
 *      Author: cocasticox
 */

#include "radioPinFunctions.h"

/* ------------------------------------------------------------------------- */

void nrf24_setupPins()
{
    PTCDD_PTCDD5=1; //CE as output
	PTEDD_PTEDD0=1; //CSN as output
	
    SPI1BR=0x01; //No prescaler of bus clock
	SPI1C2_MODFEN=0; //manual CS part 2
	SPI1C1_LSBFE=0; //MSB first
	SPI1C1_SSOE=0; //manual CS part 1 
	SPI1C1_CPHA=0; 
	SPI1C1_CPOL=0; 
	SPI1C1_MSTR=1; //i'm the master
	SPI1C1_SPE=1; //system enable
}
/* ------------------------------------------------------------------------- */
void nrf24_ce_digitalWrite(unsigned char state)
{
    PTCD_PTCD5 = state;
}
/* ------------------------------------------------------------------------- */
void nrf24_csn_digitalWrite(unsigned char state)
{
	PTED_PTED0 = state;
}

