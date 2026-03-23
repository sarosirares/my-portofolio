#include <stdio.h>
#define SIZE 5
int main()
{
    int array[SIZE], j = 0, i = 0, aux = 0;
    int *array_ptr = array;

    printf("Enter %d values of the array: \n", SIZE);

    for( i = 0; i < SIZE; i++ )
    {
        printf("array[%d] = ", i);
        scanf("%d", array + i);
    }

    for( i = 0; i < SIZE; i++ )
    {
        for( j = i + 1; j < SIZE; j++)
        if(*(array_ptr + i) > *(array_ptr + j))
        {
            aux = *(array_ptr + i) ;
            *(array_ptr + i) = *(array_ptr + j);
            *(array_ptr + j) = aux;
        }
    }

    printf("\nThe array in ascending order is: \n");

    for( i = 0; i < SIZE; i++ )
    {
        printf("array[%d] = %d\n", i, *(array_ptr + i));
    }

    return 0;
}
