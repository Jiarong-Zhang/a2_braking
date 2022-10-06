// a1793769 - Emily Zhang
/**
 * File name: adc.h
 * Description: Implementation for AEB functions
**/

/********** Include required submodules**********/

#include "Drivers/aeb.h"
#include "Drivers/gpio.h"
#include "Drivers/timer.h"
#include "Drivers/dac.h"

/********** Function Definitions **********/

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
	setPinP2(AEB_WARNING_PIN);
	dacReset();

	timerT3StartS(AEB_WARNING_TIME);
	while (T3R){}	 // wait to finish

	clrPinP2(AEB_WARNING_PIN);

}