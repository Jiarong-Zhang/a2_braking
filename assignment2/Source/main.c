// a1793769 - Emily Zhang
/*
Main function that controls the flow of the entire
subsystem
*/

/* Include required submodules */
#include "Drivers/aeb.h"
#include "Drivers/adc.h"
#include "Drivers/timer.h"
#include "Drivers/platform.h"
#include "encoder.h"
#include "lidar.h"
#include "calculations.h"
#include <reg167.h>

/* Preprocessor operations */
volatile unsigned int wait_flag; // needs to be globals, used by interrupt

void timer_interrupt (void) interrupt 0x26
{
	T6R = 0;
	wait_flag = 0;
}

void main(void)
{
	// volatile float distance_buffer[BUFFER_SIZE] = {0xFFFF};
	volatile float result = 0;
	volatile unsigned int ready_flag = 0;
	volatile float buffer[BUFFER_SIZE] = {0};

	T6IC = 0x0044;
	IEN = 1;
	wait_flag = 0;
	
	aebInit(); 
	adcGpioInit();
	timerT6Config(GPT_2_PRESC_4, TIMER_MODE, COUNT_DOWN);
	
	while(1)
	{
		ready_flag = aebRead();
		if (ready_flag == 1)
		{
			if (wait_flag == 0)
			{
				IEN = 0; // disable interrupts for now
				
				// result = lidarGetResult();
				// push_back(distance_buffer, BUFFER_SIZE, result);
				lidarUpdateBuffer(buffer);

				calculationsHandler(buffer);
				IEN = 1; // re-enable interrupts
				wait_flag = 1;
				timerT6StartMS(10);
			}
		}
 	}
}
