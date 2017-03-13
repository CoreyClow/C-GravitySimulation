/**
the function definition for delaying program execution
@author Corey Clow
*/
#include "delay.h"

void delay(unsigned int msec){
	//multiple by 1000 because it expects microseconds not milli
	clock_t goal = (msec*1000) + clock();
	while (goal > clock());
}
