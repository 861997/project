/******************************************************************************
 *
 * Module: PWM driver
 *
 * File Name: pwm.h
 *
 * Description: source file for the AVR PWM driver
 *
 * Author: Baraa Ahmed
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_
#include "gpio.h"

#define MOTOR_ENABLE_PORT_ID 		PORTB_ID
#define MOTOR_ENABLE_PIN_ID 		PIN3_ID
/*The function responsible for trigger the Timer0 with the PWM Mode*/
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
