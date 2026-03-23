#include <stdio.h>

int reverse(int num);

int main()
{
    int n = 0;
    printf("Enter an integer number: ");
    scanf("%d", &n);
    printf("The reverse of %d is: %d", n, reverse(n));
    return 0;
}

int reverse(int num)
{
    static int rev = 0;
    if(num != 0)
    {
        rev = rev * 10 + num % 10;
        return reverse(num / 10);
    }
    else
        return rev;
}
