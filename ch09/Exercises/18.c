#include <stdio.h>

int gcd(int, int);

int main(void)
{
    printf("GCD of %d and %d: %d", 12, 28, gcd(12, 28));
    return 0;
}

/* Returns the greatest common divisor of the
 * two values m and n.
 */
int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}
