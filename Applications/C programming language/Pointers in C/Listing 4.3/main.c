#include <stdio.h>

int main()
{
    int array[2][5] = {{1, 2, 3, 4, 5},
                       {6, 7, 8, 9, 10}};
    int (*ptr)[5] = array;
    int *p = array;

    printf("p = %p, ptr = %p\n", p, ptr);
    printf("array[0][0] = %d, array[0] = %p, array[0][0] = %d\n", *p, *ptr, **ptr);

    p++; /* p  = p + 4 */
    ptr++; /* ptr = ptr + 20 */

    printf("p = %p, ptr = %p\n", p, ptr);
    printf("array[0][1] = %d, array[1] = %p, array[1][0] = %d\n", *p, *ptr, **ptr);
    return 0;
}
