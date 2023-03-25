 /******************************************************************************
 *
 * Module: Motor driver
 *
 * File Name: motor.h
 *
 * Description: Header file for the motor driver
 *
 * Author: Baraa Ahmed
 *
 *******************************************************************************/


#ifndef MOTOR_H_
#define MOTOR_H_
#include"gpio.h"

#define MOTOR_INPUT1_PORT_ID 		PORTB_ID
#define MOTOR_INPUT1_PIN_ID 		PIN0_ID

#define MOTOR_INPUT2_PORT_ID		PORTB_ID
#define MOTOR_INPUT2_PIN_ID			PIN1_ID

typedef enum{
	Stop,CW,A_CW
}DcMotor_State;

/*The Function responsible for setup the direction for the two
motor pins through the GPIO driver.*/
void DcMOTOR_init(void);

/*The function responsible for rotate the DC Motor CW/ or A-CW or
stop the motor based on the state input state value*/
void DcMOTOR_Rotate(DcMotor_State state,uint8 speed);




#endif /* MOTOR_H_ */
