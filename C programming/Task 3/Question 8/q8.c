#include <stdio.h>

int isLeap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main() {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("%d is %s leap year\n", year, isLeap(year) ? "a" : "not a");
    return 0;
}
