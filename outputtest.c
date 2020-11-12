#include "project.h"

int main(void){
	uint16_t color= getColor(255,0,0);
	initializeFB();
	displayPoint(0,0,color);
	displayPoint(1,1,color);
	displayPoint(2,2,color);
	displayPoint(3,3,color);
	displayPoint(4,4,color);
	displayPoint(5,5,color);
	displayPoint(6,6,color);
	displayPoint(7,7,color);
	char garb;
	printf("Press a key then enter to terminate\n");
	scanf("%c",&garb);
	clear();
	freeFB();
}	
