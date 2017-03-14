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

#define MASS_UNIT 1000000000 // multiple user enter by this

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
@param startIndex the index to start at in the list
*/
int populateMassList(Mass *masses[],int startIndex){
	int numMasses = 0;
	clear();
        printBorder(0,0,WIDTH,HEIGHT);//print border of view
	printMassList(0,startIndex, masses,WIDTH,HEIGHT,0);
	do{	
                double mass;
                double x;
                double y;
		//prompt user for variables
		clearWithin(HEIGHT,0,WIDTH,4);
		setCursor(HEIGHT,0);//set cursor to bottom of border
                printf("Mass information (non numeric to start simulation)."\
			"\n    Mass: ");
		fflush(stdin);
                if(scanf("%lf",&mass)!=1)
			break;//non numeric so exit loop
                printf("    X: ");
		fflush(stdin);
                if(scanf("%lf",&x)!=1)
			break;//non numeric so exit loop
                printf("    Y: ");
		fflush(stdin);
                if(scanf("%lf",&y)!=1)
			break;//non numeric so exit loop
		
		//allocate memory for a mass
                Mass *tempMass = malloc(sizeof(Mass));

		//set variables of mass struct
                tempMass->mass = mass * MASS_UNIT;
                tempMass->x = x;
                tempMass->y = y;
                tempMass->xVel = 0.0;
                tempMass->yVel = 0.0;
                tempMass->xAcc = 0.0;
                tempMass->yAcc = 0.0;

		//enter it into the list
                masses[startIndex+numMasses]=tempMass;
                numMasses++;
		//display all masses created in this function
                printMassList(startIndex,numMasses,masses,WIDTH,HEIGHT,1);
        }while(startIndex+numMasses<MAX_MASSES);//a non numeric user enter will exit loop
	
	return numMasses;
}

/**
function: preloadMassList
description: preloads the mass list with a certain number of masses

@param masses the list of masses to populate
*/
int preloadMassList(Mass *masses[]){
        clear();
        printBorder(0,0,WIDTH,HEIGHT);

        //number of masses to spawn
        int numMasses = rand()%MAX_MASSES;

        for(int i = 0; i < numMasses;i++){
                Mass *mass = malloc(sizeof(Mass));
                mass->mass= ((rand()%100+1)/50.0)*MASS_UNIT;//random reasonable mass
                mass->x = rand()%WIDTH;//random x within viewing 
                mass->y = rand()%HEIGHT;//random y within viewing
                mass->xVel = 0;//0 everything else
                mass->yVel = 0;
                mass->xAcc = 0;
                mass->yAcc = 0;
                masses[i]=mass;
        }

        printMassList(0,numMasses,masses,WIDTH,HEIGHT,0);

        //allow user to enter more
        numMasses+=populateMassList(masses,numMasses);
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
	
	numMasses = preloadMassList(list);
	
	clear();//clear the command prompt
	printBorder(0,0,WIDTH,HEIGHT);
	while(running){
		//view stuff---
		printMassList(0,numMasses,list,WIDTH,HEIGHT,0);

		setCursor(HEIGHT,0);//set cursor to bottom of border
		printf("Cycle %d\nnumMasses: %d\n",cycle,numMasses);

		delay(DELAY_MS);
		clearMassList(numMasses,list,WIDTH,HEIGHT);
		//model stuff---
		updateMassList(numMasses,list);
		cycle++;
	}
	//print masses one last time
	printMassList(0,numMasses,list,WIDTH,HEIGHT,0);

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
