#include <stdio.h>

union {
    float value;
    struct float_value {
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    } m;
} f;

int main(void)
{
    f.m.sign = 1;
    f.m.exponent = 128;
    f.m.fraction = 0;

    printf("%.1f\n", f.value);
}
