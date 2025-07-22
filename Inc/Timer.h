#ifndef TIMER_H_
#define TIMER_H_

void Timer2_init(int Prescaler, char SecOrFreq);

void Timer2_Interrupt_init(int Prescaler, char SecOrFreq) ;

void GPIOD_init(void);

void LED_Toggle (void);

#define LED_PIN       15

#define SR_UIF    	(1U << 0)


#endif /* TIMER_H_ */
