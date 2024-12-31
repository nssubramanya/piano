#include <graphics.h>

#include "include\piano.h"
#define GRAPHICS_DRIVER_PATH "C:\\TURBOC3\\BGI"

int maxX, maxY;

void initialize_graphics_mode(){
	int gDriver = DETECT, gMode;

	clrscr();

	initgraph(&gDriver, &gMode, GRAPHICS_DRIVER_PATH);

	maxX = getmaxx();
	maxY = getmaxy();

}

void end_graphics_mode(){
	closegraph();
}