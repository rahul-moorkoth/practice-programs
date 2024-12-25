#include <stdio.h>

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    int original = num;  // Store the original number
    int reversed = 0;

    // Reverse the number
    while (num != 0) {
        reversed = reversed * 10 + num % 10;  // Add the last digit to reversed
        num /= 10;                            // Remove the last digit
    }

    // Check if the original number is equal to its reversed version
    return original == reversed;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("The number %d is a palindrome.\n", num);
    } else {
        printf("The number %d is not a palindrome.\n", num);
    }

    return 0;
}
