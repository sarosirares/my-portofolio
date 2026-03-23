#include <stdio.h>
int main()
{
    int   n = 1, even = 0, odd = 0;
    float sume = 0.0f, sumo = 0.0f;

    printf("Enter integer values: ");

    while(n != 0)
    {
        scanf("%d", &n);
        if(n % 2 == 0)
        {
            if(n != 0)
            {
                even++;
                sume = sume + n;
            }
        }
        else
        {
            odd++;
            sumo = sumo + n;
        }
    }
        printf("\nThe number of even integers is: %d\n", even);

    if(even != 0)
    {
        printf("\nThe average value of even integers is: %f\n", sume/even);
    }

    printf("\nThe number of odd integers is: %d\n", odd);

    if(odd != 0)
    {
        printf("\nThe average value of even integers is: %f\n", sumo/odd);
    }
    return 0;
}
