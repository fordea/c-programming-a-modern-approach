#include <stdio.h>

int main(void)
{
    int n;
    n = 0;

    if (n >= 1 <= 10)
        printf("n is between 1 and 10\n");

/*  The above if statement is legal, however it doesn't behave as we expect
 *  What it evaluates to is ((n >= 1) <= 10), so when n is 0 it evaluates to:
 *  (0 <= 10) -> 1 (true). However we only want it to return 'true' when
 *  n is between 1 & 10 inclusive.
 *
 *  To implement the behavior we want to compare n to both 1 and 10, and then ensure that both
 *  are true by using the logical and operator '&&':
 */

    if (n >= 1 && n <=10) //Relational operators have a higher precedence (7) than Logical and (12)
        printf("n is guaranteed to be between 1 and 10 if this printf is executed\n");

    return 0;
}
