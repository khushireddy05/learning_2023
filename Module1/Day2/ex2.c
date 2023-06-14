/*Write a program to swap any type of data passed to an function.

Topics to be covered
- Pointers
- Type Casting*/

#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char* temp = (char*)malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

int main() {
    int num1 = 10, num2 = 20;
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    float float1 = 3.14, float2 = 1.618;
    printf("Before swap: float1 = %.2f, float2 = %.2f\n", float1, float2);
    swap(&float1, &float2, sizeof(float));
    printf("After swap: float1 = %.2f, float2 = %.2f\n", float1, float2);

    char char1 = 'A', char2 = 'B';
    printf("Before swap: char1 = %c, char2 = %c\n", char1, char2);
    swap(&char1, &char2, sizeof(char));
    printf("After swap: char1 = %c, char2 = %c\n", char1, char2);

    return 0;
}
