// a1793769 - Emily Zhang
/**
 * File name: adc.h
 * Description: Function declarations for operations related to the C167 ADC
**/

#ifndef ADC_H
#define ADC_H

/********** Include required submodules**********/

#include <reg167.h>
#include "gpio.h"

/********** Macros **********/

// Pin numbers of the encoder and lidar
#define ENCODER_PIN 	 1U
#define LIDAR_PIN 		 2U

// ADC mode selection
#define FIXED_SINGLE 	0U
#define FIXED_CONTIN 	1U
#define AUTO_SINGLE  	2U
#define AUTO_CONTIN  	3U

// ADC start control
#define ADC_OFF  		 0U
#define ADC_ON			 1U

// ADC channel select bit position
#define CH_BIT  	 0U

// ADC mode select bit position
#define MODE_BIT	 4U

// ADC start bit bit position
#define START_BIT	 7U

// ADC busy flag position
#define BUSY_BIT	 8U

// Port 5 digital input control 
#define DIGITAL  	 0U
#define ANALOGUE	 1U


/********** Function Declearations **********/

// Configure P5DIDIS of the the encoder and LIDAR input pin, 
// used as analogue signals that can be converted by the ADC.(UM 7-34)
// 		Takes no arguments
//		Returns nothing
//
void adcGpioInit(void);

// Initialise ADC channels and modes
// 		Takes no arguments
//		Returns nothing
//
void adcReset(void);

// Check if the ADC is busy
// 		Takes no arguments
//		Returns 1 if busy, 0 if not busy
//
unsigned int adcCheckBusy(void);

// Start a conversion on the encoder's channel
// and get the result
// 		Takes unsigned int channel num, unsigned int conversion mode
//		Returns result of AD conversion
//
float adcRead(unsigned int channel, unsigned int mode);

#endif