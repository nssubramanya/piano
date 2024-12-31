/* PIANO.C */
/* Incldue System Header Files */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
/* Include User Header Files */
#include "include\\piano.h"
//#include "include\\octave.h"

short int g_octave = DEFAULT_OCTAVE;

// Frequeny of Notes SA, RE, GA, MA, PA, DHA, NI
const short int note_freq[12] = {16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12,
	24.50, 25.96, 27.50, 29.14, 30.87};
const char* note_names[12] = {"Sa", "re", "Re", "ga", "Ga", "Ma", "ma", "Pa", "dha", "Dha", "ni", "Ni"};

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
			switch (ch) {
				case 'S':
					note = SA;
					break;
				case 'r':
					note = re;
					break;
				case 'R':
					note = RE;
					break;
				case 'g':
					note = ga;
					break;
				case 'G':
					note = GA;
					break;
				case 'M':
					note = MA;
					break;
				case 'm':
					note = ma;
					break;
				case 'P':
					note = PA;
					break;
				case 'd':
					note = dha;
				case 'D':
					note = DHA;
					break;
				case 'n':
					note = ni;
				case 'N':
					note = NI;
					break;
				default:
					note = -1;
					break;
			}

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

	show_text(0, 0, maxX, HEADER_HEIGHT, HEADER_TEXT,
		DEFAULT_FONT, HORIZ_DIR, 2, WHITE, CENTER_TEXT, CENTER_TEXT);
}

void draw_footer(){
	setfillstyle(SOLID_FILL, BLUE);
	bar(0, maxY-FOOTER_HEIGHT, maxX, maxY);

	show_text(0, maxY-FOOTER_HEIGHT, maxX, FOOTER_HEIGHT, FOOTER_TEXT,
		DEFAULT_FONT, HORIZ_DIR, 1, WHITE, LEFT_TEXT, CENTER_TEXT);
}

void draw_key(int key_number, int key_type, int key_state){
	int kx, ky, kw, kh, kc;

	// determine key color
	switch (key_state){
		case KEY_STATE_PRESSED:
			kc = DARKGRAY;
			break;
		case KEY_STATE_RELEASED:
			if(key_type == WHITE_KEY)
				kc = WHITE;
			else
				kc = BLACK;
			break;
	}

	setcolor(BLACK);
	setfillstyle(SOLID_FILL, kc);

	// draw the key
	switch(key_type){
		case WHITE_KEY:
			kw = WHITE_KEY_WIDTH;
			kh = WHITE_KEY_HEIGHT;

			// key_number starts from 1, so offset it
			kx = (key_number-1) * kw;
			//bar(PIANO_X + kx, PIANO_Y, PIANO_X + kx + kw, PIANO_Y + kh);
			//rectangle(PIANO_X + kx, PIANO_Y, PIANO_X + kx + kw, PIANO_Y + kh);
			break;

		case BLACK_KEY:
			kw = BLACK_KEY_WIDTH;
			kh = BLACK_KEY_HEIGHT;

			// Determine x-location
			// Need to skip 1 key for later 3 keys
			if (key_number <= 2)
				key_number--;

			kx = key_number * WHITE_KEY_WIDTH + WHITE_KEY_WIDTH/2 + BLACK_KEY_OFFSET;

			//bar(PIANO_X + kx, PIANO_Y, PIANO_X + kx + kw, PIANO_Y + kh);
			//rectangle(PIANO_X + kx, PIANO_Y, PIANO_X + kx + kw, PIANO_Y + kh);
			break;
	}
	bar(PIANO_X + kx, PIANO_Y, PIANO_X + kx + kw, PIANO_Y + kh);
	rectangle(PIANO_X + kx, PIANO_Y, PIANO_X + kx + kw, PIANO_Y + kh);

}

void draw_piano(){
	int i;

	setcolor(BLACK);
	//rectangle(PIANO_X, PIANO_Y,
	//	PIANO_X + 7 * WHITE_KEY_WIDTH, PIANO_Y + WHITE_KEY_HEIGHT);
	for (i = 1; i <= 7; i++){
		draw_key(i, WHITE_KEY, KEY_STATE_RELEASED);
	}
	for (i = 1; i <= 5; i++){
		draw_key(i, BLACK_KEY, KEY_STATE_RELEASED);
	}
	draw_key(1, WHITE_KEY, KEY_STATE_PRESSED);
	draw_key(1, BLACK_KEY, KEY_STATE_RELEASED);
	draw_key(5, BLACK_KEY, KEY_STATE_PRESSED);
}

void draw_stats(){
}

void draw_main_screen(){
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, HEADER_HEIGHT+1, maxX, maxY-FOOTER_HEIGHT-1);

	draw_piano();
	draw_stats();
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
	//initialize_graphics_mode();
	//show_ui();

	piano_mode();
	getch();
	//end_graphics_mode();

}