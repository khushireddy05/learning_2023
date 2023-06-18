#include <stdio.h>

int findDifference(int arr[], int size) {
    int sumEven = 0;
    int sumOdd = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            // Add even element to the sumEven
            sumEven += arr[i];
        } else {
            // Add odd element to the sumOdd
            sumOdd += arr[i];
        }
    }

    // Calculate the difference
    int difference = sumEven - sumOdd;

    return difference;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int difference = findDifference(arr, size);

    printf("Difference between even and odd elements: %d\n", difference);

    return 0;
}
