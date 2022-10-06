// a1793769 - Emily Zhang
/**
 * File name encoder.c
 * Description: Implementation of encoder calculations
**/

/********** Include required submodules**********/

#include <reg167.h>
#include "encoder.h"

/********** Include required submodules**********/

float encoderGetVelocity(void)
{
	float raw_encoder_output = 0;
	float interpolated_result = 0;

	raw_encoder_output = adcRead(ENCODER_PIN, FIXED_SINGLE);

	interpolated_result = raw_encoder_output * ENCODER_STEP_SIZE;

	return interpolated_result;
}