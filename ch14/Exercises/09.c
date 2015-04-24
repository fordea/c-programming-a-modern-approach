#include <stdio.h>

#define CHECK(x,y,n) (((x) >= 0 && (x) <= ((n)-1)) && ((y) >= 0 && (y) <= ((n)-1)))
#define MEDIAN(x,y,z) (((x) - (y)) * ((z) - (x)) >= 0 ? x : ((y) - (x)) * ((z) - (y)) >= 0 ? y : z)
#define POLYNOMIAL(x) ( (3 * ((x) * (x) * (x) * (x) * (x)))         \
                       +(2 * ((x) * (x) * (x) * (x)))               \
                       -(5 * ((x) * (x) * (x)))                     \
                       -((x) * (x)) + (7 * (x)) - 6 )

int main(void)
{
    int x, y, n;
    x = 5; y = 10, n = 11;

    printf("CHECK(%d,%d,%d) = %d\n", x, y, n, CHECK(x,y,n));
    printf("MEDIAN(%d,%d,%d) = %d\n", x, y, n, MEDIAN(x,y,n));
    printf("POLYNOMIAL(%d) = %d\n", x+1, POLYNOMIAL(x+1));
}
