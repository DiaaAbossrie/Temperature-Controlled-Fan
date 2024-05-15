/*-----------------------------------------------------------------------------
 * Module Name: LM35 Temperature Sensor Control
 *
 * File Name: lm35_sensor.c
 *
 * Description: Source file for LM35 temperature sensor module. Contains
 *              function to read temperature from LM35 sensor.
 *
 * Author: Diaa Abossrie
 *-----------------------------------------------------------------------------*/

#include "lm35_sensor.h"  // Include LM35 sensor header file
#include <util/delay.h>   // Include delay header file for time delay functions
#include <avr/io.h>       // Include AVR IO header file for register access

// Function to get temperature from LM35 sensor
uint8 LM35_getTemperature(void)
{
    uint8 temp_value = 0;

    // Read ADC value from sensor channel
    ADC_READ(SENSOR_CHANNEL_ID);

    // Delay for stabilization of the ADC reading
    _delay_ms(5);

    // Calculate temperature value from ADC reading
    temp_value = (uint8)(((uint32) ADC * SENSOR_MAX_TEMPERATURE * ADC_REF_VOLT_VALUE)\
            /(ADC_MAXIMUM_VALUE * SENSOR_MAX_VOLT_VALUE));

    return temp_value;
}
