#include <stdio.h>

long long power(int a, int n) {
    long long result = 1;
    for (int i = 0; i < n; i++)
        result *= a;
    return result;
}

int main() {
    int a, n;
    printf("Enter base and power: ");
    scanf("%d %d", &a, &n);
    printf("%d^%d = %lld\n", a, n, power(a, n));
    return 0;
}
