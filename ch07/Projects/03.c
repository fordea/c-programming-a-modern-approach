#include <stdio.h>

int main(void)
{
    double n, sum = 0.0f;

    printf("This program sums a series of doubles.\n");
    printf("Enter numbers (0 to terminate): ");

    scanf("%lf", &n);
    while (n != 0.0f) {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %lf\n", sum);

    return 0;
}
