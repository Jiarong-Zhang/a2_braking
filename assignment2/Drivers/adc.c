// a1793769 - Emily Zhang
/**
Function implementations for operations related to the C167 ADC
**/

#include "Drivers/adc.h"

void adcGpioInit(void)
{
	configPinP5(ENCODER_PIN, ANALOGUE);
	configPinP5(LIDAR_PIN, ANALOGUE);
}

void adcReset(void)
{
	// TBD
	ADCON = 0x0000;
}

unsigned int adcCheckBusy(void)
{
	if (ADCON & (1 << BUSY_BIT))
	{
		return 1;
	}
	else
	{
		return 0;
	} 
}

float adcRead(unsigned int channel, unsigned int mode)
{
	float result;
	
	// set conversion channel
	ADCON |= (channel << CH_BIT);

	// set conversion mode
	ADCON |= (mode << MODE_BIT);

	// start conversion 
	ADCON |= (ADC_ON << START_BIT);

	// wait
	while (adcCheckBusy()){}

	// once no longer busy, grab result
	result = (ADDAT &= 0x3FF);

	adcReset();

	return result;
}