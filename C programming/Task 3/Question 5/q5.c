#include <stdio.h>

int IsPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

void PrintAllPrimes(int a, int b) {
    printf("Prime numbers between %d and %d:\n", a, b);
    for (int i = a; i <= b; i++)
        if (IsPrime(i)) printf("%d ", i);
    printf("\n");
}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    PrintAllPrimes(x, y);
    return 0;
}
