/**
set of functions and typedefs for mass
@author Corey Clow
*/
#ifndef MASS_H
#define MASS_H

#include "display.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//the character that is printed when a mass is printed
#define MASS_CHARACTER 'o'

#define G .0000000000667408//gravitational constant
//6.67408*10^-11
#define DISTANCE_CUTOFF 5.0//do not calculate acceleration if closer than this
typedef struct{
        double mass;
        //position
        double x;
        double y;
        //velocity
        double xVel;
        double yVel;
        //acceleration
        double xAcc;
        double yAcc;
}Mass;

/**
function: updateMassList
description: updates a list of masses including their position,
	velocity, and acceleration

@param size the number of masses in the list
@param masses the list of masses to update
*/
void updateMassList(int size, Mass *masses[]);

/**
function: updateMass
description: updates the position, and velocity of a single mass
	based on its velocity and acceleration.
@param mass a pointer to a mass to update
*/
void updateMass(Mass *mass);

/**
function: printMass
description: prints a mass within the given viewing dimension

@param mass the mass to print
@param viewingWidth the width of the display
@param viewingHeight the height of the display
@param printInfo 0 to not print info, 1 to print info below mass
*/
void printMass(Mass mass, int viewingWidth, int viewingHeight,int printInfo);

/**
function: printMassList
description: prints each mass in a list to the display within viewing constraints
@param startIndex the index to start in the list
@param amount the amount of masses to print
@param masses a list of pointers to masses
@param viewingWidth the width of the display
@param viewingHeight the height of the display
@param printInfo 0 to not print info, 1 to print info of mass below it
*/
void printMassList(int startIndex,int amount, Mass *masses[], int viewingWidth,
	 int viewingHeight,int printInfo);

/**
function: printfMass
description: prints a tostring similar description of a mass

@param mass the mass to get a description of
*/
void printfMass(Mass mass);

/**
function: clearMass
description: clears a single mass from the display

@param mass the mass to clear
@param viewingWidth the width of the display
@param viewingHeight the height of the display
*/
void clearMass(Mass mass, int viewingWidth, int viewingHeight);

/**
function: clearMassList
description: clears each mass in a list from the display

@param size the size of the list
@param masses the list pointers to a mass
@param viewingWidth the width of the display
@param viewingHeight the height of the display
*/
void clearMassList(int size, Mass *masses[], int viewingWidth, int viewingHeight);

/**
function: freeMass
description: frees dynamically allocated memory of a mass struct

@param mass the pointer to a mass created using malloc
*/
void freeMass(Mass *mass);

/**
function: freeMassList
description: frees every dynamically allocated mass in a list

@param size the size of the list
@param mass a list of pointers to dynamically allocated masses
*/
void freeMassList(int size, Mass *masses[]);
#endif

