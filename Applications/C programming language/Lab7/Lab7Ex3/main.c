#include <stdio.h>
#include <stdlib.h>

struct test{
    int test_number;
    char test_name[30];
}; //a)

typedef struct test Test; //b) another way to define

int main()
{
    Test a, b[10], *ptr; //c)

    printf("Enter a test number and a test name: ");
    scanf("%d%s", &a.test_number, a.test_name);//d)

    b[2] = a;//e)

    ptr = b;//f)

    printf("%d; %s", (ptr + 2) -> test_number, (ptr + 2) -> test_name);//g)

    return 0;
}
