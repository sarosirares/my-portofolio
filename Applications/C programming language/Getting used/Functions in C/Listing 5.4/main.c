#include <stdio.h>

void print_int(int);

int main()
{
    void (*f_ptr)(int);

    f_ptr = &print_int;
    f_ptr(2);
    (*f_ptr)(2);
    return 0;
}

void print_int(int x){
    printf("%d\n", x);
}
