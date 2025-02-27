#include <stdio.h>

int main() {
    char str[100]; // Assuming the maximum length of the string is 100 characters

    printf("Enter a string with spaces: ");
    scanf(" %[^\n]s", str);

    printf("You entered: %s\n", str);

    return 0;
}
