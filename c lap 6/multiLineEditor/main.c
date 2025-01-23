#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX_LENGTH 120
#define MAX_LINES 10

void setConsoleColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getCenterPosition(int textLength) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return (columns - textLength) / 2;
}

void drawBox(int width, int height, int startX, int startY, int borderColor) {
    setConsoleColor(borderColor, 0);
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
    setConsoleColor(7, 0);
}

void printTextOutput(char text[MAX_LINES][MAX_LENGTH], int width, int startX, int startY) {
    setConsoleColor(2, 0);
    drawBox(width, MAX_LINES + 2, startX, startY, 2); // Draws green box for output
    setConsoleColor(7, 0);
    for (int i = 0; i < MAX_LINES; i++) {
        if (text[i][0] != '\0') {
            gotoxy(startX + 2, startY + 1 + i);
            printf("%s", text[i]);
        }
    }
}

int main() {
    char text[MAX_LINES][MAX_LENGTH] = {{0}};
    int line = 0;
    int cursor_pos = 0;
    int boxWidth = 50;
    int boxHeight = 10;
    int centerPosX = getCenterPosition(boxWidth);
    int centerPosY = 5;
    int outputPosY = centerPosY + boxHeight + 3;

    printf("Start typing. Use arrow keys to navigate. Press Enter to display:\n");

    while (1) {
        int ch = getch();
        system("cls");
        drawBox(boxWidth, boxHeight, centerPosX, centerPosY, 1);

        for (int i = 0; i <= line; i++) {
            setConsoleColor(14, 0);
            gotoxy(centerPosX + 2, centerPosY + 2 + i);
            printf("%s", text[i]);
        }
        setConsoleColor(7, 0);

        switch (ch) {
            case 224:
                ch = getch();
                switch (ch) {
                    case 72:  // UP arrow
                        if (line > 0) line--;
                        cursor_pos = (cursor_pos > strlen(text[line])) ? strlen(text[line]) : cursor_pos;
                        break;
                    case 80:  // DOWN arrow
                        if (line < MAX_LINES - 1) line++;
                        cursor_pos = (cursor_pos > strlen(text[line])) ? strlen(text[line]) : cursor_pos;
                        break;
                    case 75:  // LEFT arrow
                        if (cursor_pos > 0) cursor_pos--;
                        break;
                    case 77:  // RIGHT arrow
                        if (cursor_pos < strlen(text[line])) cursor_pos++;
                        break;
                    case 83:  // DELETE key
                        if (cursor_pos < strlen(text[line])) {
                            for (int i = cursor_pos; i < strlen(text[line]); i++) {
                                text[line][i] = text[line][i + 1];
                            }
                        }
                        break;
                }
                break;
            case '\b':  // BACKSPACE key
                if (cursor_pos > 0) {
                    for (int i = cursor_pos - 1; i < strlen(text[line]); i++) {
                        text[line][i] = text[line][i + 1];
                    }
                    cursor_pos--;
                }
                break;
            case '\r':  // ENTER key
                system("cls");
                drawBox(boxWidth, boxHeight, centerPosX, centerPosY, 1);
                printTextOutput(text, boxWidth, centerPosX, outputPosY);  // Print text in output box
                line = 0;
                cursor_pos = 0;
                memset(text, 0, sizeof(text));  // Clear text after printing
                break;
            default:
                if (isprint(ch)) {
                    if (strlen(text[line]) < MAX_LENGTH - 1) {
                        for (int i = strlen(text[line]); i > cursor_pos; i--) {
                            text[line][i] = text[line][i - 1];
                        }
                        text[line][cursor_pos++] = ch;
                    }
                }
                break;
        }
        setConsoleColor(14, 0);
        gotoxy(centerPosX + 2 + cursor_pos, centerPosY + 2 + line);
        setConsoleColor(7, 0);
    }
}
