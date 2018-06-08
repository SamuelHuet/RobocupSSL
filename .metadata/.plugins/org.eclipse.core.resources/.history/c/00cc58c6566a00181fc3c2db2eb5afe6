/*
 * Dribleur.c
 *
 *  Created on: Jun 7, 2018
 *      Author: Thomas
 */
#include "Dribleur.h"
#include "IO_Map.h"

void init_PWM(void){
	TPM3C4V=0x0A;
	TPM3MOD=0x0A;
	TPM3C4SC=0x08;
	TPM3SC=0x2F;
}

void On_Dribleur(unsigned char c){
	if(c==1){
		TPM3C4V=0x01;
	}
	else{
		TPM3C4V=0x0A;
	}
}
