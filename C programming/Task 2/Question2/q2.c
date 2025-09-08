#include <stdio.h>

// Define structure
struct OperationResult {
    int addition;
    int subtraction;
    int multiplication;
    float quotient;
    int remainder;
};

// Function that takes two ints and returns structure
struct OperationResult calculateOperations(int a, int b) {
    struct OperationResult result;
    result.addition = a + b;
    result.subtraction = a - b;
    result.multiplication = a * b;
    result.quotient = (float)a / b;  // force float division
    result.remainder = a % b;
    return result;
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    struct OperationResult res = calculateOperations(x, y);

    printf("Addition = %d\n", res.addition);
    printf("Subtraction = %d\n", res.subtraction);
    printf("Multiplication = %d\n", res.multiplication);
    printf("Quotient = %.2f\n", res.quotient);
    printf("Remainder = %d\n", res.remainder);

    return 0;
}
