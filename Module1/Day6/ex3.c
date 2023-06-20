/*Write a program using structures to calculate the difference between two time periods using a user-defined function.*/

#include <stdio.h>

// Structure to represent a time period
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time* t1, struct Time* t2) {
    struct Time difference;
    int totalSeconds1, totalSeconds2, diffSeconds;

    // Convert the time periods to total seconds
    totalSeconds1 = t1->hours * 3600 + t1->minutes * 60 + t1->seconds;
    totalSeconds2 = t2->hours * 3600 + t2->minutes * 60 + t2->seconds;

    // Calculate the difference in seconds
    diffSeconds = totalSeconds2 - totalSeconds1;

    // Convert the difference back to hours, minutes, and seconds
    difference.hours = diffSeconds / 3600;
    difference.minutes = (diffSeconds % 3600) / 60;
    difference.seconds = (diffSeconds % 3600) % 60;

    return difference;
}

int main() {
    struct Time time1, time2, difference;

    // Read the first time period
    printf("Enter the first time period (hours minutes seconds): ");
    scanf("%d %d %d", &(time1.hours), &(time1.minutes), &(time1.seconds));

    // Read the second time period
    printf("Enter the second time period (hours minutes seconds): ");
    scanf("%d %d %d", &(time2.hours), &(time2.minutes), &(time2.seconds));

    // Calculate the difference
    difference = calculateTimeDifference(&time1, &time2);

    // Print the difference
    printf("Time difference: %d hours, %d minutes, %d seconds\n",
           difference.hours, difference.minutes, difference.seconds);

    return 0;
}
