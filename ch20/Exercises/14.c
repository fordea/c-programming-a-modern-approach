#include <stdio.h>
#include <string.h>
#include <math.h>

struct float_value {
    unsigned int fraction: 23; /* ordering using gcc */
    unsigned int exponent: 8;
    unsigned int sign: 1;
};

int main(void)
{
    struct float_value fv;

    fv.sign = 1;
    fv.exponent = pow(2, 8) - 1;
    fv.fraction = pow(2, 23) - 1;

    printf("%zu\n", sizeof(struct float_value));
    printf("%x\n", fv.sign);
    printf("%x\n", fv.exponent);
    printf("%x\n", fv.fraction);
}
