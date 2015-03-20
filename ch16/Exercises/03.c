#include <stdio.h>

struct complex {
    double real;
    double imaginary;
};

struct complex make_complex(double real, double imaginary)
{
    struct complex newcomplex;
    newcomplex.real = real;
    newcomplex.imaginary = imaginary;

    return newcomplex;
}

struct complex add_complex(struct complex s1, struct complex s2)
{
    struct complex newcomplex;
    newcomplex.real = s1.real + s2.real;
    newcomplex.imaginary = s1.imaginary + s2.imaginary;

    return newcomplex;
}

int main(void)
{
    struct complex c1, c2, c3;
}


