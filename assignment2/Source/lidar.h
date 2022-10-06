// a1793769 - Emily Zhang
/**
Function declarations for operations related to the LIDAR 
**/
#ifndef LIDAR_H
#define LIDAR_H

/* Include required submodules */
#include <reg167.h>
#include "buffer.h"
#include "Drivers/adc.h"
#include "Drivers/timer.h"
#include "Drivers/interrupt.h"
#include "platform.h"

/********** Macros **********/
// LIDAR pin
#define LIDAR_PIN	 		2U

#define LIDAR_STEP_SIZE 	0.3076f 	// 315/2^10 = 0.3076 (4 d.p.)
#define LIDAR_STEP_CONSTANT 5U 			// 0-5V -> 5-320m => 0-5V -> (0-315m)+ 5m

/********** Function Declearations **********/

void lidarTimerInit(void);

void lidarUpdateBuffer(void);

float lidarGetResult(void);

//float* lidarSetupBuffer(void);

#endif