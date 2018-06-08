/*
* ----------------------------------------------------------------------------
* â€œTHE COFFEEWARE LICENSEâ€� (Revision 1):
* <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a coffee in return.
* -----------------------------------------------------------------------------
* Please define your platform spesific functions in this file ...
* -----------------------------------------------------------------------------
*/

#include "radioPinFunctions.h"

/* ------------------------------------------------------------------------- */

void nrf24_setupPins()
{
    PTADD_PTADD1=1; //CE as output
	PTBDD_PTBDD5=1; //CSN as output

    SPIBR=0x04; //No prescaler of bus clock
	SPIC2_MODFEN=0; //manual CS part 2
	SPIC1_LSBFE=0; //MSB first
	SPIC1_SSOE=0; //manual CS part 1 
	SPIC1_CPHA=0; 
	SPIC1_CPOL=0; 
	SPIC1_MSTR=1; //i'm the master
	SPIC1_SPE=1; //system enable
}
/* ------------------------------------------------------------------------- */
void nrf24_ce_digitalWrite(unsigned char state)
{
	PTAD_PTAD1 = state;
}
/* ------------------------------------------------------------------------- */
void nrf24_csn_digitalWrite(unsigned char state)
{
	PTBD_PTBD5 = state;
}

