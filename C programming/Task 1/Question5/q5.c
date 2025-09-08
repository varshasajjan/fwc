// "Write a function that communicates with main using a single static variable without taking any input arguments.
//  Everytime function returns something using the static variable,after using it, main sends another input using the same variable and calls the function again. eg., print the square of each number of an array : for each number of the array : call the function main gets the static variable address as return value from function.
// main puts the array element in static variable.
// in the function : create static variable. if static variable value is not zero, print its square. function sends static variable address back to main."


#include <stdio.h>

int* func() {
    static int var = 0;
    if (var != 0) {
        printf("Square: %d\n", var * var);
    }
    return &var;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *ptr;

    for (int i = 0; i < n; i++) {
        ptr = func();    // get address of static variable
        *ptr = arr[i];   // put array element in static variable
    }

    // One more call to print last element’s square
    func();

    return 0;
}
