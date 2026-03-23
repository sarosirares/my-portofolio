#include <stdio.h>

int sum_digits(int no);
int sum_digits_rec(int no);

int main()
{
    int n = 0, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("The sum of the digits is: %d", sum_digits(n));\
    printf("\nThe sum of the digits using recursion is: %d", sum_digits_rec(n));
    return 0;
}

int sum_digits(int no)
{
    int sum = 0;
    int last_digit = 0;

    while(no != 0)
    {
        last_digit = no % 10;
        sum += last_digit;
        no = no / 10;
    }

    return sum;
}

int sum_digits_rec(int no)
{
    if(no != 0){
        return no % 10 + sum_digits_rec(no / 10);
    }
    else return 0;
}
