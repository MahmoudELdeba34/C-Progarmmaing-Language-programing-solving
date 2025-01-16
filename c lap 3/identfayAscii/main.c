#include <stdio.h>

int main() {
    char ch;
    int ascii_value;

    // Get character input from the user
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Convert character to its ASCII value
    ascii_value = (int)ch;

    // Display the ASCII value
    printf("The ASCII value of '%c' is: %d\n", ch, ascii_value);

    return 0;
}
