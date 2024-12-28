#include <stdio.h>

int bitwise_multiply(int a, int b) {
    int result = 0; // Initialize the result to 0

    // Loop until b becomes 0
    while (b != 0) {
        // If the least significant bit of b is 1, add a to the result
        if (b & 1) {
            result += a;
        }

        // Shift a to the left (equivalent to a * 2)
        a <<= 1;

        // Shift b to the right (equivalent to b / 2)
        b >>= 1;
    }

    return result;
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Call the bitwise multiplication function
    int product = bitwise_multiply(num1, num2);

    // Print the result
    printf("Product of %d and %d = %d\n", num1, num2, product);

    return 0;
}
