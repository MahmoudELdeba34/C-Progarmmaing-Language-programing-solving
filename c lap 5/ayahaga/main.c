/*
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
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX_LENGTH 120

// Function to set console text color and background color
void setConsoleColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

// Function to position the cursor on the console screen
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to calculate the center position on the console screen
int getCenterPosition(int textLength) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    // Get the console screen buffer info to calculate center
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    return (columns - textLength) / 2;
}

// Function to draw a box with a specific color for the border
void drawBox(int width, int height, int startX, int startY, int borderColor) {
    setConsoleColor(borderColor, 0);  // Set border color
    gotoxy(startX, startY);
    printf("+");
    for (int i = 0; i < width - 2; i++) printf("-");
    printf("+");

    for (int i = 1; i < height - 1; i++) {
        gotoxy(startX, startY + i);
        printf("|");
        gotoxy(startX + width - 1, startY + i);
        printf("|");
    }

    gotoxy(startX, startY + height - 1);
    printf("+");
    for (int i = 0; i < width - 2; i++) printf("-");
    printf("+");
    setConsoleColor(7, 0);  // Reset to default color
}

int main() {
    char text[MAX_LENGTH] = {0};      // Array to store typed characters
    char deleted[MAX_LENGTH] = {0};   // Array to store deleted characters
    int index = 0, del_index = 0;     // Pointers for the current position in text and deleted arrays
    int cursor_pos = 0;

    int boxWidth = 50;
    int boxHeight = 5;
    int centerPosX = getCenterPosition(boxWidth);
    int centerPosY = 5;

    printf("Start typing. Use arrow keys for navigation. Press Enter to finish:\n");

    while (1) {
        int ch = getch();

        // Clear the screen and redraw both boxes (input and output boxes)
        system("cls");

        // Draw input box at the center of the screen
        drawBox(boxWidth, boxHeight, centerPosX, centerPosY, 1);  // Blue border for input box

        // Draw output box below the input box for final display after Enter
        drawBox(boxWidth, boxHeight, centerPosX, centerPosY + 10, 2);  // Green border for output box

        switch (ch) {
            case 224:  // Extended key (arrow keys or delete)
                ch = getch();
                switch (ch) {
                    case 75:  // LEFT arrow
                        if (cursor_pos > 0) cursor_pos--;
                        break;
                    case 77:  // RIGHT arrow
                        if (cursor_pos < index) cursor_pos++;
                        break;
                    case 83:  // DELETE key
                        if (cursor_pos < index) {
                            deleted[del_index++] = text[cursor_pos];  // Store deleted character
                            for (int i = cursor_pos; i < index - 1; i++) {
                                text[i] = text[i + 1];
                            }
                            text[--index] = '\0';
                        }
                        break;
                }
                break;

            case '\b':  // BACKSPACE key
                if (cursor_pos > 0) {
                    deleted[del_index++] = text[cursor_pos - 1];  // Store deleted character
                    for (int i = cursor_pos - 1; i < index - 1; i++) {
                        text[i] = text[i + 1];
                    }
                    text[--index] = '\0';
                    cursor_pos--;
                }
                break;

            case '\r':  // ENTER key
                // Display final message in the output box
                setConsoleColor(2, 0);  // Green text for final message
                gotoxy(centerPosX + 2, centerPosY + 12);  // Position output text within output box
                printf("You typed this: %s", text);
                setConsoleColor(7, 0);  // Reset to default color
                return 0;

            default:
                if (isprint(ch) && index < MAX_LENGTH - 1) {  // Printable characters
                    for (int i = index; i > cursor_pos; i--) {
                        text[i] = text[i - 1];
                    }
                    text[cursor_pos++] = ch;
                    index++;
                }
                break;
        }

        // Display the text inside the input box and position the cursor
        setConsoleColor(14, 0);  // Yellow text on black background for typing area
        gotoxy(centerPosX + 2, centerPosY + 2);  // Position within input box
        printf("%s", text);
        gotoxy(centerPosX + 2 + cursor_pos, centerPosY + 2);  // Position cursor after typed text
        setConsoleColor(7, 0);  // Reset to default color
    }
}
