#include <stdio.h>
#include <stdlib.h>

int main()
{
    float e = 2.718281;

    printf("%f\n", e);
    printf("%.2f\n", e);
    printf("%8.4f\n", e);
    printf("%ef\n", e);
    printf("%.9f\n", e);

    return 0;
}
