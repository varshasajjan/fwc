#include <stdio.h>

int multiply(int a, int b) {
    int result = 0;
    int positive = 1;
    if (b < 0) { b = -b; positive = -1; }
    for (int i = 0; i < b; i++) result += a;
    return positive * result;
}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("Product = %d\n", multiply(x, y));
    return 0;
}
