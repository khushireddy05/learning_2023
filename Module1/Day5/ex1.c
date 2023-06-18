#include <stdio.h>
#include <ctype.h>

void changeCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            // Convert uppercase to lowercase
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            // Convert lowercase to uppercase
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char str[] = "Hello World";

    printf("Original string: %s\n", str);

    changeCase(str);

    printf("Modified string: %s\n", str);

    return 0;
}
