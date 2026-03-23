#include <stdio.h>
int main()
{
    unsigned int mask = 1 << 31, i = 0, number = 0;

    printf("Enter an unsigned integer: ");
    scanf("%u", &number);
    printf("\n%d in bits is: ", number);

    for( i = 0; i <= 31; i++ )
    {
        if(mask & number)
            printf("%d", 1);
        else
            printf("%d", 0);
        mask = mask >> 1;
    }
    return 0;
}
