#include <stdio.h>
int main()
{
    int grade = 0;

    printf("Enter the number of points obtained at the exam: ");
    scanf("%d", &grade);
    if((grade >= 0) && (grade <= 10))
    {
        if(grade >= 9)
            printf("Passed with A.\n");
        else if(grade >= 8)
            printf("Passed with B.\n");
         else if(grade >= 7)
            printf("Passed with C.\n");
         else if(grade >= 6)
            printf("Passed with D.\n");
         else if(grade >= 5)
            printf("Passed with E.\n");
         else
            printf("Failed.\n");
    }
    else
    {
        printf("You entered an invalid grade!");
    }
    return 0;
}
