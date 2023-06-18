#include <stdio.h>
#include <regex.h>

int isValidEmail(const char* email) {
    regex_t regex;
    int ret;

    // Regular expression pattern for email validation
    char* pattern = "^[A-Za-z0-9]+([._]?[A-Za-z0-9]+)*@[a-z]+\\.[a-z]+$";

    // Compile the regular expression
    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    // Execute the regular expression
    ret = regexec(&regex, email, 0, NULL, 0);

    // Free the compiled regular expression
    regfree(&regex);

    if (!ret) {
        return 1;  // Email is valid
    } else if (ret == REG_NOMATCH) {
        return 0;  // Email does not match the pattern
    } else {
        fprintf(stderr, "Error in regex matching\n");
        return 0;
    }
}

int main() {
    const char* email = "test@example.com";

    if (isValidEmail(email)) {
        printf("Valid email format\n");
    } else {
        printf("Invalid email format\n");
    }

    return 0;
}
