#include <stdio.h>

int num_digits(int);

int main(void)
{
    printf("Number of digits in %d: %d", 1267123, num_digits(1267123)); 
    return 0;
}

/* Returns the number of digits in n */
int num_digits(int n)
{
    int digits = 0;

    while (n > 0) {
        n /= 10;
        digits++;
    }

    return digits;
}

