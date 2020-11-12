#include "project.h"
pi_framebuffer_t *fb;
void initializeFB(void){
	fb = getFBDevice();
}
	
void displayPoint(int x,int y,uint16_t color){
	setPixel(fb->bitmap,x,y,color);
}

void clear(void){
	clearBitmap(fb->bitmap, 0);
}

void freeFB(void){
	freeFrameBuffer(fb);
}
