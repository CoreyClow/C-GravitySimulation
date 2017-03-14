/**
function definitions of mass related things
@author Corey Clow
*/
#include "mass.h"

void updateMassList(int size, Mass *masses[]){
	//first update position and velocity
	for(int i = 0; i < size; i++){
		updateMass(masses[i]);
	}
	
	//now update accelerations of all
	for(int i = 0; i < size; i++){
		//the values that will be updated to
		double totalXAcc = 0.0;
		double totalYAcc = 0.0;
		for(int j = 0; j < size; j++){
			if(i==j)//dont include yourself
				continue;
			Mass *mass1 = masses[i];//the mass to update
			Mass *mass2 = masses[j];//foreign mass

			double distanceSquared = pow(mass2->x-mass1->x,2)
				 + pow(mass2->y-mass1->y,2);
			
			//do not calculate acceleration, too close
			if(sqrt(distanceSquared)<DISTANCE_CUTOFF)
				continue;

			//acceleration before components x and y
			double accel= ((G*(mass1->mass*mass2->mass))/distanceSquared);
			
			//break into components x and y
			//angle is in radians
			double angle = atan2((mass2->y-mass1->y),(mass2->x-mass1->x));
			double accX = accel*cos(angle);
			double accY = accel*sin(angle);
			
			totalXAcc += accX;
			totalYAcc += accY;
			
			/*
			if(mass2->x-mass1->x>=0)//1 is left of 2
				totalXAcc +=accX;
			else if (mass2->x-mass1->x<0)//1 is right of 2
				totalXAcc -= accX;
			if(mass2->y-mass1->y>=0)//1 is above 2
				totalYAcc += accY;
			else if(mass2->y-mass1->y<0)//1 is below 2
				totalYAcc -= accY;
			*/
		}
		//set the accelerations
		masses[i]->xAcc = totalXAcc;
		masses[i]->yAcc = totalYAcc;
	}

}

void updateMass(Mass *mass){
	//update mass position
	mass->x += mass->xVel;
	mass->y += mass->yVel;
	
	//update mass velocity
	mass->xVel += mass->xAcc;
	mass->yVel += mass->yAcc;
}

void printMass(Mass mass, int viewingWidth, int viewingHeight){
	//only print if it is within viewing dimensions
	//and will not print over the border
	if(mass.x>=1&&mass.y>=1&&
		mass.x<viewingWidth-1&&mass.y<viewingHeight-1){
		setCursor(mass.y,mass.x);//reverse becase expects row, col
		put(MASS_CHARACTER);
	}

}

void printfMass(Mass mass){
	printf("pos:(%f,%f) vel:(%f,%f) acc:(%f,%f)",mass.x,mass.y,mass.xVel,mass.yVel,mass.xAcc,mass.yAcc);
}

void clearMass(Mass mass, int viewingWidth, int viewingHeight){
	//only clear if it is within viewing dimensions
	//and will not clear over the border
	if(mass.x>=1&&mass.y>=1&&
		mass.x<viewingWidth-1&&mass.y<viewingHeight-1){
		clearSpot(mass.y,mass.x);
	}
}
