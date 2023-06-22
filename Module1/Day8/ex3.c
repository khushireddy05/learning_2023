/*Data Viewer:
Write an application to view the log stored in data.csv
Example, say you have the following data in data.csv

------------------------------------

EntryNo,sensorNo,Temperature,Humidity,Light,

1,S1,36.5,100,50,10:30:50
2,S3,30,100,50,10:30:55
3,S2,-6.6,100,10,10:31:00
------------------------------------

a. Write a function to extract each line in the .csv file and store it in an array of structures. 

b. Also implement functions to display the contents of the array of structures.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

// Function to extract each line in the CSV file and store it in the array of structures
void extractLogEntries() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (numEntries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached. Some data may be truncated.\n");
            break;
        }

        LogEntry *entry = &logEntries[numEntries];

        char *token = strtok(line, ",");
        entry->entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(entry->sensorNo, token, sizeof(entry->sensorNo));

        token = strtok(NULL, ",");
        entry->temperature = atof(token);

        token = strtok(NULL, ",");
        entry->humidity = atoi(token);

        token = strtok(NULL, ",");
        entry->light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(entry->timestamp, token, sizeof(entry->timestamp));

        numEntries++;
    }

    fclose(file);
}

// Function to display the contents of the array of structures
void displayLogEntries() {
    for (int i = 0; i < numEntries; i++) {
        LogEntry *entry = &logEntries[i];
        printf("Entry No: %d\n", entry->entryNo);
        printf("Sensor No: %s\n", entry->sensorNo);
        printf("Temperature: %.2f\n", entry->temperature);
        printf("Humidity: %d\n", entry->humidity);
        printf("Light: %d\n", entry->light);
        printf("Timestamp: %s\n", entry->timestamp);
        printf("------------------------\n");
    }
}

int main() {
    extractLogEntries();
    displayLogEntries();

    return 0;
}
