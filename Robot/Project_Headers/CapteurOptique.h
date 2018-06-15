/*
 * spi.h
 *
 *  Created on: Jun 12, 2018
 *      Author: AVENIER
 */

#ifndef SPI_H_
#define SPI_H_

#include "Cpu.h"
#include "Events.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"

#define CS PTJD_PTJD0

void nrf24_setupPins();
unsigned char spi_transfer(unsigned char tx);
void initCapteur(void);
void delay(unsigned short delay);

#endif /* SPI_H_ */
