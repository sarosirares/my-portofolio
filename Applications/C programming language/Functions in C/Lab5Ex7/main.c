#include <stdio.h>
#include <math.h>
#define SIZE 5

int perfect_square(int);

int main()
{
    int a[SIZE] = {0}, perfect[SIZE] = {0};
    int j = 0;
    for(int i = 0; i < SIZE; i++)
    {
        printf("a[%d]= ", i);
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < SIZE; i++)
    {
        if(perfect_square(a[i]) == 1)
        {
            perfect[j] = a[i];
            j++;
        }
    }
    if(j == 0)
    {
        printf("\nThere are no perfect square numbers.\n");
    }
    else
    {
        printf("\n\n");
        for(int i = 0; i < j; i++)
        {
            printf("perfect[%d]= %d\n", i, perfect[i]);
        }
    }
    return 0;
}

int perfect_square(int n)
{
    if((int)sqrt(n) == sqrt(n)) return 1;
    else return 0;
}
