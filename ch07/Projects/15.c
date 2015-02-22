#include <stdio.h>

int main(void)
{
    int i, n;
    long double factorial = 1.0f;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        factorial *= i;
    }

    printf("Factorial of %d: %.0lf", n, factorial);

    return 0;
}
/* (a) Largest value of n that correctly prints its factorial (short): 7
 * (b) Largest value of n that correctly prints its factorial (int): 12
 * (c) Largest value of n that correctly prints its factorial (long): 12
 * (c) Largest value of n that correctly prints its factorial (long long): 12
 * (e) Largest value of n that correctly prints its factorial (float): 34
 * (f) Largest value of n that correctly prints its factorial (double): 170
 * (f) Largest value of n that correctly prints its factorial (long double): 1754
 */
