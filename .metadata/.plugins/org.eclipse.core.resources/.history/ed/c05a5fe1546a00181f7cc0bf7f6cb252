/* ###################################################################
 **     Filename    : main.c
 **     Project     : Radio128
 **     Processor   : MC9S08QE128CLK
 **     Version     : Driver 01.12
 **     Compiler    : CodeWarrior HCS08 C Compiler
 **     Date/Time   : 2018-05-30, 13:45, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.12
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */         
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PWM1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "nrf24.h"
#include "graph.h"
#include "Dribleur.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

void main(void)
{
	/* Write your local variable definition here */

	unsigned char data_array[5]={0x00, 0x00, 0x00, 0xFF, 0x00};
	unsigned char data_dir[4]={0x00, 0x00, 0x00, 0x00};
	unsigned char tx_address[5] = {0xE7, 0xE7, 0xE7, 0xE7, 0xE7};
	unsigned char rx_address[5] = {0xD7, 0xD7, 0xD7, 0xD7, 0xD7};
	unsigned long i;

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */

	for (i = 0; i < 5000; ++i) {

	};
	init_PWM();
	init_ADC();
	nrf24_init();
	nrf24_config(2, 4);
	PTEDD_PTEDD5=1;
//nrf24_powerUpRx();

	for(;;){

		data_array[0] = Get_ADC(0);
		Draw_battery(data_array[0]);

		nrf24_send(data_array);
		while(nrf24_isSending());
		On_Dribleur(0);
		


		
		/*for (i = 0; i < 1000; ++i) {

		}*/

		/*i=0;
		while((!nrf24_dataReady()) && (i<100)){	//Attente d'une donnée + Timeout
			i++;					//Récupération de la donnée
		}
		if(nrf24_dataReady()){
			nrf24_getData(data_dir);
		}*/


/*		nrf24_powerUpTx();
		for (i = 0; i < 1000; ++i) {

		} */



/*	if(data_dir[0] != 0x7F){
			PTED_PTED5=0;
		}else if(data_dir[1] != 0x7F){
			PTED_PTED5=0;
		}else if(data_dir[2] != 0x00){
			PTED_PTED5=0;
		}else{
			PTED_PTED5=1;
		}	*/



		for (i = 0; i < 0x35; ++i) {

		}
	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.3 [05.09]
 **     for the Freescale HCS08 series of microcontrollers.
 **
 ** ###################################################################
 */
