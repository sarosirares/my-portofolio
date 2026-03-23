#include <stdio.h>
int main()
{
    int first_integer = 0, second_integer = 0, minimum = 0;

    printf("Enter two integers: ");
    scanf("%d %d", &first_integer, &second_integer);
    minimum = first_integer < second_integer ? first_integer : second_integer;
    printf("The minimum of %d and %d is %d.\n", first_integer, second_integer, minimum);
    return 0;

}
