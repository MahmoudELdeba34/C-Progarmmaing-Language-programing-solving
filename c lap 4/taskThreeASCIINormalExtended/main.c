#include <stdio.h>
#include <conio.h>

int main() {
    int ch;

    printf("Press any key (Press ESC to exit):\n");

    while (1) {
        ch = getch(); // Read a character without echoing to the screen

        if (ch == 27) { // 27 is the ASCII value for ESC
            break; // Exit on ESC key
        }

        if (ch == 0 || ch == 224) { // Extended keys give 0 or 224 first
            int extendedCh = getch(); // Read the actual extended key code
            printf("Extended Key: %d (ASCII: %d)\n", extendedCh, ch);
        } else {
            printf("Normal Key: %c (ASCII: %d)\n", ch, ch);
        }
    }

    return 0;
}

