#include <stdio.h>

int main() {
    // i  Define variables to represent the elements of the magic square
    int a1 = 8, a2 = 1, a3 = 6;
    int b1 = 3, b2 = 5, b3 = 7;
    int c1 = 4, c2 = 9, c3 = 2;

    // Print the magic square
    printf("3x3 Magic Square:\n");
    printf("%i %i %i\n", a1, a2, a3);
    printf("%i %i %i\n", b1, b2, b3);
    printf("%i %i %i\n", c1, c2, c3);

    // Check the sum of rows
    int rowSum1 = a1 + a2 + a3; // Sum first row
    int rowSum2 = b1 + b2 + b3; // Sum  second row
    int rowSum3 = c1 + c2 + c3; // Sum  third row

    // Check the sum of columns
    int colSum1 = a1 + b1 + c1; // Sum  first column
    int colSum2 = a2 + b2 + c2; // Sum  second column
    int colSum3 = a3 + b3 + c3; // Sum  third column

    // Check the sum of diagonals
    int diag1 = a1 + b2 + c3; // Sum  first diagonal
    int diag2 = a3 + b2 + c1; // Sum  second diagonal

    // Check if all sums equal 15
    if (rowSum1 == 15 && rowSum2 == 15 && rowSum3 == 15 &&
        colSum1 == 15 && colSum2 == 15 && colSum3 == 15 &&
        diag1 == 15 && diag2 == 15) {
        printf("It is a magic square.\n");
    } else {
        printf("Not a magic square.\n");
    }

    return 0;
}
