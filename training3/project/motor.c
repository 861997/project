/******************************************************************************
 *
 * Module: Motor driver
 *
 * File Name: motor.c
 *
 * Description: source file for the moter driver
 *
 * Author: Baraa Ahmed
 *
 *******************************************************************************/

#include"motor.h"
#include"gpio.h"
#include"pwm.h"
/*The Function responsible for setup the direction for the two
motor pins through the GPIO driver.*/
void DcMOTOR_init(void){
	/* Configure the direction for N1 and N@ pins as output pins */
	GPIO_setupPinDirection(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT2_PIN_ID,PIN_OUTPUT);
	/*intail stop the motor
	 * write on N1,N2 LOGIC_LOW*/
	GPIO_writePin(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
}
/*The function responsible for rotate the DC Motor CW/ or A-CW or
stop the motor based on the state input state value*/
void DcMOTOR_Rotate(DcMotor_State state,uint8 speed){
	/*calculate duty cycle*/
	uint8 duty=(uint8)((uint32)(speed*255)/100);

	switch(state){
	case Stop :
		GPIO_writePin(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
		break;
	case CW :
		GPIO_writePin(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT1_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
		break;
	case A_CW:
		GPIO_writePin(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT2_PIN_ID,LOGIC_HIGH);
		break;
	}

	PWM_Timer0_Start(duty);


}

