/**
Proram: Gravity Simulation
description: this program simulates gravity by creating multiple masses
	at the users specification and calculating the acceleration
	due to gravity in real time and updating locations on the screen

author: Corey Clow - cmc4533@rit.edu
date: March 13, 2017

*/
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"//delay
#include "display.h"//put, set, clear, printBorder
#include "mass.h"//mass struct, MASS_CHARACTER, printMass

int width = 60;
int height = 30;


/**
function: run
description: the main prorgam loop
*/
void run(){
	Mass mass1 = {10,15,15,0,0,0,0};
	int cycle = 0;

	int running = 1;


	clear();//clear the command prompt
	printBorder(0,0,width,height);
	while(running){
		printMass(mass1,width,height);

		setCursor(height,0);
		printf("Cycle: %d\n",cycle);
		cycle++;
		delay(1000);
	}
}

int main(int argc, char** argv){
	
	run();
	return EXIT_SUCCESS;
}
