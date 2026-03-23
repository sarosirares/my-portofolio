#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    for(int i = 0; i <= 4; i++)
            printf("%d \t %d\n", (12345 / (int)pow(10, 4-i)), (12345 / (int)pow(10, i)));
    return 0;
}
