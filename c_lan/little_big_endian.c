#include <stdio.h>
#include <stdint.h>

// Generic function to swap bytes for endianness conversion
void swapEndianness(void* data, size_t size) {
    uint8_t* bytes = (uint8_t*)data;
    for (size_t i = 0; i < size / 2; i++) {
        uint8_t temp = bytes[i];
        bytes[i] = bytes[size - 1 - i];
        bytes[size - 1 - i] = temp;
    }
}

int main() {
    uint32_t num = 0x12345678;
    printf("Before Swap: 0x%X\n", num);

    swapEndianness(&num, sizeof(num));
    printf("After Swap : 0x%X\n", num);

    return 0;
}
