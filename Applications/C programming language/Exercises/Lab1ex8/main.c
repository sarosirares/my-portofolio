#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a = 0.0f, b = 0.0f;

    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);

    printf("The addition is: %f\nThe subtraction is: %f\nThe multiplication is: %f\nThe division is: %f\nThe average is: %f\n", a+b, a-b, a*b, a/b, (a+b)/2);

    return 0;
}
