#include <stdio.h>

int main() {
    int num;
    int *ptr = &num;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", ptr);  // Store input directly at the address pointed to by ptr

    // Output the value entered by the user
    printf("You entered: %d\n", *ptr);

    return 0;
}

