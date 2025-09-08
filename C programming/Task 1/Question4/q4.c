// Write a function that can take two integers as input, and gives 5 outputs : addition, subtraction, multiplication, quotient and reminder of those two numbers.
// Print the outputs in the main function:

#include <stdio.h>

void operations(int a, int b, int *add, int *sub, int *mul, int *quot, int *rem) {
    *add = a + b;
    *sub = a - b;
    *mul = a * b;
    *quot = a / b;
    *rem = a % b;
}

int main() {
    int a = 20, b = 7;
    int add, sub, mul, quot, rem;

    operations(a, b, &add, &sub, &mul, &quot, &rem);

    printf("Addition = %d\n", add);
    printf("Subtraction = %d\n", sub);
    printf("Multiplication = %d\n", mul);
    printf("Quotient = %d\n", quot);
    printf("Remainder = %d\n", rem);

    return 0;
}
