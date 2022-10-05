// a1793769 - Emily Zhang
/**
Implementation for AEB functions
**/
#include "Drivers/aeb.h"
#include "Drivers/gpio.h"


void aebInit(void)
{
	setPinDirectionP2(AEB_WARNING_PIN, OUTPUT);
	setPinDirectionP2(AEB_INPUT_PIN, INPUT);
	// don't need to set pin dir of P5 pins
	// as they are read-only
}

unsigned int aebRead(void)
{
	return readPinP2(AEB_INPUT_PIN);
}

void aebWarning(void)
{
	setPinP2(11);
}