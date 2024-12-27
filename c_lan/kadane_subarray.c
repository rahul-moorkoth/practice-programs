#include <stdio.h>

/*
 * Kadane's Algorithm is a well-known algorithm for solving the maximum subarray sum problem.
 * This problem involves finding the contiguous subarray within a one-dimensional array of
 * numbers (containing at least one positive number) which has the largest sum.
 */

int maxSubArraySum(int arr[], int n) {
    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    for (int i = 1; i < n; i++) {
        max_ending_here = (arr[i] > max_ending_here + arr[i]) ? arr[i] : max_ending_here + arr[i];
	printf("%d ",max_ending_here);
        max_so_far = (max_ending_here > max_so_far) ? max_ending_here : max_so_far;
    }

    return max_so_far;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 7, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArraySum(arr, n);
    printf("Maximum contiguous subarray sum is %d\n", max_sum);

    return 0;
}
