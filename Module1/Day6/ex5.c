/*Write a program to demonstrate the swapping the fields of two structures using pointers*/

#include <stdio.h>

// Structure to represent a student
struct Student {
    char name[50];
    int age;
};

// Function to swap the fields of two structures using pointers
void swapStructures(struct Student* s1, struct Student* s2) {
    struct Student temp;

    // Swap the name field
    strcpy(temp.name, s1->name);
    strcpy(s1->name, s2->name);
    strcpy(s2->name, temp.name);

    // Swap the age field
    temp.age = s1->age;
    s1->age = s2->age;
    s2->age = temp.age;
}

int main() {
    struct Student student1, student2;

    // Read the details for the first student
    printf("Enter the details for student 1:\n");
    printf("Name: ");
    scanf("%s", student1.name);
    printf("Age: ");
    scanf("%d", &(student1.age));

    // Read the details for the second student
    printf("\nEnter the details for student 2:\n");
    printf("Name: ");
    scanf("%s", student2.name);
    printf("Age: ");
    scanf("%d", &(student2.age));

    // Print the original details
    printf("\nOriginal details:\n");
    printf("Student 1: Name - %s, Age - %d\n", student1.name, student1.age);
    printf("Student 2: Name - %s, Age - %d\n", student2.name, student2.age);

    // Swap the structures
    swapStructures(&student1, &student2);

    // Print the swapped details
    printf("\nAfter swapping:\n");
    printf("Student 1: Name - %s, Age - %d\n", student1.name, student1.age);
    printf("Student 2: Name - %s, Age - %d\n", student2.name, student2.age);

    return 0;
}
