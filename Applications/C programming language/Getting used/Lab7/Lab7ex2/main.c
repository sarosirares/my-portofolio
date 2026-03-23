#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test{
    char test_name[30];
    char test_description[100];
};

int main()
{
    struct test b[12];
    strcpy(b[4].test_name, "test? jfndsako");
    printf("%s", b[4].test_name);
    return 0;
}

