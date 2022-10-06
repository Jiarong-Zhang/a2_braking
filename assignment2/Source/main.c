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

/********** Extern Definitions **********/
volatile unsigned int g_wait_flag = 0;
volatile float g_dist_buffer[BUFFER_SIZE] = {0};

void main(void)
{
	volatile unsigned int result = 0;
	volatile unsigned int ready_flag = 0;
	
	interruptEnable();
	g_wait_flag = 0;
	aebInit(); 
	dacInit();
	adcGpioInit();
	lidarTimerInit();

	while(1)
	{
		ready_flag = aebRead();
		if (ready_flag == 1)
		{
			if (g_wait_flag == 0)		// only update if flag is lowered
			{
				lidarUpdateBuffer();	// update buffer
			}
			calculationsHandler();
			result = (P2 & 0xFF);
		}
 	}
}
