/* PIANO.C */
/* Incldue System Header Files */
#include <stdio.h>
#include <conio.h>

/* Include User Header Files */
#include "include\\piano.h"
#include "include\\octave.h"

int main() {
	int base_octave [] = {A0, A1, A2, A3, A4, A5, A6, A7, A8};
	int DELAY = 1000;
	int octave, note;
	clrscr();
	for (octave = 1; octave < 3; octave++){
		for (note = 0; note < 8; note++){
			printf("Playing Octave [%d] - Note [%d] - Frequency: [%d]\n",
				octave, base_octave[note], base_octave[note] * octave);
			play_note(base_octave[note] * octave, DELAY);
		}
		delay (1000);
	}

	return 0;
}