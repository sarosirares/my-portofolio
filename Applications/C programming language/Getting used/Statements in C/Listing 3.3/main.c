#include <stdio.h>
int main()
{
    int grade = 0;

    printf("Enter one of the following A, a ,B, b, C, c, D, d, E, e, F, f: ");
    grade = getchar();
    switch(grade)
    {
        case 'a':
        case 'A': printf("Grade in the following interval [9, 10].\n");
            break;
        case 'b':
        case 'B': printf("Grade in the following interval [8, 9).\n");
            break;
        case 'c':
        case 'C': printf("Grade in the following interval [7, 8).\n");
            break;
        case 'd':
        case 'D': printf("Grade in the following interval [6, 7).\n");
            break;
        case 'e':
        case 'E': printf("Grade in the following interval [5, 6).\n");
            break;
        case 'f':
        case 'F': printf("Grade in the following interval [0, 5). Failed.\n");
            break;
        default: printf("You entered an invalid grade!");
    }
    return 0;
}
