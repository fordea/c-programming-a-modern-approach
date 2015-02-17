#include <stdio.h>

int main(void)
{
    int i;
    i = 17;

    printf("%d\n", i >= 0 ? 1 : -1);
/*  The above print statement contains a Conditional Expression (or ternary opeartor)
 *  This is essentially a condensed if/else statement in the form:
 *  Condition to check ? evaluate if true : evaluate if false
 *
 *  So the above printf statement
 *  means if (i >= 0) ? print 1 :else print -1. So therefore when i is 17, 1 is printed
 *  as 17 is greater than or equal to 0. However if the value of i is -17 it prints -1
 *  because -17 is not greater than or equal to 0.
 */

    return 0;
}
