#include <stdio.h>

int main(void)
{
    int m, n;
    m = 50;
    for (n = 0; m > 0; n++, m /= 2)
        /* empty loop body */ ;

    return 0;
}
