#include <stdio.h>

int main() {
    int mat1[3][3], mat2[3][2], result[3][2] = {0};

    // Get elements for the first matrix (3x3)
    printf("Enter elements for the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Get elements for the second matrix (3x2)
    printf("Enter elements for the 3x2 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    // Multiply mat: result[i][j] = sum of (mat1[i][k] * mat2[k][j])
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Print the result (3x2 matrix)
    printf("Resultant 3x2 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
