#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i = 0; i <= 15; i++)
        printf("%d\t%#o\t%#x\n", i, i, i);
    return 0;
}
