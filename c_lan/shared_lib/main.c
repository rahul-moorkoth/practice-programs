#include <stdio.h>

// Declare the functions provided by the shared library
int add(int a, int b);
int subtract(int a, int b);

int main() {
    int x = 10, y = 5;
    printf("Add: %d\n", add(x, y));
    printf("Subtract: %d\n", subtract(x, y));
    return 0;
}
