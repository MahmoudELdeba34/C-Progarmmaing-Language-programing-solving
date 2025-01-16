#include <stdio.h>

int main() {
    int mat1[3][2], mat2[2][1], result[3][1] = {0};

    // Get elements for the first matrix (3x2)
    printf("Enter elements for 3x2 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Get elements for the second matrix (2x1)
    printf("Enter elements for 2x1 matrix:\n");
    for (int i = 0; i < 2; i++) {
        printf("Element at [%d][0]: ", i);
        scanf("%d", &mat2[i][0]);
    }

    // Multiply mat: result[i][0] = mat1[i][0]*mat2[0][0] + mat1[i][1]*mat2[1][0]
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            result[i][j] = mat1[i][0] * mat2[0][j] + mat1[i][1] * mat2[1][j];
        }
    }

    // Print the result (3x1 matrix)
    printf("Resultant 3x1 matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\n", result[i][0]);
    }

    return 0;
}
