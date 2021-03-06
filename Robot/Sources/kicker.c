/*
 * kicker.c
 *
 *  Created on: Jun 8, 2018
 *      Author: Thomas
 */
#include "Kicker.h"
#include "IO_Map.h"
#include "graph.h"

#define Adc_feedback 0x0A 
#define Charge_done 0x0A		/* calculer la valeur pour 150V =>135mv sur le feedback */



void Init_Kick(void){
	unsigned char i;
	PTBDD_PTBDD1=1;		/* port en sortie (kick) */
	PTBDD_PTBDD0=1;		/* port en sortie (charge) */

	PTBD_PTBD0=1;
	for (i = 0; i < 9; ++i){
		delay_1ms();
	}
	PTBD_PTBD0=0;
	for (i = 0; i < 9; ++i){
		delay_1ms();
	}
	PTBD_PTBD0=1;		/* Lance la charge des capa */
	PTBD_PTBD1=1;		/* Kick off */
}

void Kick_Charge (void){
	unsigned char feedback_value=Get_ADC(Adc_feedback);		/* Convertie la valeur du feedback */
	if (feedback_value==Charge_done){						/* Si feedback_value superieur ou �gale � Charge_done*/
		PTBD_PTBD0=0;										/* Desactive la charge */
	}
	else{													/* Sinon */
		PTBD_PTBD0=1;										/* Active la charge */
	}
}

void Kick_ON(unsigned char *k){
	unsigned char i=0;
	if(*k==0){						/* Si l'ordre de tirer est donn� */ 
		PTBD_PTBD0=0;				/* D�sactive la charge pour pouvoir tirer */ 
		PTBD_PTBD1=0;				/* Kick on */
		for(i=0; i<=50; i++){		/* Delay de 50ms temps de tir */
			delay_1ms();
		}
		PTBD_PTBD1=1;				/* KIck off */
	}
	else{							/* Sinon */
		PTBD_PTBD1=1;		
	}
	*k = 1;
}

void delay_1ms (void){
	asm{			/* Delay 1ms */
		LDHX	#$18
		T1:	LDA		#$FF
		T0:	DECA	
		BNE		T0
		AIX		#-1
		CPHX	#$00
		BNE		T1
		RTS
	}
}
