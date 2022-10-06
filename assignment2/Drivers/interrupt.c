// a1793769 - Emily Zhang
/**
Function declarations for operations related C167 interrupts 
**/

/* Include required submodules */
#include "interrupt.h"

/********** Function Definitions **********/
void interruptEnable(void)
{
	IEN = 1;
}

void interruptDisable(void)
{
	IEN = 0;
}