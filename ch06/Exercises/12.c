#include <stdio.h>

int main(void)
{
    int d, n, is_prime;

    is_prime = 1;
    n = 1429;
    printf("Checking if %d is prime\n", n);

    for (d = 2; (d * d) <= n; d++) {
        printf("Testing %d\n", d);

        if (n % d == 0) {
            is_prime = 0;
            break;
        }
    }

    printf("%d", is_prime);
    return 0;
}
