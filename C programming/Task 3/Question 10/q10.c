#include <stdio.h>

int isLeap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int daysInMonth(int m, int y) {
    if (m == 2) return isLeap(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

int main() {
    int m, y;
    printf("Enter month and year: ");
    scanf("%d %d", &m, &y);
    printf("Days = %d\n", daysInMonth(m, y));
    return 0;
}
