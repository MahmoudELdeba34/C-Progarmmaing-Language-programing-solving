#include <stdio.h>

// Function to copy one string to another
void copyString(char *source, char *destination) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

// Function to concatenate two strings
void concatStrings(char *destination, char *source) {
    int i = 0, j = 0;
    // Move to the end of the destination string
    while (destination[i] != '\0') {
        i++;
    }
    // Append source to destination
    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0';
}

// Function to read a line of input
void getInput(char *str, int size) {
    int i = 0;
    char ch;
    while (i < size - 1 && (ch = getchar()) != '\n' && ch != EOF) {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
}

int main() {
    char firstName[10], lastName[10], fullName[21];

    printf("Enter first name: ");
    getInput(firstName, 10);

    printf("Enter last name: ");
    getInput(lastName, 10);

    // Copy first name to full name
    copyString(firstName, fullName);

    // Concatenate a space between first and last name
    concatStrings(fullName, " ");

    // Concatenate last name to full name
    concatStrings(fullName, lastName);

    // Print the full name
    printf("Full name: ");
    puts(fullName);

    return 0;
}
