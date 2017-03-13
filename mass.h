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
        int mass;
        //position
        int x;
        int y;
        //velocity
        int xVel;
        int yVel;
        //acceleration
        int xAcc;
        int yAcc;
}Mass;

/**
function: printMass
description: prints a mass within the given viewing dimension

@param mass the mass to print
@param viewingDimension the dimension of the viewing square to print
*/
void printMass(Mass mass, int viewingWidth, int viewingHeight);

#endif

