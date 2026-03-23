#include <stdio.h>

void fun_x(int x);
void fun_y(int y);
void fun_z(int z);

int main()
{
    void(*f_ptr[3])(int) = {fun_x, fun_y, fun_z};
    int ch = 0;

    printf("Enter a number between 1 and 3 or other integer value to end: ");
    scanf("%d", &ch);

    while(ch >= 1 && ch < 4)
    {
        (*f_ptr[ch - 1])(ch);
        printf("\nEnter a number between 1 and 3 or other integer value to end: ");
        scanf("%d", &ch);
    }
    return 0;
}

void fun_x(int x)
{
    printf("You entered %d -- fun_x was called.\n", x);
}

void fun_y(int y)
{
    printf("You entered %d -- fun_y was called.\n", y);
}

void fun_z(int z)
{
    printf("You entered %d -- fun_z was called.\n", z);
}
