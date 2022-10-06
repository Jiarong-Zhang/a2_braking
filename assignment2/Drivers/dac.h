// a1793769 - Emily Zhang
/**
 * File name: dac.h.h
 * Description: Function declarations for operations related to the DAC
 **/

#ifndef DAC_H
#define DAC_H

/********** Include required submodules**********/

#include "gpio.h"
#include <reg167.h>

/********** Macros **********/

// Output to these pins for the DAC
// assuming using pins 0-7
#define DAC_LSB_PIN 0U
#define DAC_MSB_PIN 7U

#define DAC_NUM_BITS 8U

/********** Function Declearations **********/

// Initialise P2.0 to P2.7 which are connected to
// the DAC
// 		Takes no arguments
//		Returns nothing
//
void dacInit(void);

// Writes given value to the DAC
// the DAC
// 		Takes unsigned int input
//		Returns nothing
//
void dacWrite(unsigned int input);

// Reset DAC output to 0x00
// 		Takes nno arguments
//		Returns nothing
//
void dacReset(void);

#endif