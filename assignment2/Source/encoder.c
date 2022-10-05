// a1793769 - Emily Zhang
/**
Implementation of encoder calculations
**/

#include <reg167.h>
#include "encoder.h"

/********** Function Declearations **********/

float encoderGetVelocity(void)
{
	float raw_encoder_output = 0;
	float interpolated_result = 0;

	raw_encoder_output = adcRead(ENCODER_PIN, FIXED_SINGLE);

	interpolated_result = raw_encoder_output * ENCODER_STEP_SIZE;

	return interpolated_result;
}