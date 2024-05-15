/*-----------------------------------------------------------------------------
 * Module Name: PWM (Pulse Width Modulation) Control
 *
 * File Name: pwm.h
 *
 * Description: Header file for PWM module. Contains function prototypes and
 *              definitions related to PWM operations using Timer0.
 *
 * Author: Diaa Abossrie
 *-----------------------------------------------------------------------------*/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"  // Include standard data types header file
#include "gpio.h"       // Include GPIO header file for pin operations

// Function to start PWM using Timer0
void PWM_Timer0_Start(uint8 duty_cycle);

#endif
