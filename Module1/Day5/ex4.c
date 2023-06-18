#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapYear(int year) {
    // Leap year if divisible by 4 and not divisible by 100, except if divisible by 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int countDaysElapsed(const char* dateStr) {
    int day, month, year;

    // Use sscanf to extract day, month, and year components
    sscanf(dateStr, "%d/%d/%d", &day, &month, &year);

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Update days in February if it's a leap year
    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    int totalDays = 0;

    // Count days in completed months
    for (int i = 1; i < month; i++) {
        totalDays += daysInMonth[i];
    }

    // Add days in the current month
    totalDays += day;

    return totalDays;
}

int main() {
    const char* dateStr = "18/06/2023";

    int daysElapsed = countDaysElapsed(dateStr);

    printf("Number of days elapsed in the year: %d\n", daysElapsed);

    return 0;
}
