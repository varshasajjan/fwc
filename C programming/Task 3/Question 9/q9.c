#include <stdio.h>

typedef struct {
    int d, m, y;
} Date;

int isOlder(Date a, Date b) {
    if (a.y < b.y) return 1;
    if (a.y > b.y) return 0;
    if (a.m < b.m) return 1;
    if (a.m > b.m) return 0;
    return a.d < b.d;
}

int main() {
    Date d1, d2;
    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &d1.d, &d1.m, &d1.y);
    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &d2.d, &d2.m, &d2.y);

    if (isOlder(d1, d2)) printf("First date is older\n");
    else printf("Second date is older\n");
    return 0;
}
