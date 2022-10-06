// a1793769 - Emily Zhang
/**
Function implementation for operations related to the C167 timers
**/

/* Include required submodules */
#include "timer.h"
#include "Source/platform.h"

// global run counter

unsigned int run_counter = 0;

void T3_interrupt (void) interrupt 0x23
{
	T3R = 0;
	run_counter++;
}
/********** Function Definitions **********/

void timerT6Config(unsigned int prescaler, unsigned int mode, unsigned int direction)
{
	// set prescaler
	T6CON |= (prescaler << TIMER_IN_S_BIT);

	// set timer mode
	T6CON |= (mode << TIMER_MODE_BIT);

	// set count direction
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
		case 0U:
			period = 13.0;
			break;
		case 1U:
			period = 26.0;
			break;
		case 2U:
			period = 52.5;
			break;
		case 3U:
			period = 105.0;
			break;
		case 4U:
			period = 210.0;
			break;
		case 5U:
			period = 420.0;
			break;
		case 6U:
			period = 840.0;
			break;
		case 7U:
			period = 1680.0;
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

void timerT3Config(unsigned int prescaler, unsigned int mode, unsigned int direction)
{
	// set prescaler
	T3CON |= (prescaler << TIMER_IN_S_BIT);

	// set timer mode
	T3CON |= (mode << TIMER_MODE_BIT);

	// set count direction
	T3CON |= (direction << COUNT_DIR_BIT);

}
void timerT3StartS(unsigned int sec)
{
	unsigned int T3I = 0;
	unsigned int value = 0;
	unsigned int runs_reqired = 0;
	float time_left = 0.0;
	float percentage = 0;
	float period = 0;

	// get period based on input selection (T3CON[2:0])
	T3I = (T3CON & 0x07);

	switch (T3I) {
		case 0U:
			period = 0.0262;
			break;
		case 1U:
			period = 0.0525;
			break;
		case 2U:
			period = 0.1050;
			break;
		case 3U:
			period = 0.2100;
			break;
		case 4U:
			period = 0.4200;
			break;
		case 5U:
			period = 0.8400;
			break;
		case 6U:
			period = 1.68;
			break;
		case 7U:
			period = 3.36;
			break;
	}
	
	time_left = sec;
	T3IC = 0x44;
	if (sec > period)
	{
		runs_reqired = sec / period + 1;
		T3 = 0xFFFF;

		while (run_counter < runs_reqired - 1)
		{
			if (T3R == 0)
			{
				T3R = 1;
			}
			
		}
//		T3IC = 0x00;
	time_left = sec - period * run_counter;
	}

	// calculate usage percentage
		percentage = time_left / period;

		// calculate inital value
		value = percentage * 0xFFFF;

		// load inital value
		T3 = value;

		T3CON |= (TIMER_ON << TIMER_START_BIT);

}