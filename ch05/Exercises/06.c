#include <stdio.h>

int main(void)
{
    int n;
    n = 5;

    if (n == 1-10)
        printf("n is between 1 and 10\n");

/*  Again, this if statement above behaves differently to what we want it to accomplish
 *  (n == 1-10) evaluates to (n == (1-10)) as the additive operand has
 *  a higher precedence (5) than the equality operand (8).
 *  So what is really happening is checking if n is equivalent to -9, therefore
 *  this printf statement would only execute if n had the value -9.
 */

    return 0;
}
