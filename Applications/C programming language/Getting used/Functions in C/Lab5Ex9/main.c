#include <stdio.h>
#include <math.h>
#define PI 3.1415

float circumference(float radius);
float area(float radius);
float volume(float radius);

int main()
{
    float (*f_ptr[3])(float) = {circumference, area, volume};
    int ch = 0;
    float radius = 0, value = 0;
    printf("\n\tMENU\n\n1.The circumference\n2. The area\n3. The volume\nEnter any value for exit.\n\n\n");
    printf("Select your option. Enter a value between 1 and 3 or other values for exit: ");
    scanf("%d", &ch);

    while(ch >= 1 && ch < 4)
    {
        system("cls");
        printf("Enter the value of the radius: ");
        scanf("%f", &radius);
        value = (*f_ptr[ch - 1])(radius);
        printf("\nThe result of your option is: %f", value);
        printf("\n\n\n\tMENU\n\n1.The circumference\n2. The area\n3. The volume\nEnter any value for exit.\n\n\n");
        printf("Select your new option. Enter a value between 1 and 3 or other values for exit: ");
        scanf("%d", &ch);
    }
    return 0;
}

float circumference(float radius)
{
    return 2 * PI * radius;
}

float area(float radius)
{
    return PI * radius * radius;
}

float volume(float radius)
{
    return (4 * PI * pow(radius, 3))/3;
}
