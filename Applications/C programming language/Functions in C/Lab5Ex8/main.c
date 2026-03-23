#include <stdio.h>

void days (int y, int m, int d, int *dd, int *rdd);

int dm[2][12] = {{31, 29, 31 ,30, 31, 30, 31, 31, 30, 31, 30, 31},
                 {31, 28, 31 ,30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main()
{
    int y = 0; int m = 0; int d = 0; int dd = 0; int rdd = 0;
    printf("Enter a year, a month and a day: ");
    scanf("%d%d%d", &y, &m, &d);
    days(y, m, d, &dd, &rdd);
    printf("%d %d\n", dd, rdd);
    return 0;
}

void days (int y, int m, int d, int *dd, int *rdd)
{
    int leap = 0;
    leap = (y % 4 == 0) && (y && 100 != 0) || (y % 400 == 0);
    if(leap)
    {
        for(int i = 0; i < m -1; i++)
            *dd += dm[0][i];
        *dd += d;
        *rdd = 366 - *dd;
    }
    else
    {
        for(int i = 0; i < m -1; i++)
            *dd += dm[1][i];
        *dd += d;
        *rdd = 365 - *dd;
    }
}
