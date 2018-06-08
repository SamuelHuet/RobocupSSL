/*
 * bsp.c
 *
 *  Created on: Oct 6, 2017
 *      Author: Cocasticox
 */
#include "bsp.h"


void move(unsigned char x, unsigned char y)
{
 putc(VT100_ESC);
 putc('[');
 putc('0' + (y / 100));
 putc('0' + ((y / 10) % 10));
 putc('0' + (y % 10));
 putc(';');
 putc('0' + (x / 100));
 putc('0' + ((x / 10) % 10));
 putc('0' + (x % 10));
 putc('H');
}
void clear_screen(void)
{
 putc(VT100_ESC);
 putc('[');
 putc('2');
 putc('J');
 putc(VT100_ESC);
 putc('[');
 putc('?');
 putc('2');
 putc('5');
 putc('l');
}
void delay(unsigned long delay)
{
 unsigned long i; 
 for (i=0; i <= delay; i++);
}

unsigned char input_SCI(void){
	if(SCIS1_RDRF){
		return SCID;
	}
}


