/*
 * moteur.c

 *
 *  Created on: Jun 13, 2018
 *      Author: MSI_COCA
 */
#include "Cpu.h"
#include"moteur.h"


/*fonction qui prend en paramètre le rapport cyclique voulue*/
void RapportCyclique(unsigned short val) {

	/*Rapport cyclique de 43.9%
	 205*0.439=90(10)=(16)
	 unsigned char valeur;
	 valeur à rentrer dans le registre TPM1C1 pour obtenir le rapport cyclique souhaité
	 valeur=205*Ton;*/

	TPM3C0V = val;
}

void delay(unsigned long val) {

	while (val > 0) {
		val--;
	}

}

void init_moteur(void) {
	RapportCyclique(1); //rapport cyclique de 0
	delay(5000);
	RapportCyclique(29); //Ton  pendant 4% de la periode soit 800µs
	delay(50000); //Attendre les 4 beep du moteur
}

