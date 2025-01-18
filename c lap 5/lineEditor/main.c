#include <stdio.h>
#include <stdlib.h>  // For system()
#include <conio.h>   // For getch() and gotoxy()
#include <string.h>
#include <ctype.h>   // For isprint()
#include <windows.h> // For Windows-specific functions

#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
#define DELETE 83
#define BACKSPACE 8
#define F1 59
#define F2 60
#define F3 61

#define MAX_LINES 100
#define MAX_LENGTH 120

char buffer[MAX_LINES][MAX_LENGTH]; // Buffer to hold lines of text
int nline = 0; // Number of lines in the buffer
int cline = 0; // Current line
int cx = 1; // Cursor x position
int cy = 1; // Cursor y position

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1; // Adjust for 0-based index
    coord.Y = y - 1; // Adjust for 0-based index
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int textColor, int bgColor) {
    // Set the text color and background color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

void display() {
    system("cls"); // Clear the screen
    setColor(15, 7); // Set text color to white (15) and background color to gray (7)
    for (int i = 0; i < nline; i++) {
        printf("%s\n", buffer[i]);
    }
    gotoxy(cx, cy); // Set cursor position
}

void insertCharacter(int line, char ch, int pos) {
    if (pos < MAX_LENGTH - 1) {
        for (int i = MAX_LENGTH - 1; i > pos; i--) {
            buffer[line][i] = buffer[line][i - 1];
        }
        buffer[line][pos] = ch;
        buffer[line][pos + 1] = '\0'; // Null terminate
    }
}

void deleteCharacter(int line, int pos) {
    if (pos < MAX_LENGTH - 1 && buffer[line][pos] != '\0') {
        for (int i = pos; i < MAX_LENGTH - 1; i++) {
            buffer[line][i] = buffer[line][i + 1];
        }
    }
}

int readInput() {
    int ch = getch(); // Read a character
    if (ch == 0 || ch == 224) { // Special key pressed
        ch = getch(); // Get the actual key code
    }
    return ch;
}

int main() {
    int x;

    // Initialize buffer
    for (int i = 0; i < MAX_LINES; i++) {
        buffer[i][0] = '\0'; // Start with empty lines
    }

    // Load initial content from file (if any)
    FILE *ptr = fopen("myfile.txt", "r");
    if (ptr != NULL) {
        while (!feof(ptr) && nline < MAX_LINES) {
            fgets(buffer[nline], MAX_LENGTH, ptr);
            buffer[nline][strcspn(buffer[nline], "\n")] = 0; // Remove newline
            nline++;
        }
        fclose(ptr);
    }

    display(); // Display the initial content
    gotoxy(cx, cy);

    while (1) {
        x = readInput(); // Read the next key

        switch (x) {
            case F1: {
                // Save function
                FILE *savePtr = fopen("myfile.txt", "w");
                if (savePtr != NULL) {
                    for (int i = 0; i < nline; i++) {
                        fprintf(savePtr, "%s\n", buffer[i]);
                    }
                    fclose(savePtr);
                }
                break;
            }
            case UP:
                if (cline > 0) {
                    cline--;
                    cy--;
                    gotoxy(cx, cy);
                }
                break;
            case DOWN:
                if (cline < nline - 1) {
                    cline++;
                    cy++;
                    gotoxy(cx, cy);
                }
                break;
            case RIGHT:
                if (cx < MAX_LENGTH - 1) {
                    cx++;
                    gotoxy(cx, cy);
                }
                break;
            case LEFT:
                if (cx > 1) {
                    cx--;
                    gotoxy(cx, cy);
                }
                break;
            case DELETE:
                deleteCharacter(cline, cx - 1);
                display();
                break;
            case BACKSPACE:
                if (cx > 1) {
                    deleteCharacter(cline, cx - 2);
                    cx--;
                    display();
                }
                break;
            case 13: // Enter key
                // Print the current line when Enter is pressed
                printf("\n%s\n", buffer[cline]); // Print the current line
                if (nline < MAX_LINES) {
                    for (int i = nline; i > cline + 1; i--) {
                        strcpy(buffer[i], buffer[i - 1]);
                    }
                    buffer[cline + 1][0] = '\0'; // New line
                    nline++;
                }
                cline++;
                cx = 1; // Reset cursor to beginning of new line
                break;
            default:
                if (isprint(x)) { // Check if the character is printable
                    insertCharacter(cline, (char)x, cx - 1);
                    printf("%c", (char)x); // Display the character on the screen
                    cx++;
                    display(); // Refresh display to show the character
                }
                break;
        }
    }

    return 0;
}
