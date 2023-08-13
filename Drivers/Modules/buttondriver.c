/*
 * buttondriver.c
 *
 *  Created on: Aug 13, 2023
 *      Author: brknu
 */

#include "stm32l0xx_hal.h"
void buttondriver_init(void){
	RCC -> IOPENR |= (1<<2);

	GPIOC -> MODER &= ~(1<<26);
	GPIOC -> MODER &= ~(1<<27);
}


int buttondriver_get_state(void){

	if(!(GPIOC -> IDR &(1<<13))){
		return 1;
	}
	else{
		return 0;
	}
}
