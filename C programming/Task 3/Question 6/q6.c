#include <stdio.h>
#include <ctype.h>

int fun_alpha_num(char c) {
    return isalnum(c);
}

int main() {
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);

    if (fun_alpha_num(c)) printf("%c is alphanumeric\n", c);
    else printf("%c is NOT alphanumeric\n", c);
    return 0;
}
