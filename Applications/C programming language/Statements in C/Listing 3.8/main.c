#include <stdio.h>
#define MAX 3
int main()
{
    double number = 0.0, sum = 0.0;
    int    i = 0;

    printf("Computes sum of %d real numbers. Negative numbers are skipped from calculation.\n", MAX);
    for( i = 0; i < MAX; i++)
    {
        printf("Enter the n%d real number: ", i+1);
        scanf("%lf", &number);
        if(number < 0)
            continue;
        sum += number;
    }
    printf("The sum of the positive numbers is %.2lf.\n", sum);
    return 0;
}
