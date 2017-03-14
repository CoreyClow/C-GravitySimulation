/**
Program: Gravity Simulation
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
	Mass mass1 = {100000.0,5.0,20.0,0.0,0.0,0.0,0.0};
	Mass mass2 = {100000.0,5.0,5.0,0.0,0.0,0.0,0.0};
	Mass *list[] = {&mass1,&mass2};
	int cycle = 0;

	int running =1;


	clear();//clear the command prompt
	printBorder(0,0,WIDTH,HEIGHT);
	while(running){
		//view stuff---
		printMass(mass1,WIDTH,HEIGHT);
		printMass(mass2,WIDTH,HEIGHT);

		setCursor(HEIGHT,0);
		printf("Cycle: %d\n",cycle);
		printf("mass1: ");
		printfMass(mass1);
		printf("\nmass2: ");
		printfMass(mass2);
		printf("\n");

		delay(DELAY_MS);
		clearMass(mass1,WIDTH,HEIGHT);
		clearMass(mass2,WIDTH,HEIGHT);
		//model stuff---
		updateMassList(2,list);
		cycle++;
	}
}

int main(int argc, char** argv){
	
	run();
	return EXIT_SUCCESS;
}
