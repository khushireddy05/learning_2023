#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int computeTotalSeconds(const char* timeStr) {
    int hours, minutes, seconds;

    // Use sscanf to extract hour, minute, and second components
    sscanf(timeStr, "%d:%d:%d", &hours, &minutes, &seconds);

    // Calculate total seconds
    int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;

    return totalSeconds;
}

int main() {
    const char* timeStr = "12:34:56";

    int totalSeconds = computeTotalSeconds(timeStr);

    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}
