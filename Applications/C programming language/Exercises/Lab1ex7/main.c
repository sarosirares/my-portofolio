#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0, c = 0;

    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);

    printf("The product of %d, %d and %d is: %d\n", a, b, c, a*b*c);

    return 0;
}
