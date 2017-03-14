/**
set of functions and typedefs for mass
@author Corey Clow
*/
#ifndef MASS_H
#define MASS_H

#include "display.h"

//the character that is printed when a mass is printed
#define MASS_CHARACTER 'o'

typedef struct{
        float mass;
        //position
        float x;
        float y;
        //velocity
        float xVel;
        float yVel;
        //acceleration
        float xAcc;
        float yAcc;
}Mass;

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
function: clearMass
description: clears a single mass from the display

@param mass the mass to clear
@param viewingWidth the width of the display
@param viewingHeight the height of the display
*/
void clearMass(Mass mass, int viewingWidth, int viewingHeight);

#endif

