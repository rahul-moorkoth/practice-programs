#include <stdio.h>

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
    segregate0and1(arr, n);
    printf("Array after segregation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
