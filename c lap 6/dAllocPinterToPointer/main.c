#include <stdio.h>
#include <stdlib.h> // For malloc

int main() {
    int **arr;
    int rows = 3;
    int cols = 4;

    // Allocate memory for an array of pointers (for each row)
    arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation for rows failed.\n");
        return 1;
    }

    // Allocate memory for each row (each with 'cols' elements)
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation for row %d failed.\n", i);
            // Free previously allocated rows before exiting
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
    }

    // Read values into the array from the user
    printf("Enter values for a 3x4 array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the array
    printf("\nThe entered 3x4 array is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]); // Free each row
    }
    free(arr); // Free the row pointers array

    return 0;
}
