#include <stdio.h>
int main()
{
    /*int int_array[3] = {1, 2, 3};
    int i = 0;
    int *int_array_ptr[3];

    for (i = 0; i < 3; i++)
    {
        int_array_ptr[i] = (int_array + i);
    }
    for (i = 0; i < 3; i++)
    {
        printf("Value of int_array[%d] = %d\n", i, *int_array_ptr[i]);
    }
    */
    char *string[3] = {"computer", "programming", "C language"};
    int i = 0;

    for( i = 0; i<3; i++)
    {
        printf("Value of string[%d] is %s.\n", i, string[i]);
    }
    return 0;
}
