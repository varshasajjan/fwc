#include <stdio.h>

void swap(int *a, int *b);   // function prototype

int main() {
    int arr[2] = {10, 20};

    printf("Before swap: %d %d\n", arr[0], arr[1]);
    swap(&arr[0], &arr[1]);
    printf("After swap: %d %d\n", arr[0], arr[1]);

    return 0;
}
