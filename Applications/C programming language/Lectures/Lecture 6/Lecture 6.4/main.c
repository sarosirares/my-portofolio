#include <stdio.h>

typedef int(*Fptr)(int, int);

int sum(int, int);
Fptr convert(const char);

int main()
{
    char operation = '\0';
    Fptr result;

    printf("Insert a character: ");
    scanf("%c", &operation);
    if(operation == '+')
    {
        result = convert('+');
        printf("%d\n", result(2, 3));
    }
    else
    {
        printf("Input is not appropriate.\n");
    }
    return 0;
}

int sum(int a, int b)
{
    return a + b;
}
Fptr convert(const char code)
{
    if(code == '+')
        return &sum;
}
