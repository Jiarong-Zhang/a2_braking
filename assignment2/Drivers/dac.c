// a1793769 - Emily Zhang
/**
Function implementations for operations related to the DAC 
**/

#include <reg167.h>
#include "dac.h"

/********** Macros **********/

/********** Function Declearations **********/

void dacInit(void)
{
	int i;
	for (i = 0; i < DAC_NUM_BITS; ++i)
	{
		setPinDirectionP2(i, OUTPUT);
	}
}

void dacWrite(unsigned int input)
{
	P2 |= ((input & 0xFF) << DAC_LSB_PIN);
}

void dacReset(void)
{
	P2 &= ~(0xFF << DAC_LSB_PIN);
}