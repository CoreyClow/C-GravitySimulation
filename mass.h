/**
set of functions and typedefs for mass
@author Corey Clow
*/
#ifndef MASS_H
#define MASS_H

#include "display.h"
#include <math.h>
#include <stdio.h>
//the character that is printed when a mass is printed
#define MASS_CHARACTER 'o'

#define G .0000000000667408//gravitational constant
//6.67408*10^-11
#define DISTANCE_CUTOFF 1//do not calculate acceleration if closer than this
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
*/
void printMass(Mass mass, int viewingWidth, int viewingHeight);

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

#endif

