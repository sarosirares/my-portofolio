#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum number {one = 1, two, three, four, five};
    enum number x, y;
    int z = 0, w = 0;

    x = two;
    y = three;
    z = 2 * x + y;
    w = y - x;
    printf("z = %d w = %d\n", z, w);
    return 0;
}
