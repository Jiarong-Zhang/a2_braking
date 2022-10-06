// a1793769 - Emily Zhang
/**
 * File name main.c
 * Description: Global, constant, and extern definition declearations
 **/

#ifndef PLATFORM_H
#define PLATFORM_H

/********** Macros **********/

#define BUFFER_SIZE 3

/********** Extern Declaration **********/

extern volatile unsigned int g_wait_flag;
extern volatile float g_dist_buffer[BUFFER_SIZE];

/********** Function Definitions **********/

#endif