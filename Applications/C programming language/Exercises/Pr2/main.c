#include <stdio.h>
#include <string.h>



int main()
{

    return 0;
}

void copy_I(char *string)
{
    int i = 0;
    char *copied;
    copied = (char *)malloc(1 + strlen(string) * sizeof(char));

    for(i = 0; i <= strlen(string); i++)
    {
        *(copied + i) = *(string + i);
    }

    printf("The copied string is: %s\n", copied);
}

void copy_II(char *string)
{
    int i = 0;
    char copied[strlen(string) + 1];

    for(i = 0; i <= strlen(string); i++)
    {
        copied[i] = string[i];
    }

    printf("The copied string is: %s\n", copied);
}
