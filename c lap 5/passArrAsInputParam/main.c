#include <stdio.h>

#define SIZE 5  // Define the size of the array

// Function to fill an array by passing it as array[]
void fillArray(int array[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);  // Fill the array with user input
    }
}

// Function to display an array by passing a pointer
void displayArray(int *array, int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);  // Access each element using pointer notation
    }
    printf("\n");
}

int main() {
    int arr[SIZE];

    // Fill the array using fillArray (pass by array notation)
    fillArray(arr, SIZE);

    // Display the array using displayArray (pass by pointer notation)
    displayArray(arr, SIZE);

    return 0;
}
