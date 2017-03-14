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
#include <signal.h>//catching ctrl c
#include "delay.h"//delay
#include "display.h"//put, set, clear, printBorder
#include "mass.h"//mass struct, MASS_CHARACTER, printMass

#define WIDTH 140
#define HEIGHT 28
#define DELAY_MS 16 //60 fps
#define MAX_MASSES 100

#define BEST_MASS 100000.0

static volatile int running =1;//the flag to notify if running or not

/**
function: ctrlCHandler
description: this function gets called when user presses ctrl-c at any time
@param flag the flag that is set to 0 to signify end of program running
*/
void ctrlCHandler(int flag){
	running=0;
}

/**
function: populateMassList
description: allows the user to enter masses into the field
	and mallocs memory to store the masses
@param masses the list of masses to populate
*/
int populateMassList(Mass *masses[]){
	int numMasses = 0;
	clear();
        printBorder(0,0,WIDTH,HEIGHT);//print border of view
	do{	
                double mass;
                double x;
                double y;
		//prompt user for variables
		clearWithin(HEIGHT,0,WIDTH,4);
		setCursor(HEIGHT,0);//set cursor to bottom of border
                printf("Mass information (non numeric to start simulation)."\
			"\n    Mass: ");
                if(scanf("%lf",&mass)!=1)
			break;//non numeric so exit loop
                printf("    X: ");
                if(scanf("%lf",&x)!=1)
			break;//non numeric so exit loop
                printf("    Y: ");
                if(scanf("%lf",&y)!=1)
			break;//non numeric so exit loop
		
		//allocate memory for a mass
                Mass *tempMass = malloc(sizeof(Mass));

		//set variables of mass struct
                tempMass->mass = mass;
                tempMass->x = x;
                tempMass->y = y;
                tempMass->xVel = 0.0;
                tempMass->yVel = 0.0;
                tempMass->xAcc = 0.0;
                tempMass->yAcc = 0.0;

		//enter it into the list
                masses[numMasses]=tempMass;
                numMasses++;
		//display all masses
                printMassList(numMasses,masses,WIDTH,HEIGHT);
        }while(1);//a non numeric user enter will exit loop
	
	return numMasses;
}

/**
function: run
description: the main program loop
*/
void run(){	
	Mass *list[MAX_MASSES];
	int numMasses = 0;
	int cycle = 0;
	
	numMasses = populateMassList(list);
	
	clear();//clear the command prompt
	printBorder(0,0,WIDTH,HEIGHT);
	while(running){
		//view stuff---
		printMassList(numMasses,list,WIDTH,HEIGHT);

		setCursor(HEIGHT,0);//set cursor to bottom of border
		printf("Cycle %d\nnumMasses: %d\n",cycle,numMasses);

		delay(DELAY_MS);
		clearMassList(numMasses,list,WIDTH,HEIGHT);
		//model stuff---
		updateMassList(numMasses,list);
		cycle++;
	}
	//print masses one last time
	printMassList(numMasses,list,WIDTH,HEIGHT);

	//free all the malloced masses
	freeMassList(numMasses,list);
	setCursor(HEIGHT+2,0);
}

int main(int argc, char** argv){
	//tells the program to call ctrlCHandler function upon exit
	signal(SIGINT,ctrlCHandler);
	run();
	return EXIT_SUCCESS;
}
