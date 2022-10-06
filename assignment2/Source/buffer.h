// a1793769 - Emily Zhang
/**
 * * File name buffer.c
 * Description: Function declarations for operations related to the buffer.
pop_front and push_back and meant to be used in conjunction!!
**/
#ifndef BUFFER_H
#define BUFFER_H

/********** Macros **********/

/********** Function Declearations **********/

// Remove the value at index 0 and move each following
// values forward by 1 index
// i.e. value at buffer[1] -> now at buffer[0]
// Also sets value at index buffer_size-1 to be 0xFF
// to prepare for new value
// 		Takes pointer to buffer, and size of buffer
//		Returns nothing
//
void pop_front(float* buffer, int buffer_size);

// Sets the last value of the buffer
// 		Takes pointer to buffer, size of buffer, value to be inserted
//		Returns nothing
//
void push_back(float* buffer, int buffer_size, float value);

#endif