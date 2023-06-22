/*Case Handler:
Write a C program to copy a file by considering the user option to handle the text case
-u, to change file content to Upper Case
-l, to change file content to Lower Case
-s, to change file content to Sentence Case
if no options are passed then it should be a normal copy

Example, say we have a file f1 with the following content
f1:
-----------------------
This is the file data
testing Case copy
application
-----------------------

./cp -s f1 f2
f2:
-----------------------
This Is The Tile Data
Testing Case Copy
Application
-----------------------

./cp -l f1 f3
f3:
-----------------------
this is the tile data
testing case copy
application
-----------------------

./cp -u f1 f4
f4:
-----------------------
THIS IS THE FILE DATA
TESTING CASE COPY
APPLICATION
-----------------------

./cp f1 f5
Should perform a normal copy*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert content to upper case
void convertToUpper(FILE *source, FILE *destination) {
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}

// Function to convert content to lower case
void convertToLower(FILE *source, FILE *destination) {
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}

// Function to convert content to sentence case
void convertToSentence(FILE *source, FILE *destination) {
    char ch;
    int sentenceStart = 1;

    while ((ch = fgetc(source)) != EOF) {
        if (sentenceStart && isalpha(ch)) {
            ch = toupper(ch);
            sentenceStart = 0;
        } else if (ch == '.' || ch == '?' || ch == '!') {
            sentenceStart = 1;
        } else {
            ch = tolower(ch);
        }

        fputc(ch, destination);
    }
}

int main(int argc, char *argv[]) {
    FILE *sourceFile, *destinationFile;
    char *sourcePath, *destinationPath;
    char *option = NULL;

    // Check if the user provided the option
    if (argc < 3) {
        printf("Usage: %s [option] sourcefile destinationfile\n", argv[0]);
        printf("Options:\n");
        printf("  -u: Convert content to upper case\n");
        printf("  -l: Convert content to lower case\n");
        printf("  -s: Convert content to sentence case\n");
        return 1;
    }

    option = argv[1];
    sourcePath = argv[2];
    destinationPath = argv[3];

    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    destinationFile = fopen(destinationPath, "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (option != NULL) {
        if (option[0] == '-' && option[1] != '\0') {
            switch (option[1]) {
                case 'u':
                    convertToUpper(sourceFile, destinationFile);
                    break;
                case 'l':
                    convertToLower(sourceFile, destinationFile);
                    break;
                case 's':
                    convertToSentence(sourceFile, destinationFile);
                    break;
                default:
                    printf("Invalid option.\n");
                    fclose(sourceFile);
                    fclose(destinationFile);
                    return 1;
            }
        } else {
            printf("Invalid option.\n");
            fclose(sourceFile);
            fclose(destinationFile);
            return 1;
        }
    } else {
        // No option provided, perform a normal copy
        char ch;
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, destinationFile);
        }
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
