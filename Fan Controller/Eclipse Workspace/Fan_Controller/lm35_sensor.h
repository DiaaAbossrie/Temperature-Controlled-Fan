/*-----------------------------------------------------------------------------
 * Module Name: LM35 Temperature Sensor Control
 *
 * File Name: lm35_sensor.h
 *
 * Description: Header file for LM35 temperature sensor module. Contains
 *              function prototypes and definitions related to LM35 sensor
 *              operations.
 *
 * Author: Diaa Abossrie
 *-----------------------------------------------------------------------------*/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"  // Include standard data types header file
#include "ADC.h"        // Include ADC header file for analog-to-digital conversion

#define SENSOR_CHANNEL_ID         CH2_ID           // Define ADC channel for LM35 sensor
#define SENSOR_MAX_VOLT_VALUE     1.5              // Define maximum voltage of the sensor
#define SENSOR_MAX_TEMPERATURE    150              // Define maximum temperature value

// Function to get temperature from LM35 sensor
uint8 LM35_getTemperature(void);

#endif
