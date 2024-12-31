/* PIANO.H */
#ifndef __PIANO_H__
#define __PIANO_H__

#define SA 0
#define RE 1
#define GA 2
#define MA 3
#define PA 4
#define DHA 5
#define NI 6

#define MAX_OCTAVES 5
#define MIN_OCTAVES 1
#define NOTE_DELAY 300

#define HEADER_HEIGHT 48
#define FOOTER_HEIGHT 48

enum KeyType {WHITE_KEY=1, BLACK_KEY=2};

extern int maxX, maxY;
extern const short int note_freq[7];
extern const char* note_names[7];

void play_note(int frequency, int duration);
void initialize_graphics_mode();

void end_graphics_mode();
void show_ui();
void draw_screen();
void draw_piano();
void draw_key(short int key_type);
#endif