/******************************************************************************
 *
 * Module: PWM driver
 *
 * File Name: pwm.c
 *
 * Description: source file for the AVR PWM driver
 *
 * Author: Baraa Ahmed
 *
 *******************************************************************************/
#include"pwm.h"
#include<avr/io.h>
/*The function responsible for trigger the Timer0 with the PWM Mode*/
void PWM_Timer0_Start(uint8 duty_cycle){
	/*non_inverting , prescaler=8*/
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<CS01)|(1<<COM01);
	/*intial timer from zero*/
	TCNT0=0;
	/*compare value*/
	OCR0=duty_cycle;
	/* Configure the direction for Enable pin as output pin */
	GPIO_setupPinDirection(MOTOR_ENABLE_PORT_ID,MOTOR_ENABLE_PIN_ID,PIN_OUTPUT);
}
