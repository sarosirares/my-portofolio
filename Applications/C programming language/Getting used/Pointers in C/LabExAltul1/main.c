#include <stdio.h>
#define SIZE 10

int main()
{
    char string[SIZE] = {'\0'};
    char *string_ptr = string;

    //gets(string);

    scanf("%s", string); //TeSt

    while(*string_ptr != '\0')
    {
        if((*string_ptr >= 'a') && (*string_ptr <= 'z'))
            *string_ptr -= 32;
        else
            *string_ptr += 32;

        string_ptr++;
    }

    printf("%s", string);


    return 0;
}
