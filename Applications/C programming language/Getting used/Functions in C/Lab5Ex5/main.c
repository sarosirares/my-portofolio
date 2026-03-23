#include <stdio.h>

int multiple(int, int);

int main()
{
    int nr1 = 0, nr2 = 0;
    for(int i = 0; i < 3; i++)
    {
        printf("Enter the pair no.%d:\n", i+1);
        scanf("%d%d", &nr1, &nr2);
        if(multiple(nr1, nr2) == 1)
            printf("%d is a multiple of %d.\n\n", nr2, nr1);
        else
            printf("%d is not a multiple of %d.\n\n", nr2, nr1);
    }

    return 0;
}

int multiple(int a, int b)
{
    if(b % a == 0) return 1;
    else return 0;
}
