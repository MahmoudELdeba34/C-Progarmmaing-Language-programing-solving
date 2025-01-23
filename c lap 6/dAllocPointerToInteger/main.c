#include <stdio.h>
#include <stdlib.h> // For malloc

int main() {
    int *ptr;

    // Allocate memory using malloc
    ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read a value from the user
    printf("Enter an integer value: ");
    scanf("%d", ptr);

    // Print the entered value
    printf("The entered value is: %d\n", *ptr);

    // Free the allocated memory
    free(ptr);

    return 0;
}
