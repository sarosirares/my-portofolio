#include <stdio.h>

int main()
{
    int number = 5, *ptr = &number, **ptr_ptr = &ptr;
    printf("Address of ptr_ptr: %p\n", &ptr_ptr);
    printf("Value of ptr_ptr: %p\n", ptr_ptr);
    printf("Address of ptr: %p\n", &ptr);
    printf("Value of ptr: %p\n", ptr);
    printf("Address of number: %p\n", &number);
    printf("Value of number: %d\n", **ptr_ptr);
    printf("Value of number: %d\n", *ptr);
    printf("Value of number: %d\n", number);
    return 0;
}
