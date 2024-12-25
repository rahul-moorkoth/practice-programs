#include <stdio.h>

#define MY_SIZEOF(type)  ((char *)(&type + 1) - (char *)(&type))

int main() {
    int a;
    double b;
    char c;

    printf("Size of int: %d bytes\n", MY_SIZEOF(a));
    printf("Size of double: %d bytes\n", MY_SIZEOF(b));
    printf("Size of char: %d byte\n", MY_SIZEOF(c));

    return 0;
}

