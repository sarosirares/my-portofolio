#include <stdio.h>
#include <stdlib.h>

//a

struct test{
    int test_number;
    char test_name[30];
};

typedef struct test Test; //b

int main()
{
    Test a, b[10], *ptr; //c

    printf("Introduce a test number and a test name: \n");
    scanf("%d %s", &a.test_number, a.test_name); //d

    b[2] = a; //e

    ptr = &b[2]; //f

    printf("The member values of element 3 of the array are: %d and %s\n", (*ptr).test_number, ptr->test_name); //g

    return 0;
}
