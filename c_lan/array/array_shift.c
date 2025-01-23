#include <stdio.h>

void shiftArrayRight(int arr[], int size) {
    if (size <= 1) return; // No need to shift for arrays with size 0 or 1

    int last = arr[size - 1]; // Store the last element
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[0] = last; // Place the last element in the first position
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    shiftArrayRight(arr, size);

    printf("Shifted array:  ");
    printArray(arr, size);

    return 0;
}

