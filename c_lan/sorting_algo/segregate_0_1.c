#include <stdio.h>
// {0,1,1,0,1}

// 1st Method
void sort_array(int *arr, int size) {
    int *start = arr;
    int *end = arr + (size - 1);
    int temp;

    while (start < end) {
        if (*start == 0) {
            start++;
        } else if (*end == 1) {
            end--;
        } else {
            // Swap values
            temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }
}

// 2nd Method
void segregate0and1(int arr[], int n) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        while (arr[lo] == 0 && lo < hi) lo++;
        while (arr[hi] == 1 && lo < hi) hi--;
        if (lo < hi) {
            int temp = arr[lo];
            arr[lo] = arr[hi];
            arr[hi] = temp;
            lo++;
            hi--;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort_array(arr, n);
    //segregate0and1(arr, n);
    printf("Array after segregation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
