#include <stdio.h>
#include <conio.h>

int main() {
    int ch;

    printf("Press any key. Press ESC to exit.\n");

    while (1) {
        ch = getch(); // Read a single character without echo

        if (ch == 27) { // ESC key ASCII code is 27
            printf("ESC pressed. Exiting...\n");
            break;
        }

        // Check if this is a special key
        if (ch == 0 || ch == 224) {
            // This means the next getch() will give us the actual scan code
            ch = getch();

            // Print out the special key code
            printf("Special key pressed. Code: %d\n", ch);
        } else {
            // Normal key
            printf("Normal key pressed: '%c' (ASCII: %d)\n", ch, ch);
        }
    }

    return 0;
}
