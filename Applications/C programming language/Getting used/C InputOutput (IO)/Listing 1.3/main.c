#include <stdio.h>
int main()
{
    char *input = "2 4 5.25", output[100] = " ";
    int a = 0, b = 0;
    float c = 0.0f, sum = 0.0f;

    sscanf(input, "%d%d%f", &a, &b, &c);
    printf("a = %d, b = %d c = %.2f\n", a, b, c);
    sum = a + b + c;
    sprintf(output, "%.2f", sum);
    printf("Sum of a, b and c is %s.\n", output);
    return 0;
}
