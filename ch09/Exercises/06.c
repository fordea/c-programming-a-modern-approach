#include <stdio.h>

int digit(int, int);

int main(void)
{
    printf("Digit %d (from right) in %d: %d", 4, 82934, digit(82934, 4));
    return 0;
}

/* Return the kth digit in n (from the right) */
int digit(int n, int k)
{
    int digit;

    while (k > 0) {
        digit = n % 10;
        n /= 10;
        k--;
    }
    return digit;
}
