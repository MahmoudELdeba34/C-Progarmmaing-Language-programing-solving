#include <stdio.h>
#include <stdlib.h>


int** createArray(int rows, int cols) {
    int **array;


    array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL) {
        printf("Memory allocation for rows failed.\n");
        return NULL;
    }


    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation for row %d failed.\n", i);

            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }

    // Get values from the user
    printf("Enter values for a %dx%d array:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    return array;
}

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

    // Call function to create the array
    int **array = createArray(rows, cols);
    if (array == NULL) {
        printf("Failed to allocate memory for the array.\n");
        return 1;
    }

    // Print the array
    printArray(array, rows, cols);

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(array[i]); // Free each row
    }
    free(array); // Free the array of row pointers

    return 0;
}
