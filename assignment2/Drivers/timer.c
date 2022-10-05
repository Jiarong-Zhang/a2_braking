// a1793769 - Emily Zhang
/**
Function implementation for operations related to the C167 timers
**/

#include <reg167.h>
#include "timer.h"

/********** Function Declearations **********/

void timerT6Config(unsigned int prescaler, unsigned int mode, unsigned int direction)
{
	// want to use prescaler == 4
	T6CON |= (prescaler << TIMER_IN_S_BIT);

	// want to use regular timer mode
	T6CON |= (mode << TIMER_MODE_BIT);

	// want to count down
	T6CON |= (direction << COUNT_DIR_BIT);
	
}

void timerT6StartMS(unsigned int ms)
{
	unsigned int T6I = 0;
	unsigned int value = 0;
	float percentage = 0;
	float period = 0;

	// get period based on input selection (T6CON[2:0])
	T6I = (T6CON & 0x07);

	switch (T6I) {
		case 000:
			period = 13.0;
			break;
	}

	// calculate usage percentage
	percentage = ms / period;

	// calculate inital value
	value = percentage * 0xFFFF;

	// load inital value
	T6 = value;

	T6CON |= (TIMER_ON << TIMER_START_BIT);
}