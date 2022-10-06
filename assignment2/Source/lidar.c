// a1793769 - Emily Zhang
/**
Function implementation for operations related to the LIDAR 
**/

/* Include required submodules */
#include "lidar.h"

/********** Function Definitions **********/

/*void lidarGetDistances (float* array, unsigned int array_size)
{
	float raw_lidar_output = 0;
	float interpolated_result = 0; 
	unsigned int index = 0;
	unsigned int toggle = 0;

	// collect first result
	raw_lidar_output = adcRead(LIDAR_PIN, FIXED_SINGLE);
	interpolated_result = (raw_lidar_output * LIDAR_STEP_SIZE) + 5;
	array[index] = interpolated_result;
	index++;

	// if array not full yet
	while (index < (array_size))
	{
		// wait 10ms before collect next distance
		timerT6StartMS(10);
		while(T6OTL == toggle){}
		toggle = !toggle;
		T6R = 0;

		// collect/calculate lidar distance
		raw_lidar_output = adcRead(LIDAR_PIN, FIXED_SINGLE);
		interpolated_result = (raw_lidar_output * LIDAR_STEP_SIZE) + 5;

		// store distance
		array[index] = interpolated_result;
		index++;
	}

	return;
}*/

/*float* lidarSetupBuffer(void)
{
	float distance_buffer[BUFFER_SIZE] = {0};

	return &distance_buffer;
}*/

void lidarT6Interrupt (void) interrupt 0x26
{
	T6R = 0;	// stop timer T6
	g_wait_flag = 0;	// lower flag, indicate "take next measurement!"
}
void lidarTimerInit(void)
{
	timerT6Config(GPT_2_PRESC_4, TIMER_MODE, COUNT_DOWN);
	timerT6EnableInterrupt();
}

float lidarGetResult(void)
{
	float raw_lidar_output = 0;
	float interpolated_result = 0; 

	// collect and return result
	raw_lidar_output = adcRead(LIDAR_PIN, FIXED_SINGLE);
	interpolated_result = (raw_lidar_output * LIDAR_STEP_SIZE) + 5;
	
	return interpolated_result;
}

void lidarUpdateBuffer(void)
{
	float lidar_result = lidarGetResult();

	interruptDisable(); // disable interrupts for now
	pop_front(g_dist_buffer, BUFFER_SIZE);
	push_back(g_dist_buffer, BUFFER_SIZE, lidar_result);
	g_wait_flag = 1;		// raise flag, indicates "measurement taken"

	interruptEnable(); // re-enable interrupts
	
	timerT6StartMS(10);		// start 10ms timer
}
