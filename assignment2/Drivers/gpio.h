// a1793769 - Emily Zhang
/**
Declarations for GPIO functions, for both P2 and P5
**/
#ifndef GPIO_H
#define GPIO_H

/* Include required submodules */
#include <reg167.h>

/********** Macros **********/
// Setup macros for declaring pin direction
#define INPUT  0U
#define OUTPUT 1U

// Setup macros for declaring pin value
#define LOW  0U
#define HIGH 1U

/********** Function Declearations **********/

// Set pin direction for the given pin on port P2
// 		Takes the pin number and direction as input
//		Returns void
//
void setPinDirectionP2(unsigned int pin_num, unsigned int direction);

// Reads and returns the value of the given pin at port P2
unsigned int readPinP2(unsigned int port_pin);

// Set this P2 pin HIGH (1)
void setPinP2(unsigned int pin_num);

// Clears the value at this pin on P2 (sets to be 0)
void clrPinP2(unsigned int pin_num);

// repeat for port 5, which is read-only, so we just need
// the 'read' function, but not the set/clr functions

// Reads and returns the value of the given pin at port P5
unsigned int readPinP5(unsigned int port_pin);

// Configure port 5 digital input control
// LOW/0 = digital input stage connected
// HIGH/1 = digital input stage NOT connected
// 		Takes pin num and pin value
// 		Returns nothing

void configPinP5(unsigned int pin_num, unsigned int value);

#endif
