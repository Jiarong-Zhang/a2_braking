// a1793769 - Emily Zhang
/**
Function declarations for operations related to the C167 timers
**/
#ifndef TIMER_H
#define TIMER_H

#include <reg167.h>
#include "gpio.h"

/********** Macros **********/

// timer mode controls consistent across GPT1 & 2
#define TIMER_MODE 			0U
#define COUNTER_MODE 		1U
#define GATED_LOW_MODE 		2U
#define GATED_HIGH_MODE 	3U

// GPT2 prescaler factor
#define GPT_2_PRESC_4 		0U

// timer count direction control
#define COUNT_UP 			0U
#define COUNT_DOWN			1U

// timer on/off controls consistent across GPT1 & 2
#define TIMER_OFF	 		0U
#define TIMER_ON 			1U

// timer presclater select bit postion
#define TIMER_IN_S_BIT		0U

// timer mode controls bit postion
#define TIMER_MODE_BIT		3U

// timer on/pff controls bit postion
#define TIMER_START_BIT		6U

// timer count direction bit position
#define COUNT_DIR_BIT 		7U


/********** Function Declearations **********/

// Initialise T6 mode and input selection
// see UM 10-24
// 		Takes arguments: prescaler factor, mode, count direction
//		Returns nothing
//
void timerT6Config(unsigned int prescaler, unsigned int mode, unsigned int direction);

// Start timer T6 for the given time
// 		Takes time to count in milliseconds
//		Returns nothing
//
void timerT6StartMS(unsigned int ms);


#endif