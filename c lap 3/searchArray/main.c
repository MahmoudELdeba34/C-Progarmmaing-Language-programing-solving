#include <stdio.h>

int main() {
    int n, target, found = -1;

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get the elements from the user
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target number to search
    printf("Enter the number to search for: ");
    scanf("%d", &target);

    //  search for the target in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = i;
            break;
        }
    }
    // Print the result
    if (found != -1) {
        printf("Number found at index: %d\n", found);
    } else {
        printf("Number not found in the array.\n");
    }

    return 0;
}
