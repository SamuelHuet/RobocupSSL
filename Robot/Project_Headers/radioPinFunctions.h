/*
 * radioPinFunctions.h
 *
 *  Created on: May 3, 2018
 *      Author: cocasticox
 */

#ifndef RADIOPINFUNCTIONS_H_
#define RADIOPINFUNCTIONS_H_

#include "IO_Map.h"

#define CE PTCD_PTCD5
#define CSN PTED_PTED0

void nrf24_setupPins(void);
void nrf24_ce_digitalWrite(unsigned char);
void nrf24_csn_digitalWrite(unsigned char);

#endif /* RADIOPINFUNCTIONS_H_ */
