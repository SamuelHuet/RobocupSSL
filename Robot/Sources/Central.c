/*
 * Central.c
 *
 *  Created on: Jun 13, 2018
 *      Author: AVENIER
 */

#include "Cpu.h"
#include "Events.h"
#include "CI2C1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Central.h"

/*Initialisation de l'accelerometre*/
void initACC(void){
	unsigned short PWR_MGMT,GYRO_CONFIG;/*INT_PIN_CRG,ACCEL_CONFIG,CONFIG;*/
	unsigned char error;
	PWR_MGMT=0x6B;
	//INT_PIN_CRG=0x37;
	//ACCEL_CONFIG=0x1C;
	//CONFIG=0x1A;
	GYRO_CONFIG=0x1B;
	write(PWR_MGMT,0x01);
	write(GYRO_CONFIG,0x08);
}


/*Obtention de l'adresse*/
unsigned char getAdress(void) {
	unsigned char registre,valeur;
	registre = 0x75;
	valeur=read(registre);
	return valeur;
}

/*Obtention de la température*/
signed short getTemp(void){
	unsigned char registre1, registre2,val1,val2;
	signed short Temp;
	registre1=0x41;
	registre2=0x42;
	val1=read(registre1);
	val2=read(registre2);
	Temp=(((signed short)(val1<<8))|((signed short) (val2)));
	Temp=(Temp/340)+36;
	return Temp;
}


/*Obtention du déplacement en X de l'accelerometre*/
unsigned short getX(void){
	unsigned char registre1, registre2, val1, val2;
	unsigned short X;
	registre1 = 0x3B;
	registre2 = 0x3C;
	val1=read(registre1);
	val2=read(registre2);
	X = ((unsigned short) (val1 << 8)|(unsigned short) val2);
	return X;
}


/*Obtention du déplacement en Y de l'accelerometre*/
unsigned short getY(void){
	unsigned char registre1, registre2, val1, val2;
	unsigned short Y;
	registre1 = 0x3D;
	registre2 = 0x3E;
	val1=read(registre1);
	val2=read(registre2);
	Y = ((unsigned short) (val1 << 8)|(unsigned short) val2);
	return Y;
}


/*Obtention du déplacement en Z du gyroscope*/
unsigned short GYRO_Z(void){
	unsigned char registre1, registre2, val1, val2;
	unsigned short Z;
	registre1 = 0x71;
	registre2 = 0x72;
	val1=read(registre1);
	val2=read(registre2);
	Z = ((unsigned short) (val1 << 8)|(unsigned short) val2);
	return Z;
}


/*Fonction d'écriture en I2C*/
void write(unsigned char registre, unsigned char data){
	unsigned char error;
	unsigned short var;
	var=(registre<<8)|data;
	error = CI2C1_SelectSlave(0x68);
	error = CI2C1_SendBlock(&var, 2, &CI2C1_SndRcvTemp); 
}

/*Fonction de lecture en I2C*/
unsigned char read(unsigned char registre){
	unsigned char resultat,error;
	error = CI2C1_SelectSlave(0x68);
	error = CI2C1_SendBlock(&registre, 1, &CI2C1_SndRcvTemp);
	error = CI2C1_SelectSlave(0x68);
	error = CI2C1_RecvBlock(&resultat, 1, &CI2C1_SndRcvTemp);
	return resultat;
}


