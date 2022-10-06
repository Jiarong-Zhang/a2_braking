// a1793769 - Emily Zhang
/**
 * File name interrupt.h
 * Description: Function declarations for operations related C167 interrupts 
**/

#ifndef INTERRUPT_H
#define INTERRUPT_H

/********** Include required submodules**********/

#include <reg167.h>

/********** Function Declearations **********/

// Enable global interrupts
// 		Takes no arguments
//		Returns nothing
//
void interruptEnable(void);

// Disable global interrupts
// 		Takes no arguments
//		Returns nothing
//
void interruptDisable(void);

#endif
