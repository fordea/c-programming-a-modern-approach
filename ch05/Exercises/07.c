#include <stdio.h>

int main(void)
{
    int i;
    i = 17;

    printf("%d\n", i >= 0 ? i : -i);
/*  The above print statement contains a Conditional Expression (or ternary opeartor)
 *  This is essentially a condensed if/else statement in the form:
 *  Condition to check ? evaluate if true : evaluate if false
 *
 *  So the above printf statement
 *  means if (i >= 0) ? print i :else print -i. So therefore when i is 17, 17 is printed
 *  as 17 is greater than or equal to 0. If the value of i is -17 it prints 17 because -i = 17.
 */

    return 0;
}
