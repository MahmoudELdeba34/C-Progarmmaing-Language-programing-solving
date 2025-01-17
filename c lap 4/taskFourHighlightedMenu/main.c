#include <stdio.h>
#include <conio.h>
#include <windows.h> // Needed for textcolor functions on Windows

// Function to set the text color and background color
void setTextColor(int textColor, int backgroundColor) {
    int colorAttribute = (backgroundColor << 4) | textColor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorAttribute);
}

// Function to display the menu with the highlighted item
void displayMenu(int highlight) {
    const char *menuItems[] = {"1. Start Game", "2. Options", "3. Help", "4. Exit"};
    int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);

    system("cls"); // Clear the screen
    printf("Use Arrow Keys to navigate and Enter to select:\n\n");

    for (int i = 0; i < menuSize; i++) {
        if (i == highlight) {
            setTextColor(0, 15); // Highlighted item (white text on black background)
        } else {
            setTextColor(15, 0); // Normal item (black text on white background)
        }
        printf("%s\n", menuItems[i]);
    }
    setTextColor(15, 0); // Reset text color
}

int main() {
    int highlight = 0;
    int ch;
    const char *menuItems[] = {"1. Start Game", "2. Options", "3. Help", "4. Exit"};

    while (1) {
        displayMenu(highlight);

        ch = getch();
        if (ch == 27) { // ESC key to exit
            printf("\nExiting the program...\n");
            break;
        } else if (ch == 224) { // Arrow keys start with 224
            ch = getch();
            switch (ch) {
                case 72: // Up arrow
                    highlight = (highlight == 0) ? 3 : highlight - 1;
                    break;
                case 80: // Down arrow
                    highlight = (highlight == 3) ? 0 : highlight + 1;
                    break;
            }
        } else if (ch == 13) { // Enter key
            system("cls");
            printf("You selected: %s\n", menuItems[highlight]);
            if (highlight == 3) { // Exit option selected
                printf("\nExiting the program...\n");
                break;
            }
            printf("Press any key to return to the menu...\n");
            getch(); // Wait for a key press to return to the menu
        }
    }
    return 0;
}
