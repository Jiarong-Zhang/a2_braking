// a1793769 - Emily Zhang
/**
Function declarations for operations related to the encoder 
**/
#ifndef ENCODER_H
#define ENCODER_H

#include <reg167.h>
#include "Drivers/adc.h"

/********** Macros **********/
// Encoder pin
#define ENCODER_PIN 		1U

#define ENCODER_STEP_SIZE 	0.1074f // 110/2^10 = 0.1074 (4 d.p.)

/********** Function Declearations **********/

// Calculates the current angular velocity
// using the analogue reading from the encoder
// 		Takes no arguments
//		Returns angular velocity as a float
//
float encoderGetVelocity(void);

#endif