#include <stdio.h>

#define PI 3.14159
#define FRAC 4.0f/3.0f

float radius, volume;

int main(void)
{
    printf("Please enter the radius of the sphere: ");
    scanf("%f", &radius); 
    volume = FRAC * (PI * (radius * radius * radius));
    printf("%.2f", volume);
}
