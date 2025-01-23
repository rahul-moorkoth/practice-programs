#include <stdio.h>

/*
 * Original array: 1 2 0 4 3 0 5 0
 * Modified array: 0 0 0 1 2 4 3 5
*/

void moveZerosToLeft(int arr[], int n) {
    int j = n - 1; // Pointer to find non-zero elements from the right

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] != 0) {
            // Move the non-zero element to position `j` and decrement `j`
            arr[j--] = arr[i];
        }
    }

    // Fill the remaining positions (from 0 to j) with zeros
    while (j >= 0) {
        arr[j--] = 0;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    moveZerosToLeft(arr, n);

    printf("Modified array: ");
    printArray(arr, n);

    return 0;
}

