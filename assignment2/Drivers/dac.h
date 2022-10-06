// a1793769 - Emily Zhang
/**
Function declarations for operations related to the DAC 
**/
#ifndef DAC_H
#define DAC_H

#include <reg167.h>
#include "gpio.h"

/********** Macros **********/

// Output to these pins for the DAC
// assuming using pins 0-7
#define DAC_LSB_PIN  0U
#define DAC_MSB_PIN  7U

#define DAC_NUM_BITS 8U

/********** Function Declearations **********/

void dacInit(void);

void dacWrite(unsigned int input);

void dacReset(void);


#endif