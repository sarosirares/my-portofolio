#include <stdio.h>
#define SIZE 10

int max(int size, int *array);
int min(int size, int *array);

int main()
{
    int a[SIZE] = {0};
    int maximum = 0, minimum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        printf("a[%d]= ", i);
        scanf("%d", &a[i]);
    }
    maximum = max(SIZE, a);
    minimum = min(SIZE, a);
    printf("\nThe maximum value is: %d\n", maximum);
    printf("\nThe minimum value is: %d\n", minimum);
    return 0;
}

int max(int size, int *array)
{
    int maximum = array[0];
    for(int i = 0; i < size; i++)
    {
        if(array[i] > maximum)
            maximum = array[i]; // *(array + i) == array[i]
    }
    return maximum;
}

int min(int size, int *array)
{
    int minimum = array[0];
    for(int i = 0; i < size; i++)
    {
        if(array[i] < minimum)
            minimum = array[i]; // *(array + i) == array[i]
    }
    return minimum;
}
