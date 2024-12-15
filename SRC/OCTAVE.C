/* Octave.c */
#include "include\\octave.h"

void play_note(int frequency, int duration) {
	sound(frequency);  // Start sound at given frequency
	delay(duration);   // Wait for the duration (in milliseconds)
	nosound();         // Stop the sound
}
