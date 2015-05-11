#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float round_nearest(float num, int decimal_places);

int main(void)
{
    float num;
    int dp;
    printf("Enter a floating-point number and decimal places to round it to: ");
    if (scanf("%f %d", &num, &dp) != 2) {
        fprintf(stderr, "Enter a floating point number followed by a space, then the number of decimal places to round it to.\n");
        exit(EXIT_FAILURE);
    }
    num = round_nearest(num, dp);
    printf("Result: %.*f\n", dp, num);
    return 0;
}

float round_nearest(float num, int decimal_places)
{
    int power = pow(10, decimal_places);
    return nearbyint(num * power) / power;
}
