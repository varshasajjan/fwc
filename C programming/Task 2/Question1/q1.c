#include <stdio.h>
#define PI 3.14159

// Define structure
struct CircleResult {
    float area;
    float perimeter;
};

// Function that takes radius and returns structure
struct CircleResult calculateCircle(float radius) {
    struct CircleResult result;
    result.area = PI * radius * radius;
    result.perimeter = 2 * PI * radius;
    return result;
}

int main() {
    float radius;
    printf("Enter radius of circle: ");
    scanf("%f", &radius);

    struct CircleResult res = calculateCircle(radius);

    printf("Area = %.2f\n", res.area);
    printf("Perimeter = %.2f\n", res.perimeter);

    return 0;
}
