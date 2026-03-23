#include <stdio.h>

int reverse(int num, int *i);

int main()
{
    int v = 0, n = 0, result = 0;
    printf("Enter an integer number: ");
    scanf("%d", &n);
    result = reverse(n, &v);
    if(v == 1)
        printf("The reverse of %d is: 0%d", n, result);
    else
        printf("The reverse of %d is: %d", n, result);
    return 0;
}

int reverse(int num, int *i)
{
    static int rev = 0;
    if(num != 0)
    {
        if(rev == 0 && num % 10 == 0)
            *i = 1;
        rev = rev * 10 + num % 10;
        return reverse(num / 10, i);
    }
    else
        return rev;
}
