#include <stdio.h>

int main() {
    int arr[10];

    //  user enter 10 integers
    printf("Enter 10 integers:\n");

    // Reading values into the array
    for (int i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the values entered
    printf("\nThe integers you entered are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
