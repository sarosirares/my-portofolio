#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
//Lab6Ex2.exe 3 5 7 9
//argc = 5
//argv[0] = "Lab6Ex2.exe"
//argv[1] = "3"
//argv[2] = "5"
//argv[3] = "7"
//argv[4] = "9"
{
    int sum = 0;
    int number = 0;

    for(int i = 1; i < argc; i++)
    {
        //number = atoi(argv[i]);
        sscanf(argv[i], "%d", &number);
        sum += number;

    }

    printf("The sum of the integer arguments is: %d\n", sum);

    return 0;
}
