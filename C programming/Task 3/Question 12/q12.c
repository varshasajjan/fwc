#include <stdio.h>
#include <ctype.h>

char CaseReverse(char c) {
    if (isupper(c)) return tolower(c);
    if (islower(c)) return toupper(c);
    return c;
}

int main() {
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);
    printf("Reversed case: %c\n", CaseReverse(c));
    return 0;
}
