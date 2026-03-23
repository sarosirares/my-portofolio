#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Re;
    int Im;
}complex;

void read_complex(complex *nr);
void display_complex(complex *nr);
void add_complex(complex *nr);

int main()
{
    complex nr;

    read_complex(&nr);
    display_complex(&nr);
    add_complex(&nr);

    return 0;
}

void read_complex(complex *nr)
{
    printf("The real part is: ");
    scanf("%d", &(nr->Re));
    printf("The imaginary part is: ");
    scanf("%d", &(nr->Im));
}

void display_complex(complex *nr)
{
    printf("\nThe complex number is:\n");
    printf("%d + %di\n\n", nr->Re, nr->Im);
}

void add_complex(complex *nr)
{
    complex nr2, sum;
    read_complex(&nr2);
    sum.Re = nr->Re + nr2.Re;
    sum.Im = nr->Im + nr2.Im;
    display_complex(&sum);
}
