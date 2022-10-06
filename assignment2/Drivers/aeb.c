// a1793769 - Emily Zhang
/**
Implementation for AEB functions
**/
#include "Drivers/aeb.h"
#include "Drivers/gpio.h"
#include "Drivers/timer.h"


void aebInit(void)
{
	setPinDirectionP2(AEB_WARNING_PIN, OUTPUT);
	setPinDirectionP2(AEB_INPUT_PIN, INPUT);
	// don't need to set pin dir of P5 pins
	// as they are read-only

	// setup timer T3 (to be used as a 4 second timer)
	timerT3Config(GPT_1_PRESC_1024, TIMER_MODE, COUNT_DOWN);
}

unsigned int aebRead(void)
{
	return readPinP2(AEB_INPUT_PIN);
}

void aebWarning(void)
{
	setPinP2(11);

	// at 20MHz, the longest time we could wait on GPT1 is 3.36 seconds
	timerT3StartS(4);

}