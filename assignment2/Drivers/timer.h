// a1793769 - Emily Zhang
/**
Function declarations for operations related to the C167 timers
**/
#ifndef TIMER_H
#define TIMER_H

/* Include required submodules */
#include <reg167.h>
#include "gpio.h"

/********** Macros **********/

// GPT1 prescaler factors
#define GPT_1_PRESC_8 		0U
#define GPT_1_PRESC_16 		1U
#define GPT_1_PRESC_32 		2U
#define GPT_1_PRESC_64 		3U
#define GPT_1_PRESC_128 	4U
#define GPT_1_PRESC_256 	5U
#define GPT_1_PRESC_512 	6U
#define GPT_1_PRESC_1024 	7U

// GPT2 prescaler factors
#define GPT_2_PRESC_4 		0U
#define GPT_2_PRESC_8 		1U
#define GPT_2_PRESC_16 		2U
#define GPT_2_PRESC_32 		3U
#define GPT_2_PRESC_64		4U
#define GPT_2_PRESC_128		5U
#define GPT_2_PRESC_256		6U
#define GPT_2_PRESC_512		7U

// timer mode controls consistent across GPT1 & 2
#define TIMER_MODE 			0U
#define COUNTER_MODE 		1U
#define GATED_LOW_MODE 		2U
#define GATED_HIGH_MODE 	3U

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

// Initialise T3 mode and input selection
// see UM 10-3
// 		Takes arguments: prescaler factor, mode, count direction
//		Returns nothing
//
void timerT3Config(unsigned int prescaler, unsigned int mode, unsigned int direction);

// Start timer T3 for the given time
// 		Takes time to count in seconds
//		Returns nothing
//
void timerT3StartS(unsigned int sec);


#endif