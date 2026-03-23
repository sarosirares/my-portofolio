#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B 2
int f(char *key)
{
    int i, sum;
    sum = 0;
    for(i = 0; i < strlen(key); i++)
        sum += key[i];
    return(sum % B);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
