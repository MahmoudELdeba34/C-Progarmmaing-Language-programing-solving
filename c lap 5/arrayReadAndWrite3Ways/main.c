#include <stdio.h>

int main() {
    int arr[5];
    int *ptr = arr;  // Pointer to the first element of the array

    // Getting values from the user
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &arr[i]);  // Store user input directly in the array
    }

    // Method 1: Using Array Indexing with Pointers
    printf("\nMethod 1: Array Indexing with Pointers\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);  // Access using ptr[i]
    }
    printf("\n");

    // Modify array using array indexing with pointer
    for (int i = 0; i < 5; i++) {
        ptr[i] += 5;  // Add 5 to each element
    }

    // Display updated values
    printf("Updated values after Method 1:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Method 2: Using Pointer Arithmetic
    printf("\nMethod 2: Pointer Arithmetic\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));  // Access using *(ptr + i)
    }
    printf("\n");

    // Modify array using pointer arithmetic
    for (int i = 0; i < 5; i++) {
        *(ptr + i) += 10;  // Add 10 to each element
    }

    // Display updated values
    printf("Updated values after Method 2:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Method 3: Using Pointer Incrementation
    printf("\nMethod 3: Pointer Incrementation\n");
    ptr = arr;  // Reset pointer to the beginning of the array
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);  // Access the value at the current pointer location
        ptr++;  // Move to the next element
    }
    printf("\n");

    // Modify array using pointer incrementation
    ptr = arr;  // Reset pointer to the beginning of the array
    for (int i = 0; i < 5; i++) {
        *ptr += 15;  // Add 15 to the current element
        ptr++;  // Move to the next element
    }

    // Display updated values
    printf("Updated values after Method 3:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


//Array Indexing: ptr[i]
// Pointer Arithmetic: *(ptr + i)
// Pointer Incrementation: *ptr with ptr++
