#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0, i = 0, sum = 0, new_size = 0;
    int *ptr = NULL;

    printf("Enter the number of elements of an array: ");
    scanf("%d", &number);
    ptr = (int *)malloc(number * sizeof(int));

    if(ptr == NULL)
    {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    printf("Enter the elements of the array: ");
    for(i = 0; i < number; i++)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Sum of the array's elements is: %d.", sum);

    printf("\nThe addresses of the allocated memory are:\n");
    for(i = 0; i < number; i++)
    {
        printf("Address of the %d element with value %d is %p.\n", i, *(ptr + i), ptr + i);
    }

    printf("\nEnter the new size of the array: ");
    scanf("%d", &new_size);
    ptr = realloc(ptr, new_size);

    if(ptr == NULL)
    {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    sum = 0;
    printf("Enter the new elements of the array: ");
    for(i = 0; i < new_size; i++)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Sum of the array's elements is: %d.", sum);

    printf("\nThe addresses of the new allocated memory are: \n");
    for(i = 0; i < new_size; i++)
        printf("Address of the %d element with value %d is %p.\n", i, *(ptr + i), ptr + i);
    free(ptr);
    return 0;
}
