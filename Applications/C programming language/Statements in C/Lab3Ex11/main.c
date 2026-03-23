#include <stdio.h>
#define SIZE 5
int main()
{
    int array[SIZE], i = 0, j = 0, aux = 0;

    printf("Enter %d values of the array: \n", SIZE);

    for( i = 0; i < SIZE; i++ )
    {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    for( i = 0; i < SIZE; i++ )
    {
        for( j = i + 1; j < SIZE; j++ )
        {
            if(array[i] > array[j])
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    printf("\nThe array in ascending order is: \n");

    for( i = 0; i < SIZE; i++ )
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}
