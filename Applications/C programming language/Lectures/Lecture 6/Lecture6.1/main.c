#include <stdio.h>

int square(int);

int main()
{
    int n = 2;
    int (*fptr1)(int);

    fptr1 = square;

    printf("%d squared is %d.\n", n, fptr1(n));

    printf("%d squared is %d.\n", n, (*fptr1)(n));
    return 0;
}

int square(int num)
{
    return num * num;
}
