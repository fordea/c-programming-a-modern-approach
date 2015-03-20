#include <stdio.h>

int main(void)
{
    struct {
        double real;
        double imaginary;
    } c1 = {0.0, 1.0},
      c2 = {1.0, 0.0},
      c3;

    c1 = c2;

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    printf("Struct c1: real = %.1f, imaginary = %.1f\n", c1.real, c1.imaginary);
    printf("Struct c2: real = %.1f, imaginary = %.1f\n", c2.real, c2.imaginary);
    printf("Struct c3: real = %.1f, imaginary = %.1f\n", c3.real, c3.imaginary);
}
