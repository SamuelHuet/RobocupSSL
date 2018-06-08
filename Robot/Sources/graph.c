/*
 * graph.c
 *
 *  Created on: May 24, 2018
 *      Author: cocasticox
 */
#include "IO_Map.h"
#include "graph.h"

unsigned char Get_ADC(unsigned char channel){

	ADCSC1_ADCH = (channel & 0x1F);
	while(!ADCSC1_COCO);	//Attente fin conversion
	//do nothing
	return ADCRL;	//Récupère la valeur
}

void Draw_battery(unsigned char battery){
	unsigned char graph;
	PTHDD = PTHDD | 0b00011111; //port en sortie

	if(battery < 51){
		graph = 0b11110;
	}else if((battery >= 51) && (battery < 102)){
		graph = 0b11100;
	}else if((battery >= 102) && (battery < 153)){
		graph = 0b11000;
	}else if((battery >= 153) && (battery < 206)){
		graph = 0b10000;
	}else if((battery >= 206) && (battery < 255)){
		graph = 0b00000;
	}

	PTHD = (PTHD & 0b11100000) | graph;
}

void init_ADC(void){
	ADCSC2 = 0x00;
	ADCCFG = 0x00; 	//Config ADC
	ADCSC1 = 0x20;	//Config ADC, démarrage conversion
}
