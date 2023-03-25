/*
 ================================================================================================
 Name        : Mini project3.c
 Author      : Baraa Ahmed
 Description : Test  Fan Controller system with polling technique using LM35 Temperature Sensor
 Date        : 10/10/2022
 ================================================================================================
 */

#include"lcd.h"
#include"adc.h"
#include"lm35_sensor.h"
#include"gpio.h"
#include "motor.h"

int main(void){
	/*get temprature value from LM35_getTemperature()*/
	uint8 temp;
	/* Create configuration structure for DCMOTOR driver */
	DcMotor_State DCMOTOR_Config;
	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Config = {Internal,Prescaler_8};
	/* initialize LCD driver */
	LCD_init();
	/* initialize ADC driver */
	ADC_init(&ADC_Config);
	/* initialize DcMOTOR driver */
	DcMOTOR_init();
	/* Display this string "Fan is " only once on LCD at the first row */
	LCD_displayStringRowColumn(0,3,"Fan is ");

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayStringRowColumn(1,3,"Temp =    C");

	while(1){
		/*get temperature frm lm35 sensr*/
		temp=LM35_getTemperature();

		if(temp>=120){
			/* Display the Fan speed value every time at same position */
			/*Display this string refer to fan speed*/
			LCD_displayStringRowColumn(0,10,"100%");
			/*set motor state*/
			DCMOTOR_Config=CW;
			DcMOTOR_Rotate(DCMOTOR_Config,100);

		}
		else if(temp>=90){
			/* Display the Fan speed value every time at same position */
			/*Display this string refer to fan speed*/
			/*set motor state*/
			DCMOTOR_Config=CW;
			DcMOTOR_Rotate(DCMOTOR_Config,75);
		}
		else if(temp>=60){
			/* Display the Fan speed value every time at same position */
			/*Display this string refer to fan speed*/
			LCD_displayStringRowColumn(0,10,"50%");;
			/*set motor state*/
			DCMOTOR_Config=CW;
			DcMOTOR_Rotate(DCMOTOR_Config,50);

		}
		else if(temp>=30){
			/* Display the Fan speed value every time at same position */
			/*Display this string refer to fan speed*/
			LCD_displayStringRowColumn(0,10,"25%");
			/*set motor state*/
			DCMOTOR_Config=CW;
			DcMOTOR_Rotate(DCMOTOR_Config,25);

		}
		else if(temp<30){
			/* Display the Fan speed value every time at same position */
			/*Display this string refer to fan speed*/
			LCD_displayStringRowColumn(0,10,"OFF");
			/*set motor state*/
			DCMOTOR_Config=Stop;
			DcMOTOR_Rotate(DCMOTOR_Config,0);
		}


		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,10);

		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}



	}


}
