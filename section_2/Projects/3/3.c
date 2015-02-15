#include <stdio.h>

#define pi 3.14159
#define frac 4.0f/3.0f

int main(void)
{
    float radius;
    printf("Please enter the radius of the sphere: ");
    scanf("%f", &radius); 
    float vol = frac * (pi * (radius * radius * radius));
    printf("%.2f", vol);
}
