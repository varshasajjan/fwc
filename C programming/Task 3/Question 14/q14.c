#include <stdio.h>

int square(int n) {
    int result = 0;
    for (int i = 0; i < n; i++) result += n;
    return result;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Square = %d\n", square(n));
    return 0;
}
