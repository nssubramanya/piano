/* PIANO.C */
/* Incldue System Header Files */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
/* Include User Header Files */
#include "include\\piano.h"
//#include "include\\octave.h"

short int g_octave = MIN_OCTAVES;

// Frequeny of Notes SA, RE, GA, MA, PA, DHA, NI
const short int note_freq[7] = {240, 270, 300, 320, 360, 400, 450};
const char* note_names[7] = {"Sa", "Re", "Ga", "Ma", "Pa", "Dha", "Ni"};

void play_note(int frequency, int duration) {
	sound(frequency);  // Start sound at given frequency
	delay(duration);   // Wait for the duration (in milliseconds)
	nosound();         // Stop the sound
}

void play_octave() {
	//int base_octave [] = {A0, A1, A2, A3, A4, A5, A6, A7, A8};
	int base_octave [] = {SA, RE, GA, MA, PA, DHA, NI};
	int DELAY = 1000;
	int octave, note;
	clrscr();
	for (octave = 1; octave <= 3; octave++){
		for (note = 0; note < 7; note++){
			printf("Playing Octave [%d] - Note [%d] - Frequency: [%d]\n",
				octave, base_octave[note], base_octave[note] * octave);
			play_note(base_octave[note] * octave, DELAY/2);
		}
		delay (1000);
	}
}

void piano_mode(){
	int ch, note, frequency;

	printf("--- Entering PIANO Mode ---\n");
	while(1){
		ch = getch(); // Read a single character without echo

		if (ch == 27) { // ESC key ASCII code is 27
			printf("--- Exiting PIANO Mode ---\n");
			break;
		}

		// Check if this is a special key
		if (ch == 0 || ch == 224) {
			// This means the next getch() will give us the actual scan code
			ch = getch();

			// Handle UP Arrow -> Octave Up
			if (ch == 72) {
				if (g_octave < MAX_OCTAVES){
					g_octave++;
					printf("--- Octave Up --- %d\n", g_octave);
				}
				else {
					printf("** Max Octaves Reached **\n");
				}
			}

			// Handle DOWN Arrow -> Octave Down
			else if (ch == 80) {
				if (g_octave > 1) {
					g_octave--;
					printf("--- Octave Down --- %d\n", g_octave);
				}
				else {
					printf("** Min Octaves Reached **\n");
				}
			}
		} else {
			// Map the keys to notes

			if (ch == 's' || ch == 'S')
				note = SA;
			else if (ch == 'r' || ch == 'R')
				note = RE;
			else if (ch == 'g' || ch == 'G')
				note = GA;
			else if (ch == 'm' || ch == 'M')
				note = MA;
			else if (ch == 'p' || ch == 'P')
				note = PA;
			else if (ch == 'd' || ch == 'D')
				note = DHA;
			else if (ch == 'n' || ch == 'N')
				note = NI;
			else
				note = -1;

			if (note >= SA && note <= NI) {
				frequency = note_freq[note] * g_octave;
				printf("Key pressed: '%c'. Note: %s, Freq: %d\n",
					ch,
					note_names[note],
					frequency);

				// Play Note
				play_note(frequency, NOTE_DELAY);
			}
		}
	}
}
void show_text(int x, int y, int width, int height, char *text,
	int font, int direction, int size, int color, int hjust, int vjust){
	int tw, th, tx, ty;
	setcolor(color);
	settextstyle(font, direction, size);

	tw = textwidth(text);
	th = textheight(text);

	switch(hjust){
		case CENTER_TEXT:
			tx = x + (width-tw)/2;
			break;
		case LEFT_TEXT:
			tx = x + 10;
			break;
		case RIGHT_TEXT:
			tx = x + width - tw - 10;
			break;
	}

	// Assuming CENTER_JUST for Vertical as of now

	ty = y + (height-th)/2;
	outtextxy(tx, ty, text);

}
void draw_header(){
	setfillstyle(SOLID_FILL, BROWN);
	bar(0,0,maxX,HEADER_HEIGHT);

	show_text(0, 0, maxX, HEADER_HEIGHT, "PIANO",
		DEFAULT_FONT, HORIZ_DIR, 2, WHITE, CENTER_TEXT, CENTER_TEXT);
}

void draw_footer(){
	setfillstyle(SOLID_FILL, BLUE);
	bar(0,maxY-FOOTER_HEIGHT,maxX,maxY);
}

void draw_main_screen(){
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, HEADER_HEIGHT+1, maxX, maxY-FOOTER_HEIGHT-1);
}

void draw_screen(){
	draw_header();
	draw_main_screen();
	draw_footer();
}

void show_ui(){
	draw_screen();
}

void main() {
	clrscr();
	initialize_graphics_mode();
	show_ui();

	//piano_mode();
	getch();
	end_graphics_mode();

}