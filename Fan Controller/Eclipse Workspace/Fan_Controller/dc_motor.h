/*-----------------------------------------------------------------------------
 * Module Name: DC Motor Control
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for DC motor control module.
 *
 * Author: Diaa Abossrie
 *-----------------------------------------------------------------------------*/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "gpio.h"     // Include GPIO header file for pin operations
#include "std_types.h" // Include standard data types header file for data types
#include "pwm.h"      // Include PWM header file for motor speed control

#define PORT_ID PORTB_ID // Define PORT_ID as PORTB_ID for motor control

#define PINA_ID PIN0_ID  // Define PINA_ID as PIN0_ID for one motor terminal
#define PINB_ID PIN1_ID  // Define PINB_ID as PIN1_ID for the other motor terminal

// Define an enumeration type DcMotor_State to represent motor states
typedef enum{
    CW,    // Clockwise rotation
    A_CW,  // Anti-clockwise rotation
    STOP   // Motor stop
}DcMotor_State;

// Function to initialize the DC motor
void DcMotor_Init(void);

// Function to control the DC motor rotation
void DcMotor_Rotate(DcMotor_State state, uint16 speed);

#endif
