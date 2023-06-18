#include <stdio.h>

int findDifference(int arr[], int size) {
    int sumEvenIndex = 0;
    int sumOddIndex = 0;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            // Add element at even index to sumEvenIndex
            sumEvenIndex += arr[i];
        } else {
            // Add element at odd index to sumOddIndex
            sumOddIndex += arr[i];
        }
    }

    // Calculate the difference
    int difference = sumEvenIndex - sumOddIndex;

    return difference;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int difference = findDifference(arr, size);

    printf("Difference between elements at even and odd indices: %d\n", difference);

    return 0;
}
