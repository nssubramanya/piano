#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define GRAPHICS_DRIVER_PATH "C:\\TURBOC3\\BGI"

void showGraphicsDetails(int gDriver, int gMode){
	int maxX, maxY, j = 0;

	printf("Graphics Driver: %s (%d)\nGraphics Mode: %s (%d)\n",
	getdrivername(), gDriver, getmodename(gMode), gMode);

	maxX = getmaxx();
	maxY = getmaxy();

	printf ("MaxX: %d, MaxY: %d", maxX, maxY);
	getch();
//	clrscr();

	setcolor(RED);
	line(0,0,maxX, maxY);
/*
	for (j = 0; j < (maxY+1)/3; j++){
		setcolor(j);
		line(0,j,maxX, j);
	}*/
}

void drawPrimitives(int maxX, int maxY){
	int i, j;
	int thickness;

	// draw Colored Lines
	setlinestyle(SOLID_LINE, SOLID_FILL, THICK_WIDTH);
	for (i = 0; i <= MAXCOLORS; i++){
		setcolor(i);
		line(0, i*20, maxX, i*20);
	}

	getch();
	cleardevice();

	// Draw colored bands
	thickness = maxY/(MAXCOLORS+1);
	for (i = 0; i <= MAXCOLORS; i++){
		setcolor(i);
		setfillstyle(SOLID_FILL, i);
		bar(0, i*thickness, maxX, i*thickness+thickness);
	}

	getch();
	cleardevice();

	// Show fonts
	for (i = DEFAULT_FONT; i <= BOLD_FONT; i++){
		settextstyle(i, HORIZ_DIR, 1);
		outtextxy(100, i * 40, "Hello");
	}

	//rectangle(0,0,maxX,maxY);
}




int main() {
	int gDriver = DETECT, gMode;
	int maxX, maxY;

	printf("%d", DETECT);

//	clrscr();
	initgraph(&gDriver, &gMode, GRAPHICS_DRIVER_PATH);
	maxX = getmaxx();
	maxY = getmaxy();
	//showGraphicsDetails(gDriver, gMode);
	drawPrimitives(maxX, maxY);
	//drawPiano(maxX, maxY);


	getch();
	closegraph();
	return 0;

}