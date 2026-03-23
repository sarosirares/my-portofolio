#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char var = 0;
    double result = 0.0;
    double n = 0, power = 0;
    char string[50] = {"9851243"};
    printf("Enter a character value for the variable var: ");
    scanf("%c", &var);
    if(isdigit(var)) // 1
        printf("\nThe variable var is a digit.\n");
    if(isalpha(var)) // 2
    {
        printf("\nThe variable var is a letter ");
        if(islower(var)) // 3
            printf("and it is a lowercase one.\n");
        if(isupper(var)) // 4
            printf("and it is an uppercase one.\n");
    }

    printf("\nEnter an integer: ");
    scanf("%lf", &n);
    printf("\nEnter another integer: ");
    scanf("%lf", &power);
    printf("%lf raised to the power of %lf is %lf", n, power, pow(n, power)); // 5
    printf("\nThe square root of %lf is: %lf", n, sqrt(n)); // 6
    printf("\nThe natural logarithm of %lf is: %lf", n, log(n)); // 7
    printf("\nThe of the radian angle %lf is: %lf\n", n, sin(n)); // 8
    result = atof(&string);
    printf("%lf is the converted value of the string %s to double.\n", result, string); // 9
    printf("%d is the converted value of the string %s to int.\n", atoi(string), string); // 10

    return 0;
}
