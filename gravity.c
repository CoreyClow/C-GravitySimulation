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

#define WIDTH 120
#define HEIGHT 30
#define DELAY_MS 16 //60 fps


/**
function: run
description: the main prorgam loop
*/
void run(){
	Mass mass1 = {10.0,15.0,15.0,1.3,0.0,-.01,0.0};
	int cycle = 0;

	int running = 1;


	clear();//clear the command prompt
	printBorder(0,0,WIDTH,HEIGHT);
	while(running){
		//view stuff---
		printMass(mass1,WIDTH,HEIGHT);
		setCursor(HEIGHT,0);
		printf("Cycle: %d\n",cycle);
		delay(DELAY_MS);
		clearMass(mass1,WIDTH,HEIGHT);

		//model stuff---
		updateMass(&mass1);
		cycle++;
	}
}

int main(int argc, char** argv){
	
	run();
	return EXIT_SUCCESS;
}
