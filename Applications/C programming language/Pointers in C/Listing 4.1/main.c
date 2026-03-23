#include <stdio.h>
int main()
{
    int var1 = 1025;
    int *int_ptr = &var1;

    printf("Address of var1: %p\n", &var1);
    printf("Value of int_ptr: %p\n", int_ptr);
    printf("Address of int_ptr: %p\n", &int_ptr);
    printf("Value of var1: %d\n", *int_ptr);
    printf("Value of *int_ptr: %d\n", *int_ptr);
    printf("Value of &*int_ptr: %p and of *&int_ptr: %p\n", &*int_ptr, *&int_ptr);

    return 0;
}
