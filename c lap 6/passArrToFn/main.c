#include <stdio.h>
#include <stdlib.h> // For malloc

// Function to print a 2D array
void printArray(int **array, int rows, int cols) {
    printf("\nThe 2D Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 3;
    int cols = 4;
    int **array;

    // Dynamically allocate memory for an array of pointers (for each row)
    array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL) {
        printf("Memory allocation for rows failed.\n");
        return 1;
    }

    // Allocate memory for each row (each with 'cols' elements)
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation for row %d failed.\n", i);
            // Free previously allocated rows before exiting
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return 1;
        }
    }

    // Get values from the user
    printf("Enter values for a 3x4 array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // Call the function to print the array
    printArray(array, rows, cols);

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(array[i]); // Free each row
    }
    free(array); // Free the row pointers array

    return 0;
}
