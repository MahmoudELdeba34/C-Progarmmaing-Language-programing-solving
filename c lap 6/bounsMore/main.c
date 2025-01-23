#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX_LENGTH 50
#define MAX_FIELDS 6

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

void printTextOutput(char fields[MAX_FIELDS][MAX_LENGTH], char text[MAX_FIELDS][MAX_LENGTH], int width, int startX, int startY) {
    setConsoleColor(2, 0);
    gotoxy(startX, startY - 1);  // Display title above output box
    printf("Your data you entered is:");
    drawBox(width, MAX_FIELDS + 2, startX, startY, 2);
    setConsoleColor(7, 0);
    for (int i = 0; i < MAX_FIELDS; i++) {
        if (text[i][0] != '\0') {
            gotoxy(startX + 2, startY + 1 + i);
            printf("%s%s", fields[i], text[i]);
        }
    }
}

int main() {
    char fields[MAX_FIELDS][MAX_LENGTH] = {
        "ID: ", "Name: ", "Age: ", "Salary: ", "Commission: ", "Deduction: "
    };
    char text[MAX_FIELDS][MAX_LENGTH] = {{0}};
    int field_count = MAX_FIELDS;
    int line = 0;
    int cursor_pos = strlen(fields[line]);
    int boxWidth = 50;
    int boxHeight = field_count + 2;
    int centerPosX = getCenterPosition(boxWidth);
    int centerPosY = 7;
    int outputPosY = centerPosY + boxHeight + 4;

    printf("Please enter your data:\n");

    while (1) {
        int ch = getch();
        system("cls");
        gotoxy(centerPosX, centerPosY - 2);  // Title above input box
        printf("Please enter your data:");
        drawBox(boxWidth, boxHeight, centerPosX, centerPosY, 1);

        for (int i = 0; i < field_count; i++) {
            setConsoleColor(14, 0);
            gotoxy(centerPosX + 2, centerPosY + 1 + i);
            printf("%s%s", fields[i], text[i]);
        }
        setConsoleColor(7, 0);

        switch (ch) {
            case 224:
                ch = getch();
                switch (ch) {
                    case 72:  // UP arrow
                        if (line > 0) line--;
                        cursor_pos = strlen(fields[line]) + strlen(text[line]);
                        break;
                    case 80:  // DOWN arrow
                        if (line < field_count - 1) line++;
                        cursor_pos = strlen(fields[line]) + strlen(text[line]);
                        break;
                    case 75:  // LEFT arrow
                        if (cursor_pos > strlen(fields[line])) cursor_pos--;
                        break;
                    case 77:  // RIGHT arrow
                        if (cursor_pos < strlen(fields[line]) + strlen(text[line])) cursor_pos++;
                        break;
                    case 83:  // DELETE key
                        if (cursor_pos > strlen(fields[line]) && cursor_pos < strlen(fields[line]) + strlen(text[line])) {
                            for (int i = cursor_pos - strlen(fields[line]); i < strlen(text[line]); i++) {
                                text[line][i] = text[line][i + 1];
                            }
                        }
                        break;
                }
                break;
            case '\b':  // BACKSPACE key
                if (cursor_pos > strlen(fields[line])) {
                    for (int i = cursor_pos - strlen(fields[line]) - 1; i < strlen(text[line]); i++) {
                        text[line][i] = text[line][i + 1];
                    }
                    cursor_pos--;
                }
                break;
            case '\r':  // ENTER key
                system("cls");
                printTextOutput(fields, text, boxWidth, centerPosX, outputPosY);  // Print text in output box
                line = 0;
                cursor_pos = strlen(fields[line]);
                memset(text, 0, sizeof(text));  // Clear text after printing
                break;
            default:
                if (isprint(ch) && strlen(text[line]) < MAX_LENGTH - 1) {
                    for (int i = strlen(text[line]); i > cursor_pos - strlen(fields[line]); i--) {
                        text[line][i] = text[line][i - 1];
                    }
                    text[line][cursor_pos - strlen(fields[line])] = ch;
                    cursor_pos++;
                }
                break;
        }

        setConsoleColor(14, 0);
        gotoxy(centerPosX + cursor_pos, centerPosY + 1 + line);
        setConsoleColor(7, 0);
    }
}
