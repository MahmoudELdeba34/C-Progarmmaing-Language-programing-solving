#include <stdio.h>

int main() {
    int rows, cols;

    // Get the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    // Get the elements from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    // Calculate the average of each column
    printf("Average of each column:\n");
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += arr[i][j];
        }
        float average = (float)sum / rows;
        printf("Column %d average: %.2f\n", j, average);
    }

    return 0;
}

