#include <stdio.h>

float calc_amount(float p, float r, int months) {
    float time_years = months / 12.0;
    float si = (p * r * time_years) / 100.0;
    return p + si;
}

int main() {
    float p, r;
    int t;
    printf("Enter principle, rate, time(in months): ");
    scanf("%f %f %d", &p, &r, &t);

    printf("Total amount to be repaid = %.2f\n", calc_amount(p, r, t));
    return 0;
}
