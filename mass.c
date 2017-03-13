/**
function definitions of mass related things
@author Corey Clow
*/
#include "mass.h"

void printMass(Mass mass, int viewingWidth, int viewingHeight){
	//only print if it is within viewing dimensions
	//and will not print over the border
	if(mass.x>=1&&mass.y>=1&&
		mass.x<viewingWidth-1&&mass.y<viewingHeight-1){
		setCursor(mass.y,mass.x);//reverse becase expects row, col
		put(MASS_CHARACTER);
	}

}
