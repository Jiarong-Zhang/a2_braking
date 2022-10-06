// a1793769 - Emily Zhang
/**
 * File name: aeb.h
 * Description: Function declarations for operations related to the AEB
 **/

#ifndef AEB_H
#define AEB_H

/********** Include required submodules**********/

#include "gpio.h"
#include <reg167.h>

/********** Macros **********/

#define AEB_WARNING_PIN 11U
#define AEB_INPUT_PIN 15U
#define AEB_WARNING_TIME 4U // in seconds

/********** Function Declearations **********/

// Initialise P2.11 & P2.15, used in communication with
// the AEB
// 		Takes no arguments
//		Returns nothing
//
void aebInit(void);

// Read the signal at P2.15, which is connected to the
// the AEB
// 		Takes no arguments
//		Returns value read
//
unsigned int aebRead(void);

// Set 'warning' signal high to the AEB for 4 seconds
// 		Takes no arguments
//		Returns nothing
//
void aebWarning(void);

#endif