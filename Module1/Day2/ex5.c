/*Write a program to encode any given string such that it gets converted into an unrecognizable form. 
Also write a decode function to get back the original string.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encodeString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] += 1; 
    }
}

void decodeString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] -= 1;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Original String: %s\n", str);

    encodeString(str);
    printf("Encoded String: %s\n", str);

    decodeString(str);
    printf("Decoded String: %s\n", str);

    return 0;
}
