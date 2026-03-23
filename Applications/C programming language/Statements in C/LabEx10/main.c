#include <stdio.h>
int main()
{
    char option;
    float n1 = 0, n2 = 0;

    printf("\tMENU\n\n");
    printf("1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n5. Exit (q)");
    printf("\n\nEnter your option: ");
    scanf("%c", &option);

    while(option != 'q')
    {
        switch(option)
        {
        case '+':
            system("cls");
            printf("Enter two real numbers: ");
            scanf("%f%f", &n1, &n2);
            printf("%f + %f = %f", n1, n2, n1+n2);
            break;
        case '-':
            system("cls");
            printf("Enter two real numbers: ");
            scanf("%f%f", &n1, &n2);
            printf("%f - %f = %f", n1, n2, n1-n2);
            break;
        case '*':
            system("cls");
            printf("Enter two real numbers: ");
            scanf("%f%f", &n1, &n2);
            printf("%f * %f = %f", n1, n2, n1*n2);
            break;
        case '/':
            system("cls");
            printf("Enter two real numbers: ");
            scanf("%f%f", &n1, &n2);
            printf("%f / %f = %f", n1, n2, n1/n2);
            break;
        default:
            system("cls");
            printf("Invalid operation!");
            break;
        }
        printf("\n\n\tMENU\n\n");
        printf("1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n5. Exit (q)");
        printf("\n\nEnter your option: ");
        scanf(" %c", &option);
    }
    return 0;
}
