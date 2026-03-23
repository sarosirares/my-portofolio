#include <stdio.h>
#define SIZE 10

int main()
{
    char string[SIZE] = {'\0'}, inv[SIZE] = {'\0'};
    char *string_ptr = string, *inv_ptr = inv;
    int  length = 0;

    printf("Write a string: ");
    scanf("%s", string);

    while(*string_ptr != '\0')
    {
        string_ptr++;
        length++;
    }

    while(length > 0)
    {
        string_ptr--;
        *inv_ptr = *string_ptr;
        inv_ptr++;
        length--;
    }

    printf("\nThe inverted string is %s", inv);
    return 0;
}
