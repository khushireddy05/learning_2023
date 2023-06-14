/*Write a program to read the 
    - Roll No
    - Name (Note, you should read full name of the student including initials)
    - Marks of Physics, Math and Chemistry
    Calculate the total, percentage and print the summary.

 */


#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    float phy, maths, chem;
    float total, percentage;

    printf("Enter Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Marks in Physics: ");
    scanf("%f", &phy);

    printf("Enter Marks in Maths: ");
    scanf("%f", &maths);

    printf("Enter Marks in Chemistry: ");
    scanf("%f", &chem);

    total = phy + maths + chem;
    percentage = (total / 300) * 100;

    printf("\n** Student Summary **\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics: %.2f\n", phy);
    printf("Maths: %.2f\n", maths);
    printf("Chemistry: %.2f\n", chem);
    printf("Total: %.2f\n", total);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
