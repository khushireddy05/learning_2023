/*Write a function to display all members in the above array of structures*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); // Clearing the newline character from the input buffer
    
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    
    // Assume the students' details are already initialized
    
    displayStudents(students, size);
    
    free(students);
    
    return 0;
}
