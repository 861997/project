/******************************************************************************
 *
 * Module: ADC driver
 *
 * File Name: adc.c
 *
 * Description: source file for the AVR ADC driver
 *
 * Author: Baraa Ahmed
 *
 *******************************************************************************/

#include <avr/io.h> /* To use ADC registers */
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "adc.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr){
	/* ADMUX Register Bits Description:
	 * REFS7:6 = insert the required reference voltage value in the last two bits (REFS1 & REFS0)
	 *           of ADMUX Register
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX=(ADMUX & 0x3f)| ((Config_Ptr->ref_volt)<<6);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = insert the required clock value in the first three bits (ADPS2 ,ADPS1 & ADPS0)
	 * of ADCSRA Register ADC_Clock = F_CPU/N  --> ADC must operate in range 50-200Khz
	 */
	ADCSRA=(ADCSRA & 0xf8)|(Config_Ptr->prescaler)|(1<<ADEN);

}
uint16 ADC_readChannel(uint8 channel_num){
	/* Input channel number must be from 0 --> 7 */
	/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel  */
	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX=(channel_num &0x07)|(ADMUX & 0xe0);
	/* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA,ADSC);
	//ADCSRA|=(1<<ADSC);
	/* Wait for conversion to complete, ADIF becomes '1' */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	/* Clear ADIF by write '1' to it :) */
	SET_BIT(ADCSRA,ADIF);
	/*another way but don't forget the |*/
	//ADCSRA|=(1<<ADIF);
	/* Read the digital value from the data register */
	return ADC;
}



