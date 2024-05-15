/*-----------------------------------------------------------------------------
 * Module Name: ADC (Analog-to-Digital Converter) Control
 *
 * File Name: adc.c
 *
 * Description: Source file for ADC module. Contains functions to initialize
 *              and read from ADC.
 *
 * Author: Diaa Abossrie
 *-----------------------------------------------------------------------------*/

#include "avr/io.h"          // Include AVR IO header file for register access
#include "adc.h"             // Include ADC header file for function prototypes
#include "common_macros.h"   // Include common macros header file for bit manipulation

void ADC_init(const ADC_ConfigType * Ptr_config)
{
    // Set reference voltage bits in ADMUX register
    ADMUX = (ADMUX & 0x3F) | ((Ptr_config->ref_volt)<<7);

    // Enable ADC by setting ADEN bit in ADCSRA register
    SET_BIT(ADCSRA,ADEN);

    // Set ADC prescaler bits in ADCSRA register
    ADCSRA = (ADCSRA & 0xF8) | (Ptr_config->prescaler & 0x07);
}

uint16 ADC_READ(uint8 channel_num)
{
    // Set channel bits in ADMUX register
    ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);

    // Start conversion by setting ADSC bit in ADCSRA register
    SET_BIT(ADCSRA,ADSC);

    // Wait for conversion to complete
    while(BIT_IS_CLEAR(ADCSRA,ADIF));

    // Clear ADIF flag
    SET_BIT(ADCSRA,ADIF);

    // Return ADC value
    return ADC;
}
