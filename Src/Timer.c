
#include "stm32f4xx.h"
#include "Timer.h"


#define CR1_CEN   				(1U << 0)

#define CR1_DIR   				(1U << 4)

#define SR_UIF    				(1U << 0)

#define GPIOD_EN                (1U <<3)

#define GPIOD_MODER_1           (1U << 30)

#define GPIOD_MODER_2            (1U << 31)

#define TIM2EN                   (1U << 0)

#define SysCLCK                  16000000UL

#define DIER_UIE                 (1U << 0)

void Timer2_Interrupt_init(int Prescaler, char SecOrFreq) {

	uint32_t Preload_VAL = 0, Timer_Prescaler = 0;

	Timer_Prescaler = 1600;

	// disable global interrupts

	  __disable_irq();

	// Enable clock acess to timer 2

	RCC->APB1ENR |= TIM2EN  ;

    // set Timer prescaler to 2 ; CK_CNT (counter clock frequency ) = Timer peripheral clock /(PSC+1)


	 TIM2->PSC =  Timer_Prescaler -1 ; // 16 000 000 / 1600 --> 10 000

	// Enable Upcounting mode :  CR1_DIR

	 TIM2->CR1 |= CR1_DIR;

	// read the preload value

	 if (SecOrFreq == 'h' ) {

		 Preload_VAL =  ( SysCLCK/Timer_Prescaler)/ Prescaler  ;

	 }

	 if (SecOrFreq == 's' ) {

			 Preload_VAL =  Prescaler * ( SysCLCK/Timer_Prescaler)  ;

		 }

	 TIM2->ARR = Preload_VAL - 1;

     // clear counter

	 TIM2->CNT = 0;

	 // enable interrupt

	 TIM2->DIER |= DIER_UIE ;

	 // Enable TIM2 interrupt in NVIC

	  NVIC_EnableIRQ(TIM2_IRQn);

	  // enable global interrupts

	  __enable_irq();

	// Enable counter TIMx_CR1 : CEN bit

    TIM2->CR1 |= CR1_CEN ;

}

void GPIOD_init(void){

	// enable clock access to port D

	RCC->AHB1ENR |= GPIOD_EN ;

	// set PD15 mode to output

   GPIOD->MODER |=  GPIOD_MODER_1 ;

   GPIOD->MODER &=  ~GPIOD_MODER_2 ;

}

