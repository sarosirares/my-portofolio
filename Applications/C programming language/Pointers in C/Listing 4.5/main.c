#include <stdio.h>

int main()
{
    char *string[2] = {"computer", "programming"};
    int  i = 0, j = 0;
    printf("string + 0 = %p.\n", string + 0);
    printf("string + 1 = %p.\n", string + 1);
    printf("*(string + 0) = %p.\n", *(string + 0));
    printf("*(string + 1) = %p.\n", *(string + 1));

    printf("Pointer offset notation:\n");
    for(i = 0; i < 2; i++)
    {
        printf("String started at *(string + %d) is %s.\n", i, *(string + i));
        for(j = 0; j < strlen(*(string + i)); j++)
            printf("*(*(string + %d) + %d) is %c at address *(string + %d) + %d = %p.\n", i, j, *(*(string + i) + j), i, j, *(string + i) + j);
    }
    return 0;
}
