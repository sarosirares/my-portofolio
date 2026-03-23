#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char *string;
    int n = 0;
    printf("Introduce the number of characters: ");
    scanf("%d", &n);

    string = (char *)malloc(n * sizeof(char));

    printf("Introduce a string of characters: ");
    scanf("%s", string);

    for(int i = 0; i < n; i++)
    {
        if(islower(string[i]))
                string[i] = string[i] - 32;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%c", string[i]);
    }
    free(string);
    return 0;
}
