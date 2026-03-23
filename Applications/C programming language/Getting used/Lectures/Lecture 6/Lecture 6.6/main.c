#include <stdio.h>
unsigned int fibonacci_no_recursion(unsigned int);
unsigned int fibonacci_recursion(unsigned int);
int main()
{
    unsigned int no_terms = 0;
    for(no_terms = 0; no_terms < 20; no_terms++)
        printf("%d\t", fibonacci_no_recursion(no_terms));
    printf("\n");
    for(no_terms = 0; no_terms < 20; no_terms++)
        printf("%d\t", fibonacci_recursion(no_terms));
    return 0;
}

unsigned int fibonacci_no_recursion(unsigned int n)
{
    unsigned int i = 0, x = 1, y = 0, z = 0;
    if((n == 0) || (n == 1))
        return n;
    for(i = 2; i <= n; i++)
    {
        z = x;
        x+=y;
        y = z;
    }
    return x;
}

unsigned int fibonacci_recursion(unsigned int n)
{
    if((n == 0) || (n == 1))
        return n;
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}
