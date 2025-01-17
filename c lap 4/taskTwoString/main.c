#include <stdio.h>
// task two reverse String
// Function to calculate the length of a string
int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to reverse a string in place
void reverseString(char *str) {
    int length = stringLength(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        // Swap characters
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char message[50];

    // Get the message from the user
    printf("Enter message: ");
    int i = 0;
    char ch;
    while (i < 49 && (ch = getchar()) != '\n' && ch != EOF) {
        message[i] = ch;
        i++;
    }
    message[i] = '\0'; // Null-terminate the string

    // Reverse the message
    reverseString(message);

    // Print the reversed message
    printf("Reversed message: %s\n", message);

    return 0;
}
