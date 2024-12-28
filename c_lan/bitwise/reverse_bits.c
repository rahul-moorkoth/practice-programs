#include <stdio.h>

unsigned int reverseBinary32Bit(unsigned int x) {
    unsigned int reversed = 0;

    for (int i = 0; i < 32; i++) {
        reversed = (reversed << 1) | (x & 1); // Shift reversed left and add the least significant bit of x
        x >>= 1; // Shift x right by 1
    }

    return reversed;
}

int main() {
    unsigned int x;
    printf("Enter a 32-bit number (0-4294967295): ");
    scanf("%u", &x); // Use %u for unsigned int input

    unsigned int result = reverseBinary32Bit(x);
    printf("Reversed binary as hexadecimal: 0x%08X\n", result);

    return 0;
}
