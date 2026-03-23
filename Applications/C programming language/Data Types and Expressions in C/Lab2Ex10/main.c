#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year;
    scanf("%d", &year);
    ((year % 4 == 0) && (year % 100 != 0)) ? (printf("%d is a leap year.", year)) : ((year % 400 == 0) ? (printf("%d is a leap year.", year)) : (printf("%d is a common year.", year)));
    return 0;
}
