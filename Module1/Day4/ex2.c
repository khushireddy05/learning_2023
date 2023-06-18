#include <stdio.h>

void findMinMax(int arr[], int size, int *min, int *max) {
    // Initialize min and max with the first element of the array
    *min = arr[0];
    *max = arr[0];

    // Iterate over the array elements starting from the second element
    for (int i = 1; i < size; i++) {
        // Update min if a smaller element is found
        if (arr[i] < *min)
            *min = arr[i];

        // Update max if a larger element is found
        if (arr[i] > *max)
            *max = arr[i];
    }
}

int main() {
    int arr[] = {10, 5, 7, 13, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, size, &min, &max);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
