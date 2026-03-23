/*Pb2
#include <stdio.h>
int main()
{
    int number = 100;

    switch(number)
    {
        case 100:
        printf("Case 1");
        case 200:
        printf("Case 2");
        break;
        case number:
        printf("Case 3");
        break;
    }
    return 0;
}
*/

/*//Pb3
#include <stdio.h>
int main()
{
    unsigned short int i = 0;

    for(i <= 10 && i >= -1; ++i; i > 0)
        printf("%u ", i);
    return 0;
}
*/
/*Pb4
#include <stdio.h>
int main()
{
    int a = 1, b = 0;

    while(a <= 5)
    {
        b = 1;
        while(b <= a)
        {
            printf("%d", a);
            b = b + 1;
        }
        printf("\n");
        a = a + 1;
    }
    return 0;
}
*/
/*Pb5
#include <stdio.h>
int main()
{
    int a = 1;

    while(a <= 10)
    {
        printf("%d ", a);
        if(a > 3)
            break;
        a = a + 1;
    }
    printf("%d", a + 10);
    return 0;
}
*/
//Pb6
#include <stdio.h>
int main()
{
    int a = 1;

    while(a <= 10)
    {
        printf("%d ", a);
        if(a > 3 && a < 8)
            continue;
        a = a + 1;
    }
    printf("%d", a + 10);
    return 0;
}
