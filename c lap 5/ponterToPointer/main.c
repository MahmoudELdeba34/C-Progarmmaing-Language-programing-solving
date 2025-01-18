#include <stdio.h>

int main() {
    int num;
    int *ptr = &num;         // Pointer to integer
    int **ptr_to_ptr = &ptr; // Pointer to pointer to integer

    // Get value from user
    printf("Enter an integer: ");
    scanf("%d", *ptr_to_ptr); // Using ptr_to_ptr to store input in num

    // Display values
    printf("\nYou entered: %d\n", num);
    printf("Value using *ptr: %d\n", *ptr);
    printf("Value using **ptr_to_ptr: %d\n", **ptr_to_ptr);

    // Display addresses
    printf("\nAddress of num: %p\n", (void*)&num);
    printf("Address stored in ptr (address of num): %p\n", (void*)ptr);
    printf("Address stored in ptr_to_ptr (address of ptr): %p\n", (void*)ptr_to_ptr);

    return 0;
}
