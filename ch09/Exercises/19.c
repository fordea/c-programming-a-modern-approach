#include <stdio.h>

void pb(int n);

int main(void)
{
    int n = 50;
    pb(n);
    return 0;
}

/* Function recursively divides a number by 2.
 * Once division has recursively evaluated to 0
 * the program returns up the stack frames printing
 * either a 0 or 1 by calculating the remainder of the division of n by 2
 * at that particular stack frame. */
void pb(int n)
{
    if (n != 0) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}
