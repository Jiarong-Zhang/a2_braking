// a1793769 - Emily Zhang
/*
Main function that controls the flow of the entire
subsystem
*/

/* Include required submodules */
#include "Drivers/aeb.h"
#include "Drivers/adc.h"
#include "Drivers/dac.h"
#include "Drivers/timer.h"
#include "Drivers/platform.h"
#include "encoder.h"
#include "lidar.h"
#include "calculations.h"
#include <reg167.h>

/* Preprocessor operations */
volatile unsigned int wait_flag; // needs to be global, used by interrupt & main

void timer_interrupt (void) interrupt 0x26
{
	T6R = 0;	// stop timer T6
	wait_flag = 0;
}

void main(void)
{
	// volatile float distance_buffer[BUFFER_SIZE] = {0xFFFF};
	volatile float result = 0;
	volatile unsigned int ready_flag = 0;
	volatile float buffer[BUFFER_SIZE] = {0};

	IEN = 1;
	wait_flag = 0;
	aebInit(); 
	adcGpioInit();
	dacInit();
	lidarTimerInit();
	timerT3StartS(6);

//	dacWrite((unsigned int)(1000 * DAC_SCALE_FACTOR));
	
	while(1)
	{
		ready_flag = aebRead();
		if (ready_flag == 1)
		{
			if (wait_flag == 0)
			{
				IEN = 0; // disable interrupts for now
				lidarUpdateBuffer(buffer);
				calculationsHandler(buffer);
				result = P2 & 0xFF;
				IEN = 1; // re-enable interrupts
				wait_flag = 1;
				timerT6StartMS(10);
			}
		}
 	}
}
