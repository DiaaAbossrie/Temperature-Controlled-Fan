/*-----------------------------------------------------------------------------
 * Module Name: Application
 *
 * File Name: app.c
 *
 * Description: Source file for the application. This file contains the main
 *              function which controls the behavior of the system.
 *
 * Author: Diaa Abossrie
 *-----------------------------------------------------------------------------*/

#include "lcd.h"             // Include LCD header file for display operations
#include "lm35_sensor.h"     // Include LM35 sensor header file for temperature readings
#include "dc_motor.h"        // Include DC motor header file for fan control
#include "ADC.h"             // Include ADC header file for analog-to-digital conversion

uint16 temprature=10;        // Initialize temperature variable
uint16 speed=10;             // Initialize fan speed variable

int main(){

    LCD_init();             // Initialize LCD display
    DcMotor_Init();         // Initialize DC motor

    // Configure ADC for internal reference voltage and prescaler of 8
    ADC_ConfigType ADC_configrations = {INTERNAL,PRESCALER_8};
    ADC_init(&ADC_configrations);   // Initialize ADC with configured settings

    temprature = LM35_getTemperature();  // Get initial temperature reading

    // Display initial information on the LCD
    LCD_displayStringRowColumn(0,4,"FAN IS OFF");
    LCD_displayStringRowColumn(1,4,"TEMP = ");
    LCD_intgerToString(temprature);
    DcMotor_Rotate(STOP,0);  // Turn off the fan initially

    while(1){

        temprature = LM35_getTemperature();  // Read current temperature

        if(temprature>=30 && temprature<60){

            // Display fan status and temperature on the LCD
            LCD_displayStringRowColumn(0,4,"FAN IS ON ");
            LCD_displayStringRowColumn(1,4,"TEMP = ");
            LCD_intgerToString(temprature);
            LCD_displayCharacter(' ');

            // Rotate the fan in Clockwise direction with speed 25%
            DcMotor_Rotate(CW,25);
        }
        else if(temprature>=60 && temprature<90){

            // Display fan status and temperature on the LCD
            LCD_displayStringRowColumn(0,4,"FAN IS ON ");
            LCD_displayStringRowColumn(1,4,"TEMP = ");
            LCD_intgerToString(temprature);
            LCD_displayCharacter(' ');

            // Rotate the fan in Clockwise direction with speed 50%
            DcMotor_Rotate(CW,50);
        }
        else if(temprature>=90 && temprature<120){

            // Display fan status and temperature on the LCD
            LCD_displayStringRowColumn(0,4,"FAN IS ON ");
            LCD_displayStringRowColumn(1,4,"TEMP = ");
            LCD_intgerToString(temprature);
            LCD_displayCharacter(' ');

            // Rotate the fan in Clockwise direction with speed 75%
            DcMotor_Rotate(CW,75);
        }
        else if(temprature>=120){

            // Display fan status and temperature on the LCD
            LCD_displayStringRowColumn(0,4,"FAN IS ON ");
            LCD_displayStringRowColumn(1,4,"TEMP = ");
            LCD_intgerToString(temprature);

            // Rotate the fan in Clockwise direction with maximum speed (100%)
            DcMotor_Rotate(CW,100);
        }
        else
        {
            // Display fan status and temperature on the LCD
            LCD_displayStringRowColumn(0,4,"FAN IS OFF");
            LCD_displayStringRowColumn(1,4,"TEMP = ");
            LCD_intgerToString(temprature);
            LCD_displayCharacter(' ');

            // Turn off the fan
            DcMotor_Rotate(STOP,0);
        }

    }

}
