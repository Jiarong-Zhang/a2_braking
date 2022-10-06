// a1793769 - Emily Zhang
/**
Implementation for GPIO functions
**/

/* Include required submodules */
#include "Drivers/gpio.h"

// Set a P2 pin's I/O direcion 
void setPinDirectionP2(unsigned int pin_num, unsigned int direction)
{
	if (direction == INPUT)
	{
		// reset to 0
		DP2 &= ~(1 << pin_num);
	}
	else if (direction == OUTPUT)
	{
		// set to 1
		DP2 |= (1 << pin_num);
	}
}

// Read a pin on P2
unsigned int readPinP2(unsigned int port_pin)
{
	if (P2 & (1 << port_pin))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Set a pin on P2 to 1
// (ony works for output pins!)
void setPinP2(unsigned int pin_num)
{
	// Can only set pin if it's an output
	if (DP2 & (1 << pin_num))
	{
		P2 |= (1 << pin_num);
	}	
}

// Clear a pin on P2 to 1
// (ony works for output pins!)
void clrPinP2(unsigned int pin_num)
{
	// Can only set pin if it's an output
	if (DP2 & (1 << pin_num))
	{
		P2 &= ~(1 << pin_num);
	}	
}

// Read a pin on P5
unsigned int readPinP5(unsigned int port_pin)
{
	if (P5 & (1 << port_pin))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

// Config P5 digital input control
void configPinP5(unsigned int pin_num, unsigned int value)
{
	if (value == 1)
	{
		P5DIDIS |= (1 << pin_num);
	}
	else if (value == 0)
	{
		P5DIDIS &= ~(1 << pin_num);
	}
}
