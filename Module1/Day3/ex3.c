/*Find the largest number by deleting single digit in a 4 digit number 5872 - 872, 9856 - 986

Concepts to be used.
- Loops
- Operators*/


#include <stdio.h>

int findLargestNumber(int num);

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNumber = findLargestNumber(num);

    printf("Largest Number: %d\n", largestNumber);

    return 0;
}

int findLargestNumber(int num) {
    int largestNumber = 0;
    int divisor = 1;

    while (divisor <= 1000) {
        int currentNumber = (num / divisor / 10) * divisor + (num % divisor);
        if (currentNumber > largestNumber) {
            largestNumber = currentNumber;
        }
        divisor *= 10;
    }

    return largestNumber;
}
