#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define GRAPHICS_DRIVER_PATH "C:\\TURBOC3\\BGI"

void showGraphicsDetails(){
	printf("Graphics Driver: %s (%d)\nGraphics Mode: %s (%d)\n",
		getdrivername(), gDriver, getmodename(gMode), gMode);

	maxX = getmaxx();
	maxY = getmaxy();

	printf ("MaxX: %d, MaxY: %d", maxX, maxY);
}

int main() {
	int gDriver = DETECT, gMode;
	int maxX, maxY;

	clrscr();

	initgraph(&gDriver, &gMode, GRAPHICS_DRIVER_PATH);

	// Change color to RED
	setcolor(RED);

	// Draw a Line
	setlinestyle(SOLID_LINE, SOLID_FILL, THICK_WIDTH);
	rectangle(0, 0, maxX, maxY);


	getch();
	closegraph();

}