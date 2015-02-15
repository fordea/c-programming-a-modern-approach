#include <stdio.h>

#define pi 3.14159
#define frac 4.0f/3.0f

int main(void)
{
    float vol = frac * (pi * (10 * 10 * 10));
    printf("%.2f", vol);
}
