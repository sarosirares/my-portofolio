#include <stdio.h>

unsigned int is_even(unsigned int);
unsigned int is_odd(unsigned int);

int main()
{
    unsigned int i = 0;

    printf("Enter an unsigned integer to check if it is even or odd: ");
    scanf("%u", &i);
    if(is_even(i))
        printf("%u is even.", i);
    else
        printf("%u is odd.", i);
    return 0;
}

unsigned int is_even(unsigned int i)
{
    if(i == 0)
        return 1;
    else
        return is_odd(i - 1);
}

unsigned int is_odd(unsigned int i)
{
    if(i == 0)
        return 0;
    else
        return is_even(i - 1);
}
