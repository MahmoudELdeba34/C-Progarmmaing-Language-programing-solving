#include <stdio.h>

// Function  for pass-by-value swap
void swap_by_value(int a, int b);

// Function  for pass-by-address swap
void swap_by_address(int *a, int *b);

// Function to get values from user
void get_values_from_user(int *x, int *y);

int main() {
    int num1, num2;

    // Get values from user
    get_values_from_user(&num1, &num2);

    // Display original values
    printf("\nOriginal values:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    // Swap by value
    swap_by_value(num1, num2);
    printf("\nAfter swap_by_value:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    // Swap by address
    swap_by_address(&num1, &num2);
    printf("\nAfter swap_by_address:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

// Function to swap values by value
    int temp = a;
    a = b;
    b = temp;
    // This swap only affects copies of the values
}

// Function to swap values by address
void swap_by_address(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to get values from the user
void get_values_from_user(int *x, int *y) {
    printf("Enter first integer: ");
    scanf("%d", x);  // Store input directly in the address of x
    printf("Enter second integer: ");
    scanf("%d", y);  // Store input directly in the address of y
}
