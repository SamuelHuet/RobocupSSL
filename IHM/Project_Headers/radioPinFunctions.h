#include "IO_Map.h"

#define CE PTAD_PTAD1
#define CSN PTBD_PTBD5

void nrf24_setupPins(void);
void nrf24_ce_digitalWrite(unsigned char);
void nrf24_csn_digitalWrite(unsigned char);
