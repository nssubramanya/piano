#ifndef __OCTAVE_H__
#define __OCTAVE_H__

/* Octave Base Frequencies */
#define A0 27.5
#define A1 55
#define A2 110
#define A3 220
#define A4 440
#define A5 880
#define A6 1760
#define A7 3520
#define A8 7040

void play_note(int frequency, int duration);
#endif