*Note down the differences between Call by Value and Call by Reference and when to use what?

1. Call by Value:
In this method, the actual value of the argument is passed to the function.
Inside the function, a new copy of that value is created.
Any changes made to the parameter do not affect the original variable in main().
Memory-wise, both original variable and function parameter exist in different memory locations.

2. Call by Reference:
In this method, the address (reference) of the variable is passed to the function.
Inside the function, we directly access the original variable using pointers.
Any changes made to the parameter reflect directly in the original variable.
Memory-wise, only one copy exists — the function works with the same variable as in main().
