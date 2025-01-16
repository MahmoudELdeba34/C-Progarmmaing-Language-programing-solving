#include <stdio.h>

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};  // static array
    int n = sizeof(arr) / sizeof(arr[0]);  // Length of the array
    int max, min;

    // Initializing max and min to the first element
    max = arr[0];
    min = arr[0];

    // Finding the maximum and minimum values
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    // dispalying  the maximum and minimum values
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nMaximum Value: %d\n", max);
    printf("Minimum Value: %d\n", min);

    return 0;
}
