#include <stdio.h>
#include <stdlib.h>

int main()
{
    float angle_radians, angle_degrees, seconds;
    int degrees, minutes;
    char o = 248;
    scanf("%f", &angle_radians);

    angle_degrees = angle_radians * 180/3.14;
    degrees = (int)angle_degrees;
    minutes = (int)((angle_degrees - degrees) * 60);
    seconds = (angle_degrees - degrees - (minutes / 60.0)) * 3600;

    printf("%d%c%d'%f\"", degrees, o, minutes, seconds);

    return 0;
}
