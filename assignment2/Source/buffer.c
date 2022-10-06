// a1793769 - Emily Zhang
/**
 * File name buffer.c
 * Description: Implementation for operations related to the buffer 
**/

/********** Include required submodules**********/
#include "buffer.h"

/********** Function Definitions **********/

void pop_front(float* buffer, int buffer_size)
{
	int i = 0;
	for(i; i < buffer_size; i++)
    {
			if (i == buffer_size - 1)
			{
				buffer[buffer_size-1] = 0xFF;
				break;
			}
			else
			{
        buffer[i] = buffer[i+1];
			}
    }
    
}

void push_back(float* buffer, int buffer_size, float value)
{
	buffer[buffer_size-1] = value;
}