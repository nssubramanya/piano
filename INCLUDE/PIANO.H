/* PIANO.H */
#ifndef __PIANO_H__
#define __PIANO_H__

// Frequency Related
#define SA 0
#define re 1
#define RE 2
#define ga 3
#define GA 4
#define MA 5
#define ma 6
#define PA 7
#define dha 8
#define DHA 9
#define ni 10
#define NI 11

#define MIN_OCTAVES 1
#define MAX_OCTAVES 8
#define DEFAULT_OCTAVE 4

#define NOTE_DELAY 300

// Keys related
#define NUM_KEYS 7
#define KEY_STATE_PRESSED  1
#define KEY_STATE_RELEASED 0

// UI Related
#define HEADER_HEIGHT 48
#define FOOTER_HEIGHT 48

#define HEADER_TEXT "PIANO"
#define FOOTER_TEXT "By: Sushruth Subramanya () & Vishnuswaroop R ()"

#define WHITE_KEY_WIDTH 	56
#define WHITE_KEY_HEIGHT	200
#define BLACK_KEY_WIDTH		40
#define BLACK_KEY_HEIGHT	108
#define BLACK_KEY_OFFSET ((WHITE_KEY_WIDTH-BLACK_KEY_WIDTH)/2)

#define PIANO_X 54
#define PIANO_Y 120
#define STATS_X 500
#define STATS_WIDTH 80
#define STATS_MARGIN 3
#define STATS_KEY_PRESSED_Y 3
#define STATS_NOTE_PLAYED_Y 69
#define STATS_FREQUENCY_Y 136

#define KEY_TEXT_HEIGHT 36

#define PRESSED_KEY_COLOR DARK_GRAY

#define UPDATE_OCTAVE 1
#define UPDATE_NOTE 2

#define DRAW_TYPE_DRAW_ONLY 1
#define DRAW_TYPE_UPDATE 2

enum KeyType {WHITE_KEY=1, BLACK_KEY=2};

extern int maxX, maxY;
extern const double note_freq[12];
extern const char* note_names[12];

void play_note(int note, unsigned int frequency, int duration);
void initialize_graphics_mode();

void end_graphics_mode();
void show_ui();
void draw_screen();
void draw_piano();
void draw_key(int draw_type, int key_number, int key_type, int key_state);
void show_text(int x, int y, int width, int height, char *text,
	int font, int direction, int size, int color, int hjust, int vjust);
void update_stats(int update_type, char ch, char* note, unsigned int freq);
void update_key(int note, int state);
#endif