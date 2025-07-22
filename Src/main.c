
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal Timer Interrupt Driver implementation
 * Toggle User LED6 at a configurable delay generated using Timer 2
 * The delay can be configured in Hz or in seconds
 *  Example :
 * Timer2_init(10, 's') toggle the led every 10 seconds
 *  Timer2_init(10, 'h') toggle the led at 10 hz (1/10 seconds)
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "Timer.h"

static void TIM2_callback(void);

int main(void) {


	GPIOD_init();

	Timer2_Interrupt_init(2, 'h');

	while (1) {


	}


}


// static so that it can be only accessed here

static void TIM2_callback(void) {


	// toggle PD15

	GPIOD->ODR ^= (1U << LED_PIN );


}


void TIM2_IRQHandler(void) {


	//check if counting is done

     if (TIM2->SR & SR_UIF) {

    	 // clear flag

    	 TIM2->SR &= ~SR_UIF;

    	// do something

    	 TIM2_callback();


     }


}

