#include <stdio.h>
int main()
{
    float n = 0.0f;

    printf("Enter a real value for n: ");
    scanf("%f", &n);

    if(n < -1)
    {
        printf("\nThe value for the function is: %f\n", (n*n + 4*n + 8));
    }
    else
    {
        if(n == -1)
        {
            printf("\nThe value for the function is: 0\n");
        }
        else
        {
            if(n > -1)
            {
                printf("\nThe value for the function is: %f\n", (n*n - 5*n + 1));
            }
        }
    }
    return 0;
}
