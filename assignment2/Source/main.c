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
#include "platform.h"
#include "Drivers/interrupt.h"
#include "encoder.h"
#include "lidar.h"
#include "calculations.h"
#include <reg167.h>

volatile unsigned int wait_flag = 0;

void main(void)
{
	volatile float distance_buffer[BUFFER_SIZE] = {0xFFFF};
	volatile float result = 0;
	volatile unsigned int ready_flag = 0;
	volatile float buffer[BUFFER_SIZE] = {0};
	

	interruptEnable();
	wait_flag = 0;
	aebInit(); 
	adcGpioInit();
	dacInit();
	lidarTimerInit();
	
	while(1)
	{
		ready_flag = aebRead();
		if (ready_flag == 1)
		{
			if (wait_flag == 0)
			{
				interruptDisable(); // disable interrupts for now
				lidarUpdateBuffer(buffer);
				calculationsHandler(buffer);
				interruptEnable(); // re-enable interrupts
				wait_flag = 1;
				timerT6StartMS(10);
			}
		}
 	}
}
