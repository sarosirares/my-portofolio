#include <stdio.h>
void function1(int a);
void function2(int b);

int main()
{
    void(*fptr[2])(int) = {function1, function2};
    int choice = 0;

    printf("Enter a number between 1 and 2, 3 to end: ");
    scanf("%d", &choice);

    while(choice >= 1 && choice < 3)
    {
        (*fptr[choice - 1])(choice);
        printf("Enter a number between 1 and 2, 3 to end: ");
        scanf("%d", &choice);
    }
    printf("Program execution completed.\n");
    return 0;
}
void function1(int x)
{
    printf("You entered %d -- Function1 was called.\n", x);
}
void function2(int y)
{
    printf("You entered %d -- Function2 was called.\n", y);
}
