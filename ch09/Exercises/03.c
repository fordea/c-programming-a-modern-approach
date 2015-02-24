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
    int remainder;
    
    while (n > 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    return m;
}
