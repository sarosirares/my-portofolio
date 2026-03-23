#include <stdio.h>
int main()
{
    int a = 2, b = 0;
    b = a++ + a-- + ++a + --a;
    printf("Value of a is %d and value of b is %d.", a, b);
    return 0;
}
