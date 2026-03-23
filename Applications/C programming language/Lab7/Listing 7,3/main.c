#include <stdio.h>
#include <stdlib.h>

union number{
    int a;
    double b;
} value;

int main(void)
{
    value.a = 100;
    printf("%s\n %d \t %.2f\n", "You inserted a value in the integer member of the union number and print the values of both its members.", value.a, value.b);
    value.b = 100.00;
    printf("\n%s\n %d \t %.2f\n", "You inserted a value in the double member of the union number and print the values of both its members.", value.a, value.b);
    return 0;
}
