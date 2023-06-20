/*Assume User will be providing input in the form of a string as show below. 
Write a function in c to parse the string and initialize an array of structures. 

Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };

Note: User must be able define the no. of inputs/size of the array during runtime.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) {
    char temp[20];
    int i = 0;
    
    const char* delimiter = " ";
    char* token = strtok((char*)input, delimiter);

    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);
        
        token = strtok(NULL, delimiter);
        strcpy(students[i].name, token);

        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);
        
        token = strtok(NULL, delimiter);
        i++;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); // Clearing the newline character from the input buffer
    
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    
    char input[100];
    printf("Enter the student details (e.g., '1001 Aron 100.00'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Removing the newline character from the input
    
    parseString(input, students, size);
    
    // Printing the initialized structures
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
    
    free(students);
    
    return 0;
}
