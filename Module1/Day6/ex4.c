/*write a program to Store Data for n students in Structures Dynamically. */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent student data
struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    int n; // Number of students
    struct Student* students; // Pointer to store array of students

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n students
    students = (struct Student*) malloc(n * sizeof(struct Student));

    // Read student data
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &(students[i].age));
        printf("Marks: ");
        scanf("%f", &(students[i].marks));
    }

    // Display student data
    printf("\nStudent Data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nDetails for student %d:\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
