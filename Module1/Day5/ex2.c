#include <stdio.h>

int main() {
    char str[] = "12345";
    int num;

    sscanf(str, "%d", &num);

    printf("Converted number: %d\n", num);

    return 0;
}
