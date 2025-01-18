#include <stdio.h>

// Function to fill a static array and return a pointer to it
int* returnStaticArray(int size) {
    static int array[10]; // Static array with a fixed size
    if (size > 10) {
        printf("Size exceeds array limit. Returning first 10 elements.\n");
        size = 10; // Limit size to 10
    }

    // Fill the static array with user input
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]); // Fill the array with user input
    }

    return array; // Return pointer to the static array
}

// Function to fill an array passed as an argument
void fillArray(int array[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]); // Fill the array with user input
    }
}

// Function to display an array
void displayArray(int *array, int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]); // Access each element using pointer notation
    }
    printf("\n");
}

// Main function
int main() {
    int size;

    // Using static array approach
    printf("Using static array return:\n");
    printf("Enter the size of the array (max 10): ");
    scanf("%d", &size);

    int *staticArr = returnStaticArray(size);
    displayArray(staticArr, size); // Display contents of the static array

    // Using passed array approach
    printf("\nUsing passed array:\n");
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[10]; // Declare an array of fixed size
    fillArray(arr, size); // Fill the array by passing it to the function
    displayArray(arr, size); // Display contents of the passed array

    return 0;
}
