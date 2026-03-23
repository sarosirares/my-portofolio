#include <stdio.h>
int main()
{
    unsigned int number = 0;
    unsigned int n_Bit = 0;

    printf("Enter an unsigned integer: ");
    scanf("%u", &number);
    printf("Enter the n-bit: ");
    scanf("%u", &n_Bit);

    printf("\nThe output is: %u\n", (1 << n_Bit) | number);

    return 0;
}
