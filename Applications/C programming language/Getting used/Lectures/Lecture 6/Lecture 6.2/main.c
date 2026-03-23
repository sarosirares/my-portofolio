#include <stdio.h>
void print(int);
void func(int, int, void(*)(int));

int main()
{
    int var_int = 0;
    int no = 0;

    printf(" Enter the integer you want to print: ");
    scanf("%d", &var_int);
    printf(" Enter how many times you want to print the integer %d: ", var_int);
    scanf("%d", &no);

    func(var_int, no, print);
    return 0;
}

void print(int x)
{
    printf("%d\n", x);
}

void func(int number, int no, void (*fptr)(int))
{
    int i = 0;
    for(i = 0; i < no; i++)
        (*fptr)(number);
}
