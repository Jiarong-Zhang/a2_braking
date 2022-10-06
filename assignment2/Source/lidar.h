// a1793769 - Emily Zhang
/**
 * File name lidar.c
 * Description: Function declarations for operations related to the LIDAR
 **/

#ifndef LIDAR_H
#define LIDAR_H

/********** Include required submodules**********/
#include "Drivers/adc.h"
#include "Drivers/interrupt.h"
#include "Drivers/timer.h"
#include "buffer.h"
#include "platform.h"
#include <reg167.h>

/********** Macros **********/

// LIDAR pin
#define LIDAR_PIN 2U

#define LIDAR_STEP_SIZE 0.3076f // 315/2^10 = 0.3076 (4 d.p.)
#define LIDAR_STEP_CONSTANT 5U  // 0-5V -> 5-320m => 0-5V -> (0-315m)+ 5m

/********** Function Declearations **********/

// Initialise the s timer used by this module
// 		Takes no arguments
//		Returns nothing
//
void lidarTimerInit(void);

// Returns latest LIDAR measurement after
// interpolation
// 		Takes no arguments
//		Returns float result
//
float lidarGetResult(void);

// Update global distances buffer
// 		Takes no arguments
//		Returns nothing
//
void lidarUpdateBuffer(void);

#endif