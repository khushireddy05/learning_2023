/*Write a program to find both smallest and largest digits in given n numbers
For example let's say we have n = 3, and n1 = 8, n2 = 156, n3 = 123450, the result will be "Not Valid", 1 and 6, 0 and 5*/

#include <stdio.h>

void findSmallestAndLargestDigits(int n, int numbers[]);

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    findSmallestAndLargestDigits(n, numbers);

    return 0;
}

void findSmallestAndLargestDigits(int n, int numbers[]) {
    int i;
    int smallestDigit = 9;  // Initialize with the largest possible digit
    int largestDigit = 0;   // Initialize with the smallest possible digit

    for (i = 0; i < n; i++) {
        int num = numbers[i];
        int tempNum = num;
        int currentSmallestDigit = 9;  // Initialize current smallest digit
        int currentLargestDigit = 0;   // Initialize current largest digit
        int hasValidDigits = 0;        // Flag to check if number has valid digits

        while (tempNum > 0) {
            int digit = tempNum % 10;

            if (digit < currentSmallestDigit) {
                currentSmallestDigit = digit;
            }

            if (digit > currentLargestDigit) {
                currentLargestDigit = digit;
            }

            tempNum /= 10;
            hasValidDigits = 1;
        }

        if (hasValidDigits) {
            if (currentSmallestDigit < smallestDigit) {
                smallestDigit = currentSmallestDigit;
            }

            if (currentLargestDigit > largestDigit) {
                largestDigit = currentLargestDigit;
            }
        }
    }

    if (smallestDigit == largestDigit) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
    }
}
