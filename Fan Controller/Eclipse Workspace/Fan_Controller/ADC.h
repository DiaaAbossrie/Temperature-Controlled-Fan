/*-----------------------------------------------------------------------------
 * Module Name: ADC (Analog-to-Digital Converter) Control
 *
 * File Name: adc.h
 *
 * Description: Header file for ADC module. Contains function prototypes and
 *              definitions related to ADC operations.
 *
 * Author: Diaa Abossrie
 *-----------------------------------------------------------------------------*/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"  // Include standard data types header file

// Define maximum ADC value and reference voltage
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

// Define ADC channel IDs
#define CH0_ID 0
#define CH1_ID 1
#define CH2_ID 2
#define CH3_ID 3
#define CH4_ID 4
#define CH5_ID 5
#define CH6_ID 6
#define CH7_ID 7

extern volatile uint16 ADC_value; // External declaration of ADC_value

// Enumeration for ADC reference voltage selection
typedef enum{
    AREF,       // External reference voltage at AREF pin
    AVCC,       // Internal reference voltage (AVcc)
    RESERVED,   // Reserved value
    INTERNAL    // Internal reference voltage (1.1V)
}ADC_ReferanceVoltage;

// Enumeration for ADC prescaler selection
typedef enum{
    NO_PRESCALER,  // No division of the system clock
    PRESCALER_2,   // System clock divided by 2
    PRESCALER_4,   // System clock divided by 4
    PRESCALER_8,   // System clock divided by 8
    PRESCALER_16,  // System clock divided by 16
    PRESCALER_32,  // System clock divided by 32
    PRESCALER_64,  // System clock divided by 64
    PRESCALER_128  // System clock divided by 128
}ADC_Prescaler;

// Structure to hold ADC configuration settings
typedef struct{
    ADC_ReferanceVoltage  ref_volt;  // Reference voltage selection
    ADC_Prescaler prescaler;        // Prescaler selection
}ADC_ConfigType;

// Function to initialize the ADC
void ADC_init(const ADC_ConfigType * Ptr_config);

// Function to read ADC value from a specific channel
uint16 ADC_READ(uint8 channel_num);

#endif
