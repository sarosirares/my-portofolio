#include <stdio.h>

unsigned int factorial(unsigned int);

int main()
{
    unsigned int i = 0;

    printf("Enter an unsigned integer to calculate its factorial: ");
    scanf("%u", &i);
    printf("Factorial of %u is %u.\n", i, factorial(i));
    return 0;
}

unsigned int factorial(unsigned int i)
{
    if(i <= 1)
        return 1;
    else
        return i * factorial(i - 1);
}
