/* ###################################################################
 **     Filename    : main.c
 **     Project     : IHM
 **     Processor   : MC9S08QE8CLC
 **     Version     : Driver 01.12
 **     Compiler    : CodeWarrior HCS08 C Compiler
 **     Date/Time   : 2018-05-29, 11:18, # CodeGen: 0
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
#include "SCI.h"
#include "SPI.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "bsp.h"
#include "IHM.h"
#include "nrf24.h"

static unsigned char key = ' ';
static unsigned char repeat =0;
unsigned char data_dir[5]={0x7F, 0x7F, 0x00, 0xFF,0x00}; //x, y, kik/sol/rotation, checksum
unsigned short i = 0;
unsigned char tx_address[5] = {0xD7, 0xD7, 0xD7, 0xD7, 0xD7};
unsigned char rx_address[5] = {0xE7, 0xE7, 0xE7, 0xE7, 0xE7};
/* User includes (#include below this line is not maintained by Processor Expert) */

void main(void)
{
	/* Write your local variable definition here */

	unsigned char data_array[4] = {0,0,0,0x00};
	unsigned char dec[3]={0,0,0};

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	nrf24_init();			//Init SPI & Ports
	nrf24_config(2,4);		//Config module radio : channel 2, tableau de 4
	nrf24_tx_address(tx_address);	//Config address Tx
	nrf24_rx_address(rx_address); 	//Config address Rx

	clear_screen();					
	draw_ihm();						

	data_dir[0]=0x7F;						//RaZ du tableau d'envois
	data_dir[1]=0x7F;
	data_dir[2]=0x00;
	data_dir[3]=0xFF;


	for(;;){
		
		nrf24_powerUpRx();			//Mode récéption


		data_array[3]=0;
		i=0;
		while ( (!nrf24_dataReady()) && (i<1000)){	//Attente d'une donnée + Timeout
			i++;
		}
		if (nrf24_dataReady()){
			nrf24_getData(data_array); //Récupération de la donnée
		}
		



		convert(((data_array[0] * 100)/255), dec);	//Conversion de la donnée en décimal
		draw_number(15, 4, dec);					//Affichage du nombre


		status_RF(data_array, 3);					//Vérification de la connection

		//-----------------------------------------------------


		if(SCIS1_RDRF){								//Récupération de la frappe clavier
			key = SCID;
			repeat = 1;								
		}
		if(!repeat){									//Si la touche n'est pas restée
			key = ' ';								//appuyé, RaZ
		}

		move(13, 20);
		putc(key);
		repeat = 0;

		/*----------------------------------------------------- */

		switch (key) {								//Conversion en donnée x,y,...
		case 0x7A: //z
			data_dir[0]=0xFF;
			break;
		case 0x73: //s
			data_dir[0]=0x00;
			break;
		case 0x71: //q
			data_dir[1]=0x00;
			break;
		case 0x64: //d
			data_dir[1]=0xFF;
			break;
		case 0x6B: //k
			data_dir[2]=data_dir[2]|0x01;
			break;
		case 0x6D: //m
			data_dir[2]=data_dir[2]|0x02;
			break;
		case 0x6F: //o
			data_dir[2]=data_dir[2]|0x04;
			break;	 
		case 0x70: //p
			data_dir[2]=data_dir[2]|0x08;
			break;  
		default:
			break;
		} 


		nrf24_send(data_dir);					//Envois du tableau
		while(nrf24_isSending());				//Attente de l'envois
		



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
