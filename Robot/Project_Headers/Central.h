/*
 * Central.h
 *
 *  Created on: Jun 13, 2018
 *      Author: AVENIER
 */

#ifndef CENTRAL_H_
#define CENTRAL_H_

void initACC(void);
unsigned char getAdress(void);
signed short getTemp(void);
unsigned short getX(void);
unsigned short getY(void);
unsigned short GYRO_Z(void);
void write(unsigned char registre, unsigned char data);
unsigned char read(unsigned char registre);

#endif /* CENTRAL_H_ */
