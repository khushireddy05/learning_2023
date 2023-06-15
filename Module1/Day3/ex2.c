/*Prints Bits:
Scan a 32bit integer and prints its bits.

Concepts to be used.
- Loops
- Bitwise Operators*/

#include <stdio.h>

void printBits(unsigned int num);

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits: ");
    printBits(num);

    return 0;
}

void printBits(unsigned int num) {
    int i;
    unsigned int mask = 1 << 31;  // Start with the leftmost bit

    for (i = 0; i < 32; i++) {
        // Check if the bit is set (1) or not (0)
        int bit = (num & mask) ? 1 : 0;
        printf("%d", bit);

        // Shift the mask to the right by 1 position
        mask >>= 1;
    }

    printf("\n");
}
