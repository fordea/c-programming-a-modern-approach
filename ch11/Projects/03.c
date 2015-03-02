#include <stdio.h>

void reduce(int numerator, int denominator,
            int *reduced_numerator,
            int *reduced_denominator);

int main(void)
{
    int num, denom, reduced_numerator = 0, reduced_denominator = 0;

    printf("Enter a fraction: ");
    scanf("%d /%d", &num, &denom);

    reduce(num, denom, &reduced_numerator, &reduced_denominator); 

    printf("In lowest terms: %d/%d", reduced_numerator, reduced_denominator);

    return 0;
}

void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator)
{
    int temp, m = numerator, n = denominator;

    while (n != 0) {
       temp = m % n;
       m = n;
       n = temp;
    }

    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
}
