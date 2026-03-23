#include <stdio.h>

int main()
{
    //a
    double number1 = 10, number2;
    double *double_ptr;
    //b
    double_ptr = &number1;
    //c
    printf("The value pointed to by double_ptr is: %lf\n", *double_ptr); //The value pointed to by double_ptr is: 10
    //d
    number2 = *double_ptr;
    //e
    printf("The value of number2 is: %lf\n", number2); //The value of number2 is: 10
    //f
    printf("The address of number1 is: %p\n", &number1);
    //g
    printf("The address stored in double_ptr is: %p\n", double_ptr);

    return 0;
}
